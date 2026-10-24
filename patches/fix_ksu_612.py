#!/usr/bin/env python3
"""修复 SukiSU 在 6.12 上的两个编译问题。

1. KPM 子目录编译时找不到父目录的 klog.h —— 需要 -I$(src)
2. netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除 —— 需要版本保护
"""
import os
import sys


def patch_kbuild(path):
    if not os.path.isfile(path):
        print(f"skip kbuild: {path} not found")
        return
    s = open(path).read()
    if "-I$(src)" in s:
        print("skip kbuild: -I$(src) already present")
        return
    s = s.rstrip("\n") + "\n\n# 子目录（extension/kpm）编译时需要父目录头文件\nccflags-y += -I$(src)\n"
    open(path, "w").write(s)
    print("patched: -I$(src) added to Kbuild")


def patch_cb_mutex(path):
    if not os.path.isfile(path):
        print(f"skip cb_mutex: {path} not found")
        return
    s = open(path).read()
    target = "DEFINE_MEMBER(netlink_kernel_cfg, cb_mutex)\n"
    if "KERNEL_VERSION(6, 9, 0)" in s:
        print("skip cb_mutex: already guarded")
        return
    if target not in s:
        print("skip cb_mutex: target not present")
        return
    s = s.replace(
        target,
        "#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 9, 0)\n" + target + "#endif\n",
        1,
    )
    open(path, "w").write(s)
    print("patched: cb_mutex guarded")


def main():
    patch_kbuild("drivers/kernelsu/Kbuild")
    patch_cb_mutex("drivers/kernelsu/extension/kpm/super_access.c")
    return 0


if __name__ == "__main__":
    sys.exit(main())
