#!/usr/bin/env python3
"""修复 SukiSU 在 6.12 / GKI 构建下的编译问题。

问题 1：子目录（core/、feature/、extension/kpm/ ...）编译时找不到 KSU 自身头文件。
        SukiSU 的头文件分散在 kernel/include/ 与 kernel/uapi/，而子目录源码用的是
        #include "xxx.h" 形式。子目录没有独立 Kbuild，父目录 ccflags 不生效。

        解法：扫描整个 kernelsu 目录，建立「头文件名 -> 真实相对路径」索引；
        对每个源文件，若 #include "x.h" 的文件不在同目录，且全树有唯一匹配，
        就改写成正确的相对路径。

问题 2：netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除。
"""
import os
import re
import sys

KSU_DIR = "drivers/kernelsu"
INCLUDE_RE = re.compile(r'#include\s+"([^"]+)"')


def build_index():
    """头文件名 -> [相对 KSU_DIR 的路径...]"""
    index = {}
    for root, _, files in os.walk(KSU_DIR):
        for f in files:
            if not f.endswith(".h"):
                continue
            rel = os.path.relpath(os.path.join(root, f), KSU_DIR)
            index.setdefault(f, []).append(rel)
    return index


def depth_of(rel_path):
    d = os.path.dirname(rel_path)
    if not d or d == ".":
        return 0
    return len([p for p in d.split(os.sep) if p])


def fix_includes():
    if not os.path.isdir(KSU_DIR):
        print("skip includes: kernelsu dir not found")
        return
    index = build_index()
    print(f"headers indexed: {len(index)} names")

    changed_files = 0
    changed_includes = 0

    for root, _, files in os.walk(KSU_DIR):
        for f in files:
            if not f.endswith((".c", ".h")):
                continue
            path = os.path.join(root, f)
            rel_file = os.path.relpath(path, KSU_DIR)
            depth = depth_of(rel_file)
            if depth == 0:
                continue
            src_dir = os.path.dirname(path)
            s = open(path, errors="ignore").read()
            orig = s

            def repl(m):
                nonlocal changed_includes
                name = m.group(1)
                if name.startswith("..") or name.startswith("/"):
                    return m.group(0)
                # 同目录存在则保持原样
                if os.path.isfile(os.path.join(src_dir, name)):
                    return m.group(0)
                base = os.path.basename(name)
                cands = index.get(base, [])
                if len(cands) != 1:
                    return m.group(0)
                prefix = "../" * depth
                new = f'#include "{prefix}{cands[0].replace(os.sep, "/")}"'
                changed_includes += 1
                return new

            s = INCLUDE_RE.sub(repl, s)
            if s != orig:
                open(path, "w").write(s)
                changed_files += 1

    print(f"patched includes: {changed_includes} in {changed_files} file(s)")


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
