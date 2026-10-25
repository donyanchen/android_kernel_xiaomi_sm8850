# 小米 17（pudding）自编译 Android GKI 内核

在小米 17（pudding / canoe / SM8850）上自编译 Android GKI 内核，使之能加载原厂 404 个厂商模块并正常开机。

当前状态：**可开机、可 Root、厂商模块全部加载**。

```
内核版本    6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k（显示串对齐原厂）
vermagic    6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
实测结果    sys.boot_completed=1，lsmod 669 个模块，KSU root 正常
```

---

## 1. 适用范围

| 项目 | 值 |
|---|---|
| 机型 | 小米 17，代号 pudding |
| 平台 | SM8850 / canoe |
| 系统 | HyperOS OS4.0.5.0.XPCCNXM（Android 16） |
| 分区 | A/B，本文所有操作针对 `_b` |
| boot 分区 | `/dev/block/sde57`，header v4，`ramdisk_size=0`，内核偏移 4096 |
| 源码基线 | ACK `android16-6.12-2026-03`（SUBLEVEL 69） |

**不适用于**：其他机型、非 A/B 设备、内核 sublevel 不同的固件。换机型时 ABI 依据全部作废，需重新采集。

本仓库只产出**内核镜像**，不含用户态。KSU 的内核侧驱动编进内核，用户态由 `init_boot` 提供。

---

## 2. 快速开始

### 2.1 构建

仓库使用 GitHub Actions，手动触发：

```
workflow: build.yml
参数:
  ack_branch = android16-6.12-2026-03
  kpm        = true
  features   = true
  sew_opt    = false
```

产物 `Image-6.12.69`：`Image` + `vmlinux.symvers` + `.config`。

配置组装顺序：

```
configs/pudding_full.defconfig   设备 /proc/config.gz 全量（6508 条，其中 2370 项启用，唯一基准）
  + configs/pudding_abi.fragment 仅 4 项有效覆盖（KSU/KPM/LOCALVERSION/AUTO=n）
  + configs/abi_symbollist.raw   TRIM_UNUSED_KSYMS 白名单（14734 项）
```

### 2.2 打包 boot.img

```bash
python3 pack_boot.py <原厂boot前4KB> <Image> <输出>
# 例：python3 pack_boot.py bootb_hdr.bin Image boot_pudding.img
```

`pack_boot.py` 只改两个字段，其余原样保留：

```python
struct.pack_into('<I', hdr, 8,  len(Image))   # kernel_size
struct.pack_into('<I', hdr, 12, 0)            # ramdisk_size
out = hdr(4096) + Image + 补齐到 4096 对齐
```

打包工具做过往返验证：用原厂内核重新打包，输出与原厂 `boot_b` 前段 md5 完全一致。

### 2.3 刷写

```bash
# 备份（务必先做）
su -c 'dd if=/dev/block/sde57 of=/sdcard/Download/kp/boot_original.img bs=4M'

# 刷入
su -c 'dd if=/sdcard/Download/kp/boot_pudding_60.img of=/dev/block/sde57 bs=4M conv=fsync'
su -c 'sync'

# 回读校验
su -c 'dd if=/dev/block/sde57 bs=4096 count=<镜像页数> | md5sum'
```

### 2.4 回滚

```bash
# 系统还能起来
su -c 'dd if=/sdcard/Download/kp/boot_original.img of=/dev/block/sde57 bs=4M'

# 起不来：音量下 + 电源 进 fastboot
fastboot flash boot_b boot_original.img
```

### 2.5 首次开机

换内核后首次启动要重建 dex2oat 与模块初始化，**90～300 秒属正常**。判断依据不是屏幕，而是：

```bash
adb shell getprop sys.boot_completed    # 变成 1 即已启动完成
```

---

## 3. 技术原理

### 3.1 ABI 策略：设备配置是唯一基准

厂商模块在加载时比对两件事：`vermagic` 字符串，以及每个符号的 CRC。

因此配置必须与设备**完全一致**，不能"补全"。

本项目早期版本为了方便，在设备设为 `n` 的情况下额外打开了 `CFG80211`、`MAC80211`、`MHI_BUS`、`SLIMBUS`、`SOUNDWIRE`、`CORESIGHT` 等选项。结果是：

```
与设备 4593 个真实 CRC 对比  一致率 31.8%
module_layout               0xbc47a22e ≠ 0x797f2b3e
```

`CONFIG_CFG80211` 会给 `struct net_device` 增加 `ieee80211_ptr`、`wiphy` 等字段，所有涉及 `net_device` 的函数 CRC 全部改变。清空这些额外项后差异项从 134 项降到 13 项。

**结论：多开任何一项 CONFIG，都可能改变结构体布局。**

### 3.2 为什么 CRC 无法精确对齐

设备开启了这两个选项：

```
CONFIG_EXTENDED_MODVERSIONS=y
CONFIG_GENDWARFKSYMS=y
```

