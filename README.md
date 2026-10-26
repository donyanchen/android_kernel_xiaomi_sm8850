# 小米 17 系列 / Redmi K90 Pro Max 自编译 GKI 内核

基于 AOSP `android16-6.12` 编译，**原厂厂商模块全兼容**，内建 Root，附带环境隐藏与性能优化。

---

## 支持的机型

| 机型 | 代号 | 内核版本串 |
|---|---|---|
| 小米 17 | `pudding` | `6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k` |
| Redmi K90 Pro Max / Poco F8 Ultra | `myron` | `6.12.69-android16-6-gb1493ec68d4a-abogki514973465-4k` |

**只支持以上两款。** 其他机型（含小米 17 Pro Max）不要刷。

判断方法：

```bash
getprop ro.product.device
# 输出 pudding 或 myron 才能刷
```

---

## 下载

到 [Releases](../../releases) 页，按机型选对应版本：

| 文件 | 用途 | KPM |
|---|---|---|
| `AnyKernel3_*.zip` | Root 管理器 / Recovery 刷入 | 看刷法 |
| `boot_*_nokpm.img.gz` | fastboot / dd / KernelFlasher | ❌ 不含 |

---

## 内核特性

| 项目 | 状态 |
|---|---|
| 原厂模块兼容 | ✅ 相机 / WiFi / 指纹 / 音频 / 快充正常 |
| Root 方案 | ✅ 内建，无需额外刷模块 |
| **KPM 内核模块** | ✅ 可用（需按下方方式刷入） |
| SELinux 状态处理 | ✅ |
| AVC 审计处理 | ✅ |
| 挂载点隐藏 | ✅ |
| 版本串伪装 | ✅ |
| ADIOS IO 调度器 | ✅ |
| LZ4 / LZ4KD 压缩 | ✅ |
| BBR 拥塞控制 | ✅ |
| CAKE / FQ / HTB / TBF / SFQ 队列 | ✅ |
| IPSet + netfilter 扩展（广告拦截 / 代理） | ✅ |
| TPROXY 透明代理 | ✅ |
| WireGuard | ✅ |
| DAMON 自适应回收 | ✅ |
| ZRAM ZSTD + 写回 | ✅ |
| ZSWAP / KSM | ✅ |
| F2FS 压缩 / EROFS LZMA / NTFS3 | ✅ |
| SUSFS | ❌ 不兼容当前 Root 方案 |

---

## 怎么刷

### 方式一：管理器刷入（**想要 KPM 必须用这个**）

1. 下载对应机型的 `AnyKernel3_*.zip`
2. 打开 **SukiSU Ultra 管理器**
3. **内核刷入** → **从本地安装** → 选这个 zip
4. **勾选「KPM 补丁模式」** ← 想要 KPM 就不能漏这一步
5. 刷入 → 重启

**为什么必须勾**：AK3 里是未打补丁的裸内核。KPM 需要管理器在刷入时用 kptools 给内核打补丁。不勾的话内核能正常启动，但 KPM 接口是空壳。

### 方式二：fastboot（KPM 不可用）

```bash
# 小米17
gunzip boot_pudding_nokpm.img.gz
# 或 K90
gunzip boot_k90_nokpm.img.gz

adb reboot bootloader
fastboot getvar current-slot          # 确认是 a 还是 b
fastboot flash boot_a boot_pudding_nokpm.img   # 按实际槽位和机型换文件名
fastboot reboot
```

### 方式三：dd 刷入（KPM 不可用）

```bash
su
# 文件名按机型替换
dd if=/sdcard/Download/boot_pudding_nokpm.img of=/dev/block/by-name/boot_b bs=4096
sync
reboot
```

### 方式四：TWRP / KernelFlasher

同上，刷 `boot_xxx.img` 或 AK3（不勾 KPM 模式）。

> **说明**：为什么没有「预打好 KPM 补丁的 boot.img」——KPM 的 superkey 是每台设备专属的，别人打的补丁到你机器上验证不过。所以带 KPM 的只能本机用管理器现场打。

---

## 刷完验证

```bash
uname -r
# 期望：6.12.69-android16-6-4k

cat /proc/version | head -1
# 期望包含对应机型的 abogki 号

lsmod | wc -l
# 期望：接近 660
```

**如果刷的时候勾了 KPM 模式，再查：**

```bash
/data/adb/ksu/bin/ksud kpm version
# 期望：输出类似  3337 (21:46:21 Oct 25 2026)

/data/adb/ksu/bin/ksud extension list | grep -A2 kpm
# 期望：[AVAILABLE] kpm (ID=0)
```

显示 `[NOT_SUPPORTED]` 说明刷的时候没勾 KPM 模式，或者管理器版本过旧。

---

## 怎么回滚

**能开机时：**

```bash
su
dd if=你的备份.img of=/dev/block/by-name/boot_a bs=4096
reboot
```

**开不了机时：**

长按 **音量下 + 电源** 进 fastboot：

```bash
fastboot flash boot_a 你的原厂boot.img
fastboot reboot
```

---

## 分区信息

| 机型 | boot_a | boot_b |
|---|---|---|
| 小米 17 | sde14 | sde57 |
| K90 Pro Max | sde14 | sde57 |

**刷前先确认当前槽位（A/B 会切换）：**

```bash
getprop ro.boot.slot_suffix
# 输出 _a 或 _b
```

脚本/命令里把 `boot_a` 换成实际槽位。

---

## 需要 Root 管理器

内核内建 SukiSU Ultra，需要配套管理器：

[SukiSU Ultra 管理器](https://github.com/SukiSU-Ultra/SukiSU-Ultra/releases)

**不要用官方 KernelSU 管理器**，接口不兼容。

---

#### ※※※ 刷写内核有风险。刷之前务必备份 boot 分区，或者至少确认能进 fastboot 回滚。※※※
