#!/usr/bin/env python3
"""
补齐 SUSFS 的 Kconfig 定义

背景：
  susfs4oki 有两个补丁：
    kernel_patches/50_add_susfs_in_gki-androidXX-X.Y.patch   ← fs/susfs.c + fs/Makefile
    kernel_patches/KernelSU/10_enable_susfs_for_ksu.patch     ← kernel/Kconfig 定义
  CI 只打了 50_，导致 CONFIG_KSU_SUSFS 在 Kconfig 中不存在，
  kconfig 静默丢弃这些符号 → fs/susfs.o 不编译 → /sys/kernel/mm/susfs 不出现。

做法：
  只补 Kconfig 定义（不套用 10_ 整个补丁，避免与 SukiSU 源码冲突）。
  与 CI 里追加的 CONFIG 列表保持一致。

用法：
  python3 patch_susfs_kconfig.py <内核源码根>
"""
import sys, os

BLOCK = '''
menu "KernelSU - SUSFS"

config KSU_SUSFS
\tbool "KernelSU addon - SUSFS"
\tdepends on KSU
\tdefault y
\thelp
\t  susfs4ksu integration for KernelSU.

config KSU_SUSFS_HAS_MAGIC_MOUNT
\tbool "Support Magic Mount"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_SUS_PATH
\tbool "Enable sus_path"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_SUS_MOUNT
\tbool "Enable sus_mount"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_AUTO_ADD_SUS_KSU_DEFAULT_MOUNT
\tbool "Auto add sus ksu default mount"
\tdepends on KSU_SUSFS_SUS_MOUNT
\tdefault y

config KSU_SUSFS_AUTO_ADD_SUS_BIND_MOUNT
\tbool "Auto add sus bind mount"
\tdepends on KSU_SUSFS_SUS_MOUNT
\tdefault y

config KSU_SUSFS_SUS_KSTAT
\tbool "Enable sus_kstat"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_TRY_UMOUNT
\tbool "Enable try_umount"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_AUTO_ADD_TRY_UMOUNT_FOR_BIND_MOUNT
\tbool "Auto add try_umount for bind mount"
\tdepends on KSU_SUSFS_TRY_UMOUNT
\tdefault y

config KSU_SUSFS_SPOOF_UNAME
\tbool "Enable spoof uname"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_ENABLE_LOG
\tbool "Enable log"
\tdepends on KSU_SUSFS
\tdefault y

config KSU_SUSFS_HIDE_KSU_SUSFS_SYMBOLS
\tbool "Hide KSU SUSFS symbols"
\tdepends on KSU_SUSFS
\tdefault y

endmenu
'''


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    cands = [
        os.path.join(root, 'drivers/kernelsu/Kconfig'),
        os.path.join(root, 'drivers/KernelSU/Kconfig'),
    ]
    path = None
    for c in cands:
        if os.path.exists(c):
            path = c
            break
    if not path:
        print('✗ 未找到 kernelsu Kconfig（SukiSU 可能未集成）')
        return 1

    src = open(path, encoding='utf-8', errors='replace').read()
    if 'config KSU_SUSFS' in src:
        print('✓ Kconfig 已含 KSU_SUSFS，跳过')
        return 0

    open(path, 'a', encoding='utf-8').write(BLOCK)
    chk = open(path, encoding='utf-8').read()
    n = chk.count('config KSU_SUSFS')
    print(f'✓ 已向 {path} 追加 SUSFS 菜单（{n} 处 KSU_SUSFS 定义）')
    # 校验 Kbuild / Makefile 里有 susfs.o 入口
    mk = os.path.join(root, 'fs/Makefile')
    if os.path.exists(mk):
        ok = 'susfs.o' in open(mk, encoding='utf-8', errors='replace').read()
        print('  fs/Makefile 含 susfs.o:', '是' if ok else '否（50_ 补丁可能未生效）')
    return 0


if __name__ == '__main__':
    sys.exit(main())
