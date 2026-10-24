#!/usr/bin/env python3
"""修复 SukiSU 在 6.12 / GKI 构建下的编译问题。

问题 1：KPM 子目录编译时找不到 klog.h 等头文件。
        SukiSU 的 klog.h 实际位于 kernel/include/klog.h（部署后是
        drivers/kernelsu/include/klog.h），而子目录里的源码写的是
        #include "klog.h"。子目录没有独立 Kbuild，父目录 ccflags 不生效。
        这里自动定位头文件真实位置，把 include 改写成正确的相对路径。

问题 2：netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除。
"""
import os
import sys

KSU_DIR = "drivers/kernelsu"
# 需要修正为相对路径的头文件（在 KSU 目录内查找真实位置）
TARGET_HEADERS = ["klog.h"]


def build_header_index():
    """扫描 KSU 目录，建立 文件名 -> 相对 KSU_DIR 的路径 映射。"""
    index = {}
    for target in TARGET_HEADERS:
        for root, _, files in os.walk(KSU_DIR):
            if target in files:
                rel = os.path.relpath(os.path.join(root, target), KSU_DIR)
                index[target] = rel
                break
    return index


def depth_of(rel_path):
    d = os.path.dirname(rel_path)
    if not d:
        return 0
    return len([p for p in d.split(os.sep) if p and p != "."])


def fix_includes():
    if not os.path.isdir(KSU_DIR):
        print("skip includes: kernelsu dir not found")
        return
    index = build_header_index()
    print(f"header index: {index}")
    if not index:
        print("skip includes: no target headers located")
        return

    changed = 0
    for root, _, files in os.walk(KSU_DIR):
        for f in files:
            if not f.endswith((".c", ".h")):
                continue
            path = os.path.join(root, f)
            rel_file = os.path.relpath(path, KSU_DIR)
            depth = depth_of(rel_file)
            if depth == 0:
                continue
            s = open(path, errors="ignore").read()
            orig = s
            prefix = "../" * depth
            for name, real_rel in index.items():
                # 已经是相对路径的不动
                s = s.replace(
                    f'#include "{name}"',
                    f'#include "{prefix}{real_rel.replace(os.sep, "/")}"',
                )
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
