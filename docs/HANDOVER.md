# 小米 17 内核 —— #60 之后的进展交接

> 从「自编译内核 #60 已能开机」这个节点开始，之后发生的所有尝试与结论。
> 时间：2026-10-25

---

## 一、起点：#60 已可用

```
设备      小米 17（pudding / canoe / SM8850）
系统      HyperOS OS4.0.5.0.XPCCNXM，Android 17（SDK 37）
内核      6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
vermagic  6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64
分区      A/B，_b，boot_b=/dev/block/sde57，init_boot_b=/dev/block/sdf72
boot      header v4，ramdisk_size=0，内核偏移 4096
```

#60 状态（全部实测通过）：

```
sys.boot_completed = 1
lsmod 669 个，404 个厂商模块全部加载
su -c id → uid=0 context=u:r:ksu:s0
相机 / WiFi(cnss2) / 指纹 / 音频 / 100W 快充 全正常
/proc/version 与原厂一致（abogki561813157）
```

构建来源：ACK `android16-6.12-2026-03` + 设备 `/proc/config.gz` 全量配置 + SukiSU main。

关键改动：

```
kernel/module/version.c 的 check_version() 返回 1（跳过符号 CRC 校验）
init/version-timestamp.c 替换 release= 与 LINUX_COMPILER 为原厂字面量
```

依据：BTF 实测 11,109/11,124 个结构体与原厂一致，`struct module` 1600 字节 / 75 成员逐成员相同。CRC 差异来自 `EXTENDED_MODVERSIONS` + `GENDWARFKSYMS` 的编译器 DWARF 指纹，不是真实 ABI 不兼容。

---

## 二、之后的两次尝试，都失败

### 尝试 1：加 SUSFS

目标：内核级隐藏，减轻检测。

试了 5 种组合：

| 组合 | 结果 |
|---|---|
| SukiSU `main` + susfs4oki `50_` 补丁 | 编译过，但 `CONFIG_KSU_SUSFS` 被 kconfig 丢弃（main 的 Kconfig 没有这些符号） |
| SukiSU `builtin` + susfs 旧分支 | 编译失败：缺 `CMD_SUSFS_SET_PRIORITY_UID_FILTER` |
| SukiSU `builtin` + susfs `-dev` 分支 | 编译成功、SUSFS v2.3.0 已编入，**但刷入后一屏狂闪无限重启** |
| SukiSU `main` + dev 的 `10_` 补丁 | 8 处冲突 |
| **官方 KernelSU + dev 的 `10_` 补丁** | **零冲突，干净套用** |

**根因**：`10_enable_susfs_for_ksu.patch` 期望 `ksu_handle_setresuid(uid_t, uid_t)`，SukiSU main 已换成 `ksu_handle_execveat_ksud(int *fd, struct filename **, ...)`。SUSFS 要插入 setuid hook，两版 hook 模型不同，移植需重写对接层。

**结论**：要 SUSFS 只能换官方 KernelSU，代价是失去 KPM 与 SukiSU 特性。

修过的编译问题（记录备用）：

```
drivers/kernelsu/hook/lsm_hook.c    6.12 的 security_add_hooks 需 struct lsm_id（已写补丁）
fs/proc/task_mmu.c                  SUSFS 补丁末尾加 label，触发 -Werror,-Wc23-extensions
```

### 尝试 2：用 KernelPatch 让 KPM 可用

背景：SukiSU 的 `CONFIG_KPM=y` 只是**接口壳**：

```
KernelSU: kpm: Stub function called (sukisu_kpm_load_module_path). ptr=0000000000000000
```

真正的 KPM 依赖 KernelPatch。

| 尝试 | 结果 |
|---|---|
| 自编译内核 + KPatch-Next 0.13.14 预编译（kpimg 0xd0e） | 刷入后进 fastboot，无内核日志 |
| 自编译内核 + 源码编译（bmax121/KernelPatch 提交 052c73f，含 2026-10-20 RELA 重定位修复） | 同样进 fastboot |
| 原厂内核 + KPatch（用户此前实测） | 用户反馈也起不来 |

已排除的因素（都验证过）：

