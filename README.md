# Pudding Kernel

[![Build](https://github.com/donyanchen/pudding-kernel/actions/workflows/build.yml/badge.svg)](https://github.com/donyanchen/pudding-kernel/actions/workflows/build.yml)
[![Kernel](https://img.shields.io/badge/kernel-6.12.69-blue)]()
[![KMI](https://img.shields.io/badge/KMI-android16--6.12-green)]()
[![License](https://img.shields.io/badge/license-GPL--2.0-orange)]()

Xiaomi 17 (`pudding` / SM8850 `canoe`) 的 GKI 6.12 定制内核。
基于 **Google 官方 Android Common Kernel**，内建 SukiSU + KPM + SUSFS，构建全流程在 GitHub Actions 完成。

---

## 特性

| 类别 | 内容 |
|---|---|
| **Root** | SukiSU Ultra（内建 `CONFIG_KSU=y`，非 LKM） |
| **KPM** | 内建 `CONFIG_KPM=y` — 支持 `.kpm` 内核补丁模块运行时加载 |
| **隐藏** | SUSFS 2.3.0、`avc_spoof`、`selinux_hide` |
| **调度** | `SCHED_CLASS_EXT`（sched_ext + `android_vh_scx_*` vendor hooks） |
| **内存** | MGLRU 多代 LRU、ZSWAP、ZRAM writeback |
| **IO** | Kyber 调度器 |
| **网络** | TCP BBR、WireGuard、ipset/iptables 扩展 |
| **文件系统** | F2FS 压缩、EROFS |
| **调试** | `KALLSYMS_ALL`（KPM 必需） |

## 版本策略

```
内核版本      6.12.69
KMI          android16-6.12
vermagic     6.12.69-android16-6-4k          ← 必须与 vendor 模块一致
显示版本      6.12.69-android16-6-g<commit>-abogki<n>-4k
```

> **vermagic 是硬约束。** 设备上 404 个 vendor 模块的 vermagic 写死为
> `6.12.69-android16-6-4k`，内核的 `VERMAGIC_STRING` 不一致会导致全部模块拒绝加载
> （无显示、无触控、无存储驱动）。
>
> 显示版本通过补丁单独伪造（`init/version-timestamp.c`），每次构建附带当前 commit
> 与构建序号，跟随官方命名风格，且不参与模块校验。

## 构建

### GitHub Actions（推荐）

`Actions → Build Kernel → Run workflow`

| 输入 | 说明 | 默认 |
|---|---|---|
| `ack_branch` | ACK 源码分支 | `android16-6.12-2026-03` |
| `kpm` | 内建 KPM | `true` |
| `features` | 额外特性配置 | `true` |

产物：`Image`（内核镜像）+ `build.log`（构建日志）。

### 本地构建

```bash
./scripts/build.sh
```

需要：Linux x86_64、约 40 GB 磁盘、clang r536225（脚本自动下载）。

## 刷入

```bash
# 1. 备份当前 boot
adb shell su -c 'dd if=/dev/block/by-name/boot_b of=/sdcard/boot_backup.img bs=1M'

# 2. 替换内核
./scripts/flash.sh Image

# 3. 重启
adb reboot
```

或使用 KernelSU 管理器 / TWRP 刷入 AnyKernel3 zip。

## 回滚

```bash
adb shell su -c 'dd if=/sdcard/boot_backup.img of=/dev/block/by-name/boot_b bs=1M'
adb reboot
```

## 目录结构

```
├── .github/workflows/
│   └── build.yml            构建流水线
├── configs/
│   └── pudding.fragment     内核配置片段（所有 CONFIG 追加项）
├── patches/
│   └── fix_ksu_612.py       SukiSU 在 6.12 上的兼容性修正
├── manifest/
│   └── source.json          源码与工具链版本锁定
├── scripts/
│   ├── build.sh             本地构建入口
│   └── flash.sh             刷入脚本
└── docs/
    ├── compatibility.md     模块兼容性说明
    └── troubleshooting.md   常见问题
```

## 已知限制

- 编译产物与官方内核**不同源**。官方内核由小米基于私有源码构建，源码未公开；
  本项目使用 Google 官方 ACK + 官方工具链，无法做到逐字节一致。
- 内核本体中不含小米私有的 `MI_SCHED_EXT`。该扩展在真机上处于 `disabled` 状态
  （`/sys/kernel/sched_ext/state`），且无 vendor 模块引用其符号；本项目通过启用
  sched_ext 子系统与 `android_vh_scx_*` vendor hooks 提供等价能力。
- 首次构建约 25–40 分钟，启用 ccache 后约 5–8 分钟。

## 许可

GPL-2.0。内核源码来自 [Android Common Kernel](https://android.googlesource.com/kernel/common)，
SukiSU 来自 [SukiSU-Ultra](https://github.com/SukiSU-Ultra/SukiSU-Ultra)。
