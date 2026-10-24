#!/usr/bin/env python3
"""修复 SukiSU 在 6.12 / GKI 构建下的编译问题。

问题 1：KPM 子目录编译时找不到父目录的 klog.h、policy 等头文件。
        子目录没有独立 Kbuild，父目录 ccflags 不生效，KCFLAGS 也不被采用，
        直接把 #include "klog.h" 改写成正确的相对路径最可靠。

问题 2：netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除。
"""
import os
import re
import sys

KSU_DIR = "drivers/kernelsu"
LOCAL_HEADERS = ["klog.h"]


def depth_of(rel_path):
    """返回相对于 drivers/kernelsu 的目录层数。"""
    d = os.path.dirname(rel_path)
    if not d:
        return 0
    return len([p for p in d.split(os.sep) if p])


def fix_includes():
    if not os.path.isdir(KSU_DIR):
        print("skip includes: kernelsu dir not found")
        return
    changed = 0
    for root, _, files in os.walk(KSU_DIR):
        for f in files:
            if not f.endswith((".c", ".h")):
                continue
            path = os.path.join(root, f)
            depth = depth_of(os.path.relpath(path, KSU_DIR))
            if depth == 0:
                continue
            s = open(path, errors="ignore").read()
            orig = s
            prefix = "../" * depth
            for h in LOCAL_HEADERS:
                s = s.replace(f'#include "{h}"', f'#include "{prefix}{h}"')
            if s != orig:
                open(path, "w").write(s)
                changed += 1
    print(f"patched includes: {changed} file(s)")


def patch_cb_mutex():
    path = os.path.join(KSU_DIR, "extension/kpm/super_access.c")
    if not os.path.isfile(path):
        print("skip cb_mutex: file not found")
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
    fix_includes()
    patch_cb_mutex()
    return 0


if __name__ == "__main__":
    sys.exit(main())