```
kptools 符号解析      kallsyms_lookup_name 偏移 0x20F1F8，与设备 /proc/kallsyms 算出的一致
补丁结构              入口跳板 kernel_end+5632，与原厂成功版完全对称
trampoline            有效 ARM64 指令
重打包                magiskboot 与手工 dd 结果等价
oops 分区(mtdoops)    无任何崩溃记录 → 在早期打印之前就挂了
```

**在手机上编译 KernelPatch 的方法（可复用）**

```bash
cd kernel && make TARGET_COMPILE=/usr/bin/ hdr kpimg
cd tools && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make
```

需先修三个上游问题：

```
1. patch/include/selinux_sepolicy.h 缺 selinux_sepolicy_clean_eval_enter/leave 原型
2. patch/common/supercmd.c 缺 #include <userd.h>
3. kernel/Makefile 的 CFLAGS 加 -fno-stack-protector（Alpine gcc 默认开，裸机代码不能有 libc 依赖）
```

---

## 三、当前状态

```
运行内核   #60（回到这一版）
root       正常，13 个模块，0 个被禁
SUSFS      无
KPM        无（stub）
```

`selinux_hide` 已启用（`ksud feature get selinux_hide` → Value 1 / enabled），但只能处理 `/sys/fs/selinux` 的查询结果，**不隐藏进程 SELinux 域**。

检测器读 `/proc/<pid>/attr/current`，当前 24+ 个进程在 `u:r:ksu:s0`：

```
ksud            必须有（KernelSU 守护进程）
zn-daemon       必须有（Zygisk Next 核心）
zygisk_lsposed  可停用
zygisk-sui      可停用
cq_uid_seccomp  可停用
mihomo          代理跑在 root，可改非 root
```

所以「ROOT/异常模块」与「SELinux Policy」这两项靠 `selinux_hide` 清不掉，需要内核级隐藏（SUSFS 或 KPM），两条路都已堵死。

**唯一没查透的点**：`ksud feature set selinux_hide 1` 会报

```
ksuctl failed: Try again (os error 11)     ← EAGAIN
```

但 `feature get` 显示已启用。这个 EAGAIN 的成因值得挖。

---

## 四、设备上的文件

```
/sdcard/Download/kp/
  boot_original.img                 原厂（md5 cfb6faa689c23fb1988d6e35d016d9ec）
  boot_kpatch.img                   KPatch 版（历史存档）
  boot_b_before57/60/66/kp/kp2.img  各阶段备份
  boot_pudding_57/60/66/kp.img      自编译版本
  init_boot_b_before_restore.img    改动过的 init_boot 备份
```

固件包：`/storage/emulated/0/Download/DLManager/pudding-ota_full-OS4.0.5.0.XPCCNXM-user-17.0-2bdf4c81b9.zip`

---

## 五、可以继续的方向

1. **查 `selinux_hide` 的 EAGAIN** —— 唯一还没查透、且无变砖风险的点。

2. **换官方 KernelSU 换 SUSFS** —— 技术已验证零冲突，代价是失去 KPM 与 SukiSU 特性。

3. **继续调 KernelPatch** —— 需要能拿到早期启动日志（串口，或 cmdline 加 `earlycon` + 加大 `log_buf_len`），否则只能盲试。

4. **升级到 6.12.96** —— ACK `android16-6.12-lts` 已到 6.12.96（当前落后 27 个 sublevel）。GKI 约定同一 KMI 代次 ABI 稳定，理论上加个 vermagic 补丁即可，但要重新验证结构体。

---

## 六、踩过的坑（避免重犯）

```
persist.adb.tcp.port=5555   会让系统把 adb 从 USB 组合里剔除，插电脑只剩 MTP，
                            重启不恢复。清掉后还要 settings put global adb_enabled 0→1
                            触发重新组合
手机直连手机 USB 调试        必须 OTG 在主机侧，两边都是 device 时只有充电
YAML run: | 里 heredoc 顶格  整个 workflow 失效（jobs=0，运行名显示文件路径）
CONFIG_MODULE_SIG_PROTECT=y  内核树根必须有 protected_module_names_list 文件
```
