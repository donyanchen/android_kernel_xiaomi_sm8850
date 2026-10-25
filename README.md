# 小米 17（pudding）自编译 GKI 内核

适配 **小米 17 / pudding / canoe / SM8850 / HyperOS OS4.0.5.0.XPCCNXM / Android 16**。

当前状态：**已实机开机验证**，669 个厂商内核模块全部正常加载，KernelSU root 可用。

---

## 一、功能

| 功能 | 状态 | 说明 |
|---|---|---|
| 厂商模块兼容 | ✅ | 669 个模块全部加载，相机 / WiFi / 音频 / 充电 / 触控正常 |
| KernelSU | ✅ | SukiSU Ultra，uapi 6，与设备现有 ksud 版本匹配 |
| KPM | ✅ | 内核内建 KPM 加载器，可运行时加载内核模块 |
| ADIOS IO 调度器 | ✅ | 附加 mq 调度器，可按设备切换 |
| LZ4KD 压缩 | ✅ | zram 额外压缩算法 |
| 版本串对齐 | ✅ | `/proc/version` 与原厂逐字一致 |
| SUSFS | ⚠️ 待验证 | 补丁已接入 CI，本次构建未确认生效 |
| 小米优化移植包 | ⏸ 未启用 | 16 个模块已适配，默认关闭 |

**内核标识**

```
uname -r   6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
vermagic   6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
```

---

## 二、这个内核解决了什么问题

小米 17 的厂商驱动是预编译的 `.ko` 模块（404 个），它们只认特定的内核 ABI。
自编译内核如果要让这些模块正常加载，必须同时满足三个条件：

1. **vermagic 完全一致** — 平台串必须精确等于 `6.12.69-android16-6-4k`
2. **导出符号齐全** — 模块引用的每个内核符号都必须在
3. **符号 CRC 一致** — 否则模块拒绝加载

本项目逐项处理了这三点：

**① vermagic**：固定 `CONFIG_LOCALVERSION="-android16-6-4k"`，关闭 `LOCALVERSION_AUTO`
**② 符号覆盖**：以设备 `/proc/config.gz` 的 2369 项配置为唯一基准，不做任何"补全"
**③ CRC**：见下节

---

## 三、符号 CRC 的处理

### 问题

设备内核开启了：

```
CONFIG_EXTENDED_MODVERSIONS=y
CONFIG_GENDWARFKSYMS=y
```

这两个选项让符号 CRC 由**编译产物的 DWARF 调试信息**计算，而不是源码声明。
换编译器、换编译参数、甚至换 clang 的小版本，CRC 全都会变。

实测：本内核与原厂的 4593 个真实 CRC 对比，只有 31.8% 一致。

### 处理

经 BTF 逐结构体比对，本内核与原厂的 **11124 个结构体中有 11109 个完全一致**（成员名、类型、偏移全部相同），
仅 15 个 f2fs 相关结构体有差异。也就是说 CRC 差异来自编译器指纹，不是真实 ABI 不兼容。

因此在 `kernel/module/version.c` 中把 `check_version()` 改为直接返回 1，
跳过 CRC 校验。签名校验（`MODULE_SIG_FORCE`）本来就没开启，不影响。

```c
int check_version(const struct load_info *info, const char *symname,
                  struct module *mod, const u32 *crc)
{
    return 1;
}
```

由 `scripts/patch_modversion.py` 在构建时自动应用。

---

## 四、遇到的坑

### 1. 缺 CONFIG_ASHMEM 导致开机卡死

**现象**：内核能引导，卡在开机动画，永不进入系统。`sys.boot_completed` 一直为空。

**日志**：

```
E ashmem : Unable to open ashmem device: No such file or directory
E Zygote : java.lang.RuntimeException: Failed to create ashmem: No such file or directory
E Zygote : System zygote died with fatal exception
FATAL EXCEPTION IN SYSTEM PROCESS: main
BootFailReport: summary ZYGOTE_FAIL
```

**根因链**：

```
CONFIG_ASHMEM 未启用
  → zygote 创建 ashmem 失败，直接 FATAL EXCEPTION
  → system_server 起不来
  → 卡开机动画
  → BootFailReport 计数超限
  → 所有 KSU 模块被系统自动禁用
```

**为什么 ASHMEM 没启用**：

```kconfig
config ASHMEM
	bool "Enable the Anonymous Shared Memory Subsystem"
	depends on SHMEM && RUST
```

ACK 6.12 的 ashmem 是用 Rust 重写的（`drivers/staging/android/ashmem.rs`），
所以依赖 `CONFIG_RUST`；而 `CONFIG_RUST` 需要 `scripts/rust_is_available.sh` 通过，其中要求 **bindgen**。

CI 里工具链缓存命中，bindgen 从未安装 → RUST 被 kconfig 静默丢弃 → ASHMEM 连带丢失。

