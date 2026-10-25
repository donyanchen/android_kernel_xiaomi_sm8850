# SUSFS 适配结论（2026-10-25）

## 结论：本项目不集成 SUSFS

原因不是配置或版本号，而是**补丁与 SukiSU 的 hook 模型不兼容**。

## 尝试过的路径

| 组合 | 结果 |
|---|---|
| SukiSU `main` + susfs4oki `50_` 补丁 | 编译过，但 `CONFIG_KSU_SUSFS` 被 kconfig 丢弃 —— SukiSU main 的 Kconfig 里没有这些符号 |
| SukiSU `builtin` + susfs4oki `oki-android16-6.12` | 编译失败：缺 `CMD_SUSFS_SET_PRIORITY_UID_FILTER`（旧分支没有） |
| SukiSU `builtin` + susfs4oki `-dev` | 编译成功（SUSFS v2.3.0 已编入），但**刷入后一屏狂闪、无限重启** |
| SukiSU `main` + susfs4oki `-dev` 的 `10_` 补丁 | 8 处冲突，且不是格式问题 |
| 官方 KernelSU + susfs4oki `-dev` 的 `10_` 补丁 | **零冲突，干净套用** |

## 关键不兼容点

`10_enable_susfs_for_ksu.patch` 期望的 KSU 接口：

```c
int ksu_handle_setresuid(uid_t old_uid, uid_t new_uid)
```

SukiSU `main` 已经改用新版 hook 模型：

```c
int ksu_handle_execveat_ksud(int *fd, struct filename **filename_ptr,
                             struct user_arg_ptr *argv,
                             struct user_arg_ptr *envp, int *flags)
```

SUSFS 需要把自己的逻辑插进 setuid hook。两个版本的 hook 模型不同，**要移植必须重写对接层**，属于内核开发工作，不是打补丁能解决的。

## `builtin` 分支为什么会崩溃

`builtin` 分支自带 SUSFS 集成，编译通过、符号也在（`susfs_add_sus_path` 等），SUSFS 版本串是 `v2.3.0`。

但刷入后一屏狂闪、无限重启，`pstore` 无记录（说明在 ramoops 初始化前就挂了）。

`builtin` 分支在 2026-10-25 09:30 还有提交，属于活跃开发中，未针对 6.12 GKI 做完整验证。

## 如果要 SUSFS

唯一干净的路是**用官方 KernelSU 替代 SukiSU**：

```
官方 KernelSU (tiann/KernelSU)
  + susfs4oki oki-android16-6.12-dev 的 10_ 补丁   → 零冲突
  + 50_ 补丁
```

代价：失去 SukiSU 的特性（KPM 内核模块加载、内置管理面板、preinit runner）。

## 当前采用的方案

```
SukiSU main（已验证可开机、全功能正常）
+ KPM
+ 无 SUSFS
```

隐藏能力依赖 SukiSU 内置的 `selinux_hide` 等特性，以及用户态方案（Zygisk 模块、HMA 等）。
