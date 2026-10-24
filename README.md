# Pudding Kernel — Xiaomi 17 (pudding / SM8850) GKI 6.12

自建内核构建流水线。全部在 GitHub Actions 完成。

## 目标

| 项 | 值 |
|---|---|
| 机型 | Xiaomi 17 `pudding`，SM8850 / `canoe`，HyperOS 4.0.5.0 (Android 17) |
| 内核基线 | Android Common Kernel `android16-6.12` |
| KMI | `android16-6.12` |
| Root | SukiSU Ultra，**内建**（`CONFIG_KSU=y`） |
| KPM | **内建**（`CONFIG_KPM=y`） |
| SUSFS | 内建 |
| 输出 | `Image` + AnyKernel3 zip |

## 关键技术约束（实测得出）

### 1. vermagic 必须精确匹配

手机上 404 个 vendor 模块的 vermagic 是：

```
6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
```

内核的 `VERMAGIC_STRING` 由 `UTS_RELEASE` 拼接而成（`include/linux/vermagic.h`），
所以 **UTS_RELEASE 必须等于 `6.12.69-android16-6-4k`**，否则所有模块被拒载。

显示用的长串（`6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k`）可以通过补丁
单独伪造 `init/version.c` 与 `init/utsname.c`，不影响 vermagic。

### 2. KPM 只有内建模式可用

`kernel/extension/kpm.c` 使用 `#ifdef CONFIG_KPM` 宏判断，外部模块编译（LKM）时
内核头里没有该宏，`ksu_extension_kpm_io` 直接返回 `-EOPNOTSUPP`。
即使把 KPM 目标文件强行链接进 `kernelsu.ko`，宏判定仍走 `#else`。

### 3. SukiSU 的 uapi 头文件需要手动拷贝

`setup.sh` 只把 `kernel/` 拷进 `drivers/kernelsu/`，仓库根的 `uapi/*.h` 需要额外复制到
`common/drivers/kernelsu/uapi/`，否则 `uapi/extension.h`、`uapi/app_profile.h` 找不到。

### 4. super_access.c 与 6.12 不兼容

`DEFINE_MEMBER(netlink_kernel_cfg, cb_mutex)` 在 6.9+ 已被移除，需要加版本保护。

## 原厂内核审计结论

在真机上导出 `/proc/config.gz`、`/proc/kallsyms` 后统计：

```
mi_ 符号        707 个 → 内建 7 个，其余 700 个在 /vendor/lib/modules
xiaomi_ 符号    147 个 → 全部在模块
qcom_ 符号     1388 个 → 内建 122 个（多为通用平台驱动）
已加载模块      670 个
vendor 模块目录 404 个 .ko
```

小米在内核本体的定制仅 4 个配置：

```
CONFIG_MI_SCHED_EXT=y
CONFIG_MI_SCX_PERFETTO_TRACK=y
CONFIG_XIAOMI_ALLOC_STACK_PAGE=y
CONFIG_XIAOMI_VMAP_ALLOC_PAGE=y
```

其中 `MI_SCHED_EXT` 对应 7 个内建符号，**没有任何 vendor 模块引用**。

真机运行时状态：

```
/sys/kernel/sched_ext/state = disabled
switch_all = 0
nr_rejected = 0
```

即小米的 sched_ext 扩展实际未启用，丢失不影响运行。

## 小米开源情况

`MiCode/Xiaomi_Kernel_OpenSource` 共 267 个分支，无 `pudding`。
`popsicle-w-oss` 分支含 `build.config.msm.pudding`、`configs/pudding_*.bzl` 与 1471 个
driver 文件，但 Makefile 版本为 `6.11.0`，且不含 `MI_SCHED_EXT` 实现，属增量包而非
完整 6.12 源码树。

## 构建

Actions → `Build Kernel` → Run workflow。

## 刷入与回滚

```bash
# 备份
dd if=/dev/block/by-name/boot_b of=/sdcard/boot_backup.img bs=1M
# 回滚
dd if=/sdcard/boot_backup.img of=/dev/block/by-name/boot_b bs=1M
```

## 已知风险

- 编译产物与官方内核**不同源**，无法做到逐字节一致
- 丢失 `MI_SCHED_EXT`（实测设备上未启用）
- 首次构建 30–50 分钟