**修复**：bindgen 单独一步安装，不依赖缓存；并在配置内核阶段就导出 `PATH / LIBCLANG_PATH / BINDGEN / RUSTC`。

### 2. 不要"补全"设备配置

早期为了让更多符号存在，额外开启了设备上关闭的选项：

```
CONFIG_CFG80211=m
CONFIG_MHI_BUS=y
CONFIG_SLIMBUS=y
CONFIG_SOUNDWIRE=y
CONFIG_CORESIGHT=y
```

后果：`struct net_device` 等结构体布局偏离原厂，CRC 一致率只有 31.8%。
清空这些额外配置后回到正轨。

**设备 `/proc/config.gz` 是唯一基准。**

### 3. `/proc/kallsyms` 里带方括号的符号不是内核导出的

```
ffffffe2b5293000 r __ksymtab_cfg80211_any_usable_channels  [cfg80211]
                                                            ↑ 模块名
```

带 `[模块名]` 后缀的符号是**模块自己导出**的，不属于内核本体。
统计"模块需要内核提供多少符号"时必须排除，否则数字会虚高一倍
（按内核本体导出算：2716 个；错误算法会得出 6150 个）。

---

## 五、构建

### 依赖（全部来自本仓库 Release）

```
ACK       android16-6.12-2026-03
clang     clang-r536225.tar.gz
rust      rust-1.82.0.tar.gz
bindgen   bindgen-0.69.5.tar.gz
KSU       SukiSU-Ultra
```

### CI 流程

```
1. 准备 ACK 源码
2. 准备工具链（clang / rust）
3. 确保 bindgen 就位            ← 不依赖缓存
4. 集成 SukiSU
5. 兼容性补丁
6. ADIOS / LZ4KD 补丁
7. 集成高通开源子系统（dataipa / synx / dsp / datarmnet / securemsm）
8. SUSFS 补丁（失败不阻塞）
9. 配置内核（设备真配置 + ABI 对齐）
10. 编译
11. ABI 硬门槛                  ← RUST / ASHMEM / ANDROID_BINDER_IPC_RUST 缺一即失败
12. 配置差异诊断
13. 上传产物
```

**第 11 步是防呆关键**：宁可构建失败，也不产出一个刷了开不了机的镜像。

---

## 六、刷写

```bash
# 打包（用原厂 boot 的前 4KB 作 header 模板）
python3 scripts/pack_boot.py <原厂boot前4KB> <Image> boot_pudding.img

# 刷入
su -c 'dd if=boot_pudding.img of=/dev/block/sde57 bs=4M conv=fsync'

# 回滚
su -c 'dd if=boot_original.img of=/dev/block/sde57 bs=4M conv=fsync'
# 或
fastboot flash boot_b boot_original.img
```

> boot header v4：`kernel_size` 在偏移 8，`ramdisk_size` 在偏移 12（本机型为 0），
> `header_size` 1584 在偏移 20，`header_version` 4 在偏移 40，内核数据从偏移 4096 开始。

---

## 七、工具

| 脚本 | 用途 |
|---|---|
| `scripts/pack_boot.py` | 打包 boot.img（header v4），支持往返校验 |
| `scripts/fake_version.py` | 编译期替换 `release=` 与 `LINUX_COMPILER` |
| `scripts/patch_image.py` | 离线对已编译 Image 做等长版本串替换 |
| `scripts/patch_modversion.py` | 跳过模块符号 CRC 校验 |
| `scripts/patch_kconfig.py` | 解除 `MODULE_SCMVERSION` 对 `LOCALVERSION_AUTO` 的依赖 |
| `scripts/config_diff.py` | 构建出的 `.config` 与设备配置全量 diff |
| `tools/extract_crc.py` | 从 `.ko` 的 `__version_ext_crcs` 提取真实符号 CRC |
| `tools/infer_params.py` | 反汇编推断外部符号的参数个数 |
| `tools/gen_stubs.py` | 生成 ABI 兼容桩函数 |
| `tools/cmp_structs.py` | BTF 结构体布局比对 |
| `tools/btf_sigs.py` | 从 BTF 提取函数签名 |

---

## 八、已知限制

- 仅适配 **SM8850 / canoe 平台的小米 17（pudding）**，其它机型需重新采集配置与 BTF
- CRC 校验被跳过，若后续真有结构体不兼容，表现为个别模块异常而非加载失败
- SUSFS 补丁尚未在实机验证
- 小米优化移植包（mi_rmap / unfairmem / unionpower 等）默认关闭，`scripts/apply_sew.sh` 中已禁用 4 个与 6.12 冲突的模块

---

## 九、免责

刷机会清空或破坏数据，请先完整备份 `boot_a` / `boot_b` / `init_boot`。
本项目按原样提供，不对变砖负责。
