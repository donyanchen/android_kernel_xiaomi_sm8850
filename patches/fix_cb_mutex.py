#!/usr/bin/env python3
"""6.12 兼容性：netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除。

SukiSU 的 KPM super_access.c 用编译期结构体成员自检表引用该字段，
直接用 sizeof() 取成员会编译失败，这里加版本保护。
"""
import sys
import os

TARGET = "DEFINE_MEMBER(netlink_kernel_cfg, cb_mutex)\n"
GUARD_IF = "#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 9, 0)\n"
GUARD_END = "#endif\n"


def main():
    if len(sys.argv) < 2:
        print("usage: fix_cb_mutex.py <path-to-super_access.c>")
        return 1
    p = sys.argv[1]
    if not os.path.isfile(p):
        print(f"skip: {p} not found")
        return 0
    s = open(p).read()
    if "KERNEL_VERSION(6, 9, 0)" in s:
        print("skip: already guarded")
        return 0
    if TARGET not in s:
        print("skip: target line not present")
        return 0
    s = s.replace(TARGET, GUARD_IF + TARGET + GUARD_END, 1)
    open(p, "w").write(s)
    print("patched: cb_mutex guarded")
    return 0


if __name__ == "__main__":
    sys.exit(main())
