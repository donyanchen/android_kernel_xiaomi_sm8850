# Pudding Kernel — 小米 17 自编译内核

> 设备：小米 17（pudding / canoe / SM8850），HyperOS OS4.0.5.0.XPCCNXM
> 状态：**已成功开机，厂商模块全部加载**

---

## 一、成果

```
内核        6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
            （显示串与原厂逐字一致）
vermagic    6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
sys.boot_completed   1
/dev/ashmem          存在
lsmod                669 个（camera / cnss2 / mca_* / adsp 共 51 个关键模块）
root                 uid=0  context=u:r:ksu:s0
```

产物：`boot_pudding_60.img`（41,451,520 字节，header v4，ramdisk 0）

---

## 二、失败根因链（核心教训）

```
缺 CONFIG_ASHMEM
  → zygote 创建 ashmem 失败：java.lang.RuntimeException: Failed to create ashmem
  → FATAL EXCEPTION IN SYSTEM PROCESS
  → system_server 起不来 → 卡开机动画
  → BootFailReport 计数超限 → 自动禁用所有 KSU 模块
```

而 `CONFIG_ASHMEM` 在 ACK 6.12 里的定义是：

```kconfig
config ASHMEM
	bool "Enable the Anonymous Shared Memory Subsystem"
	depends on SHMEM && RUST        ← 关键
```

**ASHMEM 在 6.12 是用 Rust 重写的**（`drivers/staging/android/ashmem.rs`），所以必须启用 RUST；
而 `CONFIG_RUST` 需要 `scripts/rust_is_available.sh` 通过，其中要求 **bindgen**。

工具链缓存命中导致 bindgen 从未安装 → RUST 被丢弃 → ASHMEM 跟着丢。

---

## 三、ABI 策略

### 3.1 事实

```
设备内核本体导出符号    9,933
厂商模块导出符号        4,801
404 个模块真正依赖      6,150（其中需内核提供 2,716）
```

### 3.2 CRC 无法对齐的原因

```
CONFIG_EXTENDED_MODVERSIONS=y
CONFIG_GENDWARFKSYMS=y
```

这两个选项让符号 CRC 由**编译产物的 DWARF** 计算，对编译器极其敏感。
我们的 clang 构建号（12833971）与原厂（14043575）不同 → CRC 必然不同。

### 3.3 采用的方案

**跳过 CRC 校验**：`scripts/patch_modversion.py` 把 `kernel/module/version.c` 的
`check_version()` 整体替换为 `return 1`。

依据：BTF 实测本内核与原厂的 **11,109 / 11,124 个结构体完全一致**，
CRC 差异属于编译器指纹，不是真实 ABI 不兼容。

### 3.4 配置原则

**设备 `/proc/config.gz` 是唯一基准，绝不多开。**

早期曾「补全」设备没有的 CONFIG（CFG80211 / MHI_BUS / SLIMBUS / CORESIGHT 等），
导致 `struct net_device` 等布局偏离原厂，CRC 一致率只有 31.8%。
清空额外配置后回到正确轨道。

---

## 四、版本串伪装

`/proc/version` 需要与原厂逐字一致：

```
Linux version 6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
(kleaf@build-host)
(Android (14043575, +pgo, +bolt, +lto, +mlgo, based on r536225) clang version 19.0.1 (...), LLD 19.0.1)
# SMP PREEMPT Tue Sep  8 15:08:49 UTC 2026
```

| 段 | 来源 | 方式 |
|---|---|---|
| 版本串 | `init/version-timestamp.c` 的 `release=` | `scripts/fake_version.py` |
| 编译器号 | `LINUX_COMPILER` 宏 | 同上，替换为字面量 |
| 时间戳 | `KBUILD_BUILD_TIMESTAMP` | 设为 `Tue Sep  8 15:08:49 UTC 2026` |

也支持离线补丁：`scripts/patch_image.py`（等长二进制替换）。

---

## 五、CI 流程

```
1. 准备 ACK 源码（android16-6.12-2026-03）
2. 准备工具链（clang-r536225 / rust-1.82.0）
3. 确保 bindgen 就位（不依赖缓存 ← 关键）
4. 集成 SukiSU
5. 兼容性补丁
6. 应用 ADIOS / LZ4KD 补丁
7. 集成高通开源子系统（sparse-checkout）
8. 应用 SUSFS 补丁（失败不阻塞）
9. 配置内核（设备真配置 + ABI 对齐 + SUSFS 配置）
10. 编译（pahole 生成 BTF）
11. ABI 硬门槛 ← RUST / ASHMEM / ANDROID_BINDER_IPC_RUST 缺一即失败
12. 配置差异诊断
13. 上传产物（Image + vmlinux.symvers + .config）
```

**第 11 步是防呆关键**：宁可构建失败，也不产出刷了会变砖的镜像。

---

## 六、刷写

```bash
# 打包（原厂 header + 新内核）
python3 scripts/pack_boot.py <原厂boot前4KB> <Image> <输出>

# 刷入
su -c 'dd if=boot_pudding_60.img of=/dev/block/sde57 bs=4M conv=fsync'

# 回滚
su -c 'dd if=boot_original.img of=/dev/block/sde57 bs=4M'
# 或 fastboot
fastboot flash boot_b boot_original.img
```

---

## 七、工具

| 脚本 | 用途 |
|---|---|
| `scripts/pack_boot.py` | 打包 boot.img（header v4） |
| `scripts/fake_version.py` | 编译期版本串伪装 |
| `scripts/patch_image.py` | 离线镜像版本串补丁 |
| `scripts/patch_modversion.py` | 跳过模块 CRC 校验 |
| `scripts/patch_kconfig.py` | 解除 MODULE_SCMVERSION 依赖 |
| `scripts/config_diff.py` | 构建配置与设备配置全量 diff |
| `tools/extract_crc.py` | 从 .ko 提取真实符号 CRC |
| `tools/infer_params.py` | 反汇编推断外部符号参数 |
| `tools/gen_stubs.py` | 生成 ABI 桩函数 |
| `tools/cmp_structs.py` | BTF 结构体布局比对 |
| `tools/btf_sigs.py` | BTF 函数签名提取 |

---

## 八、辅助：用另一台手机通过 OTG 调试

当目标机卡开机时，可用安卓手机作 adb/fastboot 宿主：

1. 取 Termux 的 `android-tools`（musl 版），连同 53 个依赖库打包
2. 改写 `adb` / `fastboot` 的 ELF `PT_INTERP` 为 `/data/local/tmp/a/ld.so`
3. 通过 localhost HTTP 从宿主沙箱传输（`curl http://127.0.0.1:8766/xxx`）
4. 直接运行即可；`/proc/self/exe` 指向真实路径，adb server 能正常重启

---

## 九、待办

- [ ] SUSFS 补丁验证（CI 步骤已加）
- [ ] BORE 调度器
- [ ] IO / VM / TCP 运行时可调优
- [ ] 小米优化移植包（16 个兼容模块，`scripts/apply_sew.sh`）