在此模式下，符号 CRC 不是由 `genksyms` 从源码声明计算，而是由 `gendwarfksyms` 从**编译产物的 DWARF 调试信息**计算。也就是说 CRC 直接绑定编译器输出。

实测证据：

```
memset / strlen / snprintf / sscanf / strncmp   基本类型函数 → CRC 一致
__alloc_skb / __amba_driver_register / ...      涉及结构体   → CRC 不符
struct module                                   1600 字节 / 75 成员，与设备逐个成员一致
全量结构体                                       11109 / 11124 一致，仅 15 个 f2fs 相关不同
```

结构体一致而 CRC 不同，说明差异来自编译器指纹而非真实 ABI 不兼容。

### 3.3 跳过 CRC 校验

`kernel/module/version.c` 中 `check_version()` 在 CRC 不符时返回 0 拒绝加载。本项目将其整体替换为直接返回 1：

```c
int check_version(const struct load_info *info, const char *symname,
                  struct module *mod, const u32 *crc)
{
	/* PUDDING: skip crc check */
	(void)info; (void)symname; (void)mod; (void)crc;
	return 1;
}
```

`check_modstruct_version()` 内部同样调用它，一并生效。

**依据**：11109/11124 个结构体经 BTF 实测一致，CRC 差异属编译器指纹。这是有风险的取舍，不是"已验证安全"——见第 5 节。

### 3.4 版本串伪装

`/proc/version` 与原厂需要一致：

```
Linux version 6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
(kleaf@build-host)
(Android (14043575, +pgo, +bolt, +lto, +mlgo, based on r536225) clang version 19.0.1 (...), LLD 19.0.1)
#1 SMP PREEMPT Tue Sep  8 15:08:49 UTC 2026
```

实现方式：`scripts/fake_version.py` 修改 `init/version-timestamp.c`

```
release = "<原厂串>"           替换 release= UTS_RELEASE
LINUX_COMPILER                 替换为原厂编译器字面量
```

配合 CI 环境变量：

```
KBUILD_BUILD_USER=kleaf
KBUILD_BUILD_HOST=build-host
KBUILD_BUILD_TIMESTAMP="Tue Sep  8 15:08:49 UTC 2026"   ← 必须是 date 默认格式
```

时间戳写成 ISO 格式会导致 `uname -v` 与原厂不同。

另有离线方案 `scripts/patch_image.py`：版本串 52 字节、编译器构建号 8 位数字，均可对已编译 Image 做**等长二进制替换**，无需重编。

---

## 4. 踩坑记录

### 4.1 最贵的一次：卡开机动画，根因是 ASHMEM

现象：内核成功启动（能出开机动画），但系统起不来；无内核 panic，`pstore` 为空。

完整根因链：

```
缺 CONFIG_ASHMEM
  → zygote: RuntimeException: Failed to create ashmem
  → FATAL EXCEPTION IN SYSTEM PROCESS
  → 卡在开机动画（内核不崩，所以查不到 panic）
  → 重启次数累积 → BootFailReport 计数超限
  → 系统自动禁用所有 KSU 模块
```

而 ASHMEM 在 ACK 6.12 中依赖 Rust：

```
CONFIG_RUST  →  ashmem.rs  →  CONFIG_ASHMEM
RUST_IS_AVAILABLE 需要 rustc + bindgen
```

CI 里工具链缓存命中，`scripts/rust_is_available.sh` 检测到 `bindgen` 不存在，`RUST_IS_AVAILABLE=n`，kconfig 静默丢弃 `CONFIG_RUST`，`CONFIG_ASHMEM` 连带丢失。

**教训**：

1. 缓存命中的步骤不等于依赖装好了 —— bindgen 必须放在独立步骤、不参与缓存
2. kconfig 丢弃依赖不满足的选项时**不报错**，只看 `defconfig` 里的 `=y` 是无效的
3. 卡开机动画且无 panic 时，先怀疑 zygote / system_server，而不是内核

修复后的硬门槛（缺一即构建失败）：

```
CONFIG_RUST=y
CONFIG_ASHMEM=y
CONFIG_ANDROID_BINDER_IPC_RUST=m
```

### 4.2 `/proc/kallsyms` 里带方括号的是模块导出

```
ffffffe2 b5293000 r __ksymtab_cfg80211_any_usable_channels  [cfg80211]
                                                            ↑ 模块名
```

早期把这类条目也算成"内核导出"，导致需要的符号数从 2716 被高估到 6150，进而生成了一大批本不该存在的桩函数，连锁出现 `duplicate symbol`、`conflicting types`、`void 函数 return 值` 等一堆编译错误。

正确统计：

```
内核本体导出 9933   模块导出 4801
404 个模块真正需要内核提供 2716   由其它模块提供 3434
```

同理，`EXPORT_SYMBOL` 扫描必须覆盖全部变体，否则会误判：

