# 小米 17（pudding）自编译 Android GKI 内核

### 📱 构建信息

- 内核版本号：`6.12.69_gki-android16-6-4k`
- 机型：小米 17 / pudding / SM8850
- 源码基线：AOSP `android16-6.12-2026-03`
- vermagic：`6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64`

### ⚙️ 内核特性

| 项目 | 状态 |
|---|---|
| 原厂模块兼容 | ✅ 404 个全部加载 |
| Root 方案 | ✅ FinaSU / SukiSU Ultra（内建） |
| SELinux 状态伪装 | ✅ |
| AVC 审计伪装 | ✅ |
| 挂载点隐藏 | ✅ |
| 版本串伪装 | ✅ |
| ADIOS IO 调度器 | ✅ |
| LZ4 / LZ4KD 压缩 | ✅ |
| BBR 拥塞控制 | ✅ |
| CAKE / FQ / HTB / TBF / SFQ 队列 | ✅ |
| IPSet + netfilter 扩展 | ✅ |
| TPROXY 透明代理 | ✅ |
| WireGuard | ✅ |
| DAMON 自适应回收 | ✅ |
| ZRAM ZSTD + 写回 | ✅ |
| ZSWAP | ✅ |
| KSM 内存去重 | ✅ |
| F2FS 压缩（LZ4/LZ4HC） | ✅ |
| EROFS LZMA 压缩 | ✅ |
| NTFS3 | ✅ |
| SUSFS | ❌ 不兼容当前 Root 方案 |
| KPM | ❌ 需额外内核补丁 |

### 📥 下载

| 文件 | 用途 |
|---|---|
| `boot_pudding_*.img.gz` | 配合 `flash.sh` 或 fastboot 刷入 |
| `AnyKernel3_*.zip` | 管理器 / Recovery 直刷 |
| `flash.sh` | 一键刷入脚本（自动判槽位、自动备份、失败回滚） |

### 📋 安装方法

1. **手机端一键刷（推荐）**：下载 `flash.sh` 和 `boot_pudding_*.img.gz` 到 `/sdcard/Download/kp/`，终端执行 `su` 后 `sh /sdcard/Download/kp/flash.sh`
2. **管理器直刷**：下载 AnyKernel3 zip，Root 管理器 → 模块 → 从本地安装
3. **KernelFlasher**：安装 [KernelFlasher](https://github.com/capntrips/KernelFlasher/releases)，选当前槽位 → 先备份 → 刷入解压后的 `.img`
4. **fastboot**：`fastboot getvar current-slot` 确认槽位后 `fastboot flash boot_b xxx.img`

⚠️ **不要用 `fastboot flash:raw`**，会丢掉 kernel_dtb，导致无法开机。

⚠️ **刷入前务必用 KernelFlasher 等工具备份 boot 分区。**

### 🔙 回滚

```bash
# 系统还能起
dd if=你的备份.img of=/dev/block/by-name/boot_b bs=4096

# 起不来：长按 音量下 + 电源 进 fastboot
fastboot flash boot_b 备份.img
```

### ✅ 验证

```bash
uname -r
# 期望 6.12.69-android16-6-4k

su -c "od -An -tx4 /sys/fs/selinux/status"
# 期望 policyload（第 4 段）为 00000000
```

### 📱 支持范围

| 项 | 值 |
|---|---|
| 机型 | 小米 17，代号 pudding / canoe |
| 平台 | SM8850 |
| 内核 KMI | `android16-6-4k` |
| 分区 | A/B，boot_a = sde14，boot_b = sde57 |

**其他机型不要刷。** 判断方法：

```bash
getprop ro.product.device     # 必须是 pudding 或 canoe
uname -r                      # 必须是 6.12.69-android16-6-4k
```

> `android16` 是 GKI 的 KMI 世代标识，不是系统版本。Android 17 系统配 `android16-6-4k` 内核是正常组合。

### 🔨 从源码构建

```
Actions → Build Kernel → Run workflow
  ack_branch   android16-6.12-2026-03
  features     true
  sew_opt      false
```

约 20 分钟，产物为 `Image-6.12.69`。
