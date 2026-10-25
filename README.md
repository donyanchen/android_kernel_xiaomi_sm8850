# 小米 17（pudding）自编译 Android GKI 内核

```
内核版本    6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
vermagic    6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
```

支持机型：**小米 17（pudding / canoe，SM8850）**，系统 Android 16 / 17 均可。

---

## 特性

### 兼容性
- **原厂模块全兼容**：404 个厂商模块全部加载，相机 / WiFi / 指纹 / 音频 / 100W 快充 / 触控全部正常
- **版本串对齐**：`/proc/version` 与原厂逐字一致，`uname -r` 无法分辨
- **KMI 稳定**：`android16-6-4k`，符合 GKI 约定

### Root 方案
- **FinaSU / SukiSU Ultra** 可选，内核内建（非 LKM 模块）
- 无需额外刷模块，刷完即用

### 环境隐藏
- **SELinux 状态伪装**：修正状态页返回值，避免出现原版内核不可能产生的数值
- **AVC 审计伪装**：拒绝日志中的上下文不会泄露
- **挂载隐藏**：模块挂载点对普通应用不可见
- **版本串伪装**：`utsname` 输出与原厂一致

### 性能与调优
- **ADIOS IO 调度器**：附加 mq 调度器，可按场景切换
- **LZ4KD 压缩**：zram 额外压缩算法，内存更省
- 附带常规内核性能与网络调优

### 不提供
- SUSFS（与当前 Root 方案的 hook 模型不兼容）
- KPM（需要额外内核补丁，本内核不适用）

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