```
EXPORT_SYMBOL_NS_GPL(...)        ← 漏掉这个，dma_buf_* 全被当成缺失
EXPORT_TRACEPOINT_SYMBOL_GPL(..) ← 漏掉这个，上百个 __traceiter_* 被当成缺失
```

### 4.3 不要设 `persist.adb.tcp.port`

为调试方便设了 `persist.adb.tcp.port=5555`，结果 adbd 进入纯网络模式，系统把 adb 功能从 USB 组合中剔除：

```
sys.usb.config        adb,mtp        （属性看起来正常）
实际组合              仅 MTP          （adb 被剔除）
```

表现为插电脑、插 OTG 手机都只能充电或识别为 MTP，**无 USB 调试弹窗，且重启不恢复**（属性是持久的）。

清掉之后还需要重新触发一次组合计算：

```bash
settings put global adb_enabled 0
settings put global adb_enabled 1
```

### 4.4 手机直连手机做 USB 调试

OTG 必须插在**主机那一侧**。两边都当 device 时只有充电：

```
dwc3 state        not attached
TypeC data_role   device
TypeC power_role  sink
```

### 4.5 GitHub Actions 的 YAML heredoc

`run: |` 块标量里所有行必须缩进。写入内联 heredoc 内容顶格会导致**整个 workflow 失效**，表现为 push 事件 `jobs=0`、运行名显示为文件路径。

改用仓库文件 + `cat` 引用，不要在 YAML 里写 heredoc。

### 4.6 `CONFIG_MODULE_SIG_PROTECT` 需要额外文件

```
make[2]: *** No rule to make target 'protected_module_names_list',
              needed by 'Module.symvers'
```

`CONFIG_MODULE_SIG_PROTECT=y` 时内核树根必须有 `CONFIG_MODULE_SIG_PROTECT_LIST` 指定的文件（设备值为 `protected_module_names_list`）。

---

## 5. 已知限制与待办

### 已知限制

| 项目 | 说明 |
|---|---|
| CRC 校验被跳过 | 不是"通过"，是关掉。若有未发现的结构体差异，模块可能运行异常而非加载失败 |
| 编译器构建号未对齐 | `CONFIG_CC_VERSION_TEXT` 仍为 `Android (12833971, ...)`，原厂是 `14043575`。会出现在 `/proc/version` 里 |
| 无 Rust 符号 | 设备导出 3655 个 Rust 符号，本内核没有。实测厂商模块不依赖它们 |
| 版本升级受限 | 改 sublevel 会改变 vermagic，且需再打 vermagic 补丁 |
| 未做长时间稳定性验证 | 仅确认能开机、模块加载、Root 可用 |

### 待办

```
[ ] SUSFS 确认生效（补丁已加，需验证 /sys/kernel/mm/susfs 存在）
[ ] BORE 调度器评估
[ ] 小米优化移植包（sew_opt）在 6.12 上的可行性
[ ] 相机 / 音频 / WiFi / 充电 / 指纹 逐项功能实测
[ ] 补齐 bindgen，恢复 CONFIG_RUST
```

---

## 6. 工具

| 脚本 | 用途 |
|---|---|
| `scripts/pack_boot.py` | 打 boot.img（header v4，ramdisk_size=0） |
| `scripts/fake_version.py` | 编译期版本串伪装 |
| `scripts/patch_image.py` | 离线镜像版本串补丁（等长替换，免重编） |
| `scripts/patch_modversion.py` | 跳过 `check_version` CRC 校验 |
| `scripts/patch_kconfig.py` | 解除 `MODULE_SCMVERSION` 对 `LOCALVERSION_AUTO` 的依赖 |
| `scripts/config_diff.py` | 构建出的 `.config` 与设备配置全量 diff |
| `tools/extract_crc.py` | 从 `.ko` 提取真实符号 CRC |
| `tools/infer_params.py` | 反汇编推断外部符号参数个数 |
| `tools/gen_stubs.py` | 生成 ABI 桩函数 |
| `tools/cmp_structs.py` | BTF / 头文件结构体比对 |
| `tools/btf_sigs.py` | 从 BTF 提取函数签名 |

---

## 7. 免责声明

刷写自编译内核会使设备**无法开机**，需要 fastboot 或 `dd` 回滚。

- 操作前必须备份 `boot` 分区，且确认备份与当前分区内容一致
- 必须确认能用 fastboot（`音量下 + 电源`）恢复
- 跳过 CRC 校验意味着放弃了内核的一道安全检查，异常可能表现为运行时崩溃而非加载失败
- 本项目仅在一台设备、一个固件版本上验证，不保证其他环境可用
- 因使用本项目造成的任何设备损坏、数据丢失，作者不承担责任

内核源码来自 Android Common Kernel（GPL-2.0）；本仓库的脚本与补丁同属 GPL-2.0。
