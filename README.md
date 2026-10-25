# 小米 17（pudding）自编译 Android GKI 内核

在小米 17（pudding / canoe / SM8850）上自编译 Android GKI 内核，使之能加载原厂 404 个厂商模块并正常开机。

当前状态：**可开机、可 Root、厂商模块全部加载**。

```
内核版本    6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k（显示串对齐原厂）
vermagic    6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
实测结果    sys.boot_completed=1，lsmod 669 个模块，KSU root 正常
```

---

## 仓库内容说明

**本仓库只包含构建流程与开源代码，不含设备私有数据。**

| 内容 | 位置 | 是否公开 |
|---|---|---|
| CI 定义、构建脚本、上游补丁、自写工具 | 本仓库 | ✅ 公开 |
| 设备 ABI 符号表、原厂 defconfig、厂商桩函数、Kconfig | `donyanchen/pudding-private` | ❌ 私有 |
| Linux 内核源码 | `android.googlesource.com`（构建时拉取） | ✅ 公开 |
| Root 方案源码 | `donyanchen/FinaSU` / `donyanchen/SukiSU-Ultra` | ✅ 公开 |

**为什么要这样分**：内核与 Root 方案都是 GPL-2.0，必须开源；而 ABI 符号表、原厂配置、厂商符号签名是**从设备固件逆向得到的数据**，不是内核代码，不受 GPL 约束，因此单独存放在私有仓库。

### 构建前必须配置

在仓库 Settings → Secrets and variables → Actions 添加：

| Name | 值 |
|---|---|
| `PRIVATE_REPO_TOKEN` | 只勾 `Contents: Read-only`、限定 `pudding-private` 的 fine-grained token |

CI 的「拉取私有配置」步骤会用它 clone 私有仓库；**secret 缺失时构建会直接失败**，不会用空配置编出废镜像。

---

## 功能

| 功能 | 状态 | 说明 |
|---|---|---|
| 厂商模块兼容 | 已实现 | 404 个模块全部加载，相机 / WiFi / 音频 / 充电 / 触控正常 |
| KernelSU | 已实现 | FinaSU / SukiSU Ultra 可选，内核内建 |
| `selinux_hide` 修复 | 已实现 | 修复 `sequence` 硬编码、备份误释放、失败仍报 ENABLED |
| `avc_spoof` | 已实现 | AVC 审计日志伪装 |
| `mount_hide` / `mount_view_filter` | 已实现 | 挂载点隐藏 |
| `uts_spoof` / `uts_view` | 已实现 | `/proc/version` 版本串伪装 |
| ADIOS IO 调度器 | 已实现 | 附加 mq 调度器，可按设备切换 |
| LZ4KD 压缩 | 已实现 | zram 额外压缩算法 |
| 版本串对齐 | 已实现 | `/proc/version` 与原厂逐字一致 |
| SUSFS | ❌ 未集成 | 补丁与 SukiSU hook 模型不兼容，详见 `docs/SUSFS.md` |
| KPM | ⚠️ 不可用 | 需 KernelPatch，本内核打不上 |
| 小米优化移植包 | 未启用 | 16 个模块已适配（`scripts/apply_sew.sh`），默认关闭 |

## 1. 适用范围

| 项目 | 值 |
|---|---|
| 机型 | 小米 17，代号 pudding |
| 平台 | SM8850 / canoe |
| 系统 | HyperOS OS4.0.5.0.XPCCNXM（Android 17 / SDK 37） |
| 内核 KMI | `android16-6-4k`（与系统版本无关，见下） |
| 分区 | A/B，`boot_b = /dev/block/sde57`，`boot_a = /dev/block/sde14` |
| boot 格式 | header v4，`ramdisk_size=0`，内核偏移 4096 |
| 源码基线 | ACK `android16-6.12-2026-03`（SUBLEVEL 69） |

**关于 `android16`**：这是 GKI 的 KMI 世代标识，**不是系统版本**。Android 17 系统配 `android16-6-4k` 内核是正常组合——厂商升级系统层时继续沿用旧 KMI 内核。

**不适用于**：其他机型、非 A/B 设备、KMI 或 sublevel 不同的固件。换机型时 ABI 依据全部作废，需重新采集。

本仓库只产出**内核镜像**，不含用户态。KSU 的内核侧驱动编进内核，用户态由 `init_boot` 提供。

---

## 2. 快速开始

### 2.1 构建

仓库使用 GitHub Actions，手动触发：

```
Actions → Build Kernel → Run workflow
  ack_branch   android16-6.12-2026-03
  kpm          任意（当前无实际作用，见下方说明）
  features     true
  sew_opt      false
```

构建约 20 分钟，产物为 `Image-6.12.69`（含 `arch/arm64/boot/Image`、`vmlinux.symvers`、`.config`）。

> **`kpm` 输入当前无实际作用**：`build.yml` 里定义了这个输入但没有任何步骤读取它。KPM 需要 KernelPatch 提供后端，本内核打不上。

### 2.2 打包 boot.img

```bash
# 从设备备份的 boot 镜像出发
dd if=/dev/block/by-name/boot_b of=bootb.img

# 解包 → 替换内核 → 重打包
magiskboot unpack bootb.img
gzip -9 -n -c Image > kernel
magiskboot repack bootb.img new_boot.img
```

也可用仓库内的 `scripts/pack_boot.py`：

```bash
python3 pack_boot.py bootb_hdr.bin Image boot_pudding.img
```

### 2.3 刷写

**方式一：一键脚本（推荐）**

```bash
su
sh flash.sh
```

