# 小米 17（pudding）自编译 Android GKI 内核

```
内核版本    6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
vermagic    6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
```

支持机型：**小米 17（pudding / canoe，SM8850）**，系统 Android 16 / 17 均可。

---

## 特性

- **原厂模块全兼容**，日常功能正常
- **Root 内建**：FinaSU / SukiSU Ultra 可选，无需额外刷模块
- **环境隐藏**：SELinux 状态 / AVC 审计 / 挂载点 / 版本串
- **IO 与内存**：ADIOS 调度器、LZ4KD 压缩
- **不含**：SUSFS、KPM

---

## 下载

到 [Releases](../../releases) 页下载：

| 文件 | 用途 |
|---|---|
| `boot_pudding_*.img.gz` | 配合 `flash.sh` 或 fastboot 刷入 |
| `AnyKernel3_*.zip` | 管理器 / Recovery 直刷 |
| `flash.sh` | 一键刷入脚本（自动检测槽位、自动备份、失败回滚） |

---

## 刷入

**方式一：手机端一键刷（推荐）**

```bash
su
sh /sdcard/Download/kp/flash.sh
```

**方式二：fastboot**

```bash
fastboot getvar current-slot          # 先确认是 a 还是 b
fastboot flash boot_b xxx.img         # 按实际槽位替换
fastboot reboot
```

> ⚠️ 不要用 `fastboot flash:raw`，会丢掉 kernel_dtb，无法开机。

**方式三：管理器直刷**

下载 AnyKernel3 zip，在 Root 管理器里「从本地安装」。

---

## 回滚

```bash
# 系统还能起来
dd if=你的备份.img of=/dev/block/by-name/boot_b bs=4096

# 起不来：长按 音量下 + 电源 进 fastboot
fastboot flash boot_b 备份.img
```

**刷之前务必先备份。**

---

## 验证

```bash
uname -r
# 期望 6.12.69-android16-6-4k

su -c "od -An -tx4 /sys/fs/selinux/status"
# 期望 policyload（第 4 段）为 00000000
```

---

## 支持范围

| 项 | 值 |
|---|---|
| 机型 | 小米 17，代号 pudding |
| 平台 | SM8850 / canoe |
| 内核 KMI | `android16-6-4k` |
| 分区 | A/B，boot_a = sde14，boot_b = sde57 |

**其他机型不要刷。** 判断方法：

```bash
getprop ro.product.device     # 必须是 pudding 或 canoe
uname -r                      # 必须是 6.12.69-android16-6-4k
```

> `android16` 是 GKI 的 KMI 世代标识，不是系统版本。Android 17 系统配 `android16-6-4k` 内核是正常组合。

---

## 从源码构建

```
Actions → Build Kernel → Run workflow
  ack_branch   android16-6.12-2026-03
  features     true
  sew_opt      false
```

约 20 分钟，产物为 `Image-6.12.69`。