脚本会自动检测当前槽位、备份目标分区、校验 md5、写入后回读验证，失败自动回滚。

**方式二：fastboot**

```bash
adb reboot bootloader
fastboot getvar current-slot          # 确认是 a 还是 b
fastboot flash boot_b new_boot.img    # 按实际槽位
fastboot reboot
```

> ⚠️ **不要用 `fastboot flash:raw`**：会丢掉 20MB 的 `kernel_dtb`，导致无法开机。

### 2.4 回滚

```bash
# 系统还能起来
su -c "dd if=你的备份.img of=/dev/block/by-name/boot_b bs=4096"

# 起不来：长按 音量下 + 电源 进 fastboot
fastboot flash boot_b 备份.img
```

### 2.5 首次开机

```bash
# 验证内核版本
uname -r
# 期望 6.12.69-android16-6-4k

# 验证 SELinux 状态页（本版关键修复）
su -c "od -An -tx4 /sys/fs/selinux/status"
# 期望 00000001 <sequence> 00000001 00000000
#      policyload 末位必须是 0，不是 1
```

---

## 3. 技术原理

### 3.1 ABI 策略：设备配置是唯一基准

自编译内核要与原厂 404 个厂商模块兼容，`vermagic` 与导出符号 CRC 都必须对上。

配置只能从设备 `/proc/config.gz` 全量导出（2,301 项）。曾尝试按 ACK 默认值多开 `CFG80211` / `MAC80211` / `MHI_BUS`，结果 CRC 一致率仅 31.8%。

### 3.2 为什么 CRC 无法精确对齐

`EXTENDED_MODVERSIONS` + `GENDWARFKSYMS` 使符号 CRC 由 DWARF 信息计算，**绑定编译器版本与优化选项**，无法用不同工具链复现。

依据：BTF 实测 11,109 / 11,124 个结构体与原厂一致，`struct module` 1600 字节 / 75 成员逐成员相同 —— 差异来自编译器 DWARF 指纹，不是真实 ABI 不兼容。

### 3.3 跳过 CRC 校验

`kernel/module/version.c` 的 `check_version()` 直接返回 1，跳过符号 CRC 校验。

### 3.4 版本串伪装

`init/version-timestamp.c` 中替换 `release=` 与 `LINUX_COMPILER` 为原厂字面量，使 `/proc/version` 逐字一致。

---

## 4. 踩坑记录

### 4.1 最贵的一次：卡开机动画，根因是 ASHMEM

```
缺 CONFIG_ASHMEM
 → zygote: Failed to create ashmem
 → FATAL EXCEPTION IN SYSTEM PROCESS
 → 卡开机动画（内核不崩、pstore 空）
 → BootFailReport 计数超限 → 自动禁用所有 KSU 模块
```

ACK 6.12 中 ASHMEM 依赖 RUST，RUST 需 bindgen。CI 工具链缓存命中导致 bindgen 从未安装，`RUST_IS_AVAILABLE=n`，kconfig **静默丢弃** RUST 与 ASHMEM（不报错）。

### 4.2 `/proc/kallsyms` 里带方括号的是模块导出

不是内核导出。统计口径：
- 内核本体导出 9,933
- 模块导出 4,801
- 404 个厂商模块真正需要内核提供 2,716

### 4.3 不要设 `persist.adb.tcp.port=5555`

会让系统把 adb 从 USB 组合里剔除，插电脑只剩 MTP，重启不恢复。清掉后还要 `settings put global adb_enabled 0→1` 触发重新组合。

### 4.4 手机直连手机做 USB 调试

必须 OTG 在主机侧，两边都是 device 时只有充电。

### 4.5 GitHub Actions 的 YAML heredoc

`run: |` 里 heredoc 顶格写会让整个 workflow 失效（jobs=0，运行名显示文件路径）。

### 4.6 `CONFIG_MODULE_SIG_PROTECT` 需要额外文件

内核树根必须有 `protected_module_names_list` 文件，否则：

```
make[2]: *** No rule to make target 'protected_module_names_list', needed by 'Module.symvers'
```

### 4.7 `setup.sh` 分支不存在时静默回退

SukiSU 的 `setup.sh` 里：

```sh
git checkout "$1" && echo "[-] Checked out $1." || echo "[-] Checkout default branch"
```

从上游 clone 时 `git checkout pudding` 会失败，`||` 分支吞掉错误，**编出一个不含任何修复的内核，CI 却显示绿色**。

已修正：clone 指向 fork，checkout 失败直接 `exit 1`。

---

## 5. 已知限制与待办

### 已知限制

| 项 | 说明 |
|---|---|
| `CONFIG_CC_VERSION_TEXT` | 仍为 `Android (12833971)`，原厂是 `14043575`，会出现在 `/proc/version` 里 |
| SUSFS | 补丁与 SukiSU hook 模型不兼容，见 `docs/SUSFS.md` |
| KPM | 需 KernelPatch，本内核打不上，接口为 stub |

### 待办

- [x] 设备私有数据迁至 `pudding-private`
- [x] CI 从私有仓库拉取配置
- [ ] 清理后验证构建（公开仓库已无敏感文件）

---

## 6. 相关仓库

| 仓库 | 内容 |
|---|---|
| `donyanchen/FinaSU` | Root 方案（当前使用），`pudding` 分支含 `selinux_hide` 修复 |
| `donyanchen/SukiSU-Ultra` | Root 方案（备选），`pudding` 分支含同样修复 |
| `donyanchen/pudding-private` | 设备 ABI 数据、原厂配置、厂商桩函数（私有） |
