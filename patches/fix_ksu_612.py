#!/usr/bin/env python3
"""修复 SukiSU 在 6.12 / GKI 构建下的编译问题。

问题 1：子目录（core/、feature/、extension/kpm/ ...）编译 KSU 自身源文件时，
        找不到本仓库的头文件。SukiSU 的头文件分布在 kernel/include/、kernel/uapi/、
        kernel/policy/ 等目录，而子目录源码写的是 #include "xxx.h"。
        子目录没有独立 Kbuild，父目录 ccflags 传不进来。

        解法：建立头文件索引（排除 vendored 的 preinit/runner/nolibc），
        对每个源文件把无法就地解析的 #include "xxx.h" 改写成相对路径；
        重名时优先取 include/ 下的那份。

问题 2：netlink_kernel_cfg.cb_mutex 在 Linux 6.9+ 已移除。
"""
import os
import re
import sys

KSU_DIR = "drivers/kernelsu"
SKIP_DIR = "preinit/runner/nolibc"
INCLUDE_RE = re.compile(r'#include\s+"([^"]+)"')


def _skip(path_rel):
    return SKIP_DIR in path_rel.replace(os.sep, "/")


def build_index():
    index = {}
    for root, _, files in os.walk(KSU_DIR):
        rel_root = os.path.relpath(root, KSU_DIR)
        if _skip(rel_root):
            continue
        for f in files:
            if not f.endswith(".h"):
                continue
            rel = os.path.relpath(os.path.join(root, f), KSU_DIR)
            index.setdefault(f, []).append(rel)
    return index


def pick(cands):
    if len(cands) == 1:
        return cands[0]
    if len(cands) > 1:
        preferred = [c for c in cands if c.replace(os.sep, "/").startswith("include/")]
        if len(preferred) == 1:
            return preferred[0]
    return None


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

    fixed = 0
    files_changed = 0

    for root, _, files in os.walk(KSU_DIR):
        rel_root = os.path.relpath(root, KSU_DIR)
        if _skip(rel_root):
            continue
        for f in files:
            if not f.endswith((".c", ".h")):
                continue
            path = os.path.join(root, f)
            depth = depth_of(os.path.relpath(path, KSU_DIR))
            if depth == 0:
                continue
            src_dir = os.path.dirname(path)
            s = open(path, errors="ignore").read()
            orig = s

            def repl(m):
                nonlocal fixed
                name = m.group(1)
                if name.startswith("..") or name.startswith("/") or "/" in name:
                    return m.group(0)
                if os.path.isfile(os.path.join(src_dir, name)):
                    return m.group(0)
                chosen = pick(index.get(name, []))
                if not chosen:
                    return m.group(0)
                fixed += 1
                return '#include "%s%s"' % ("../" * depth, chosen.replace(os.sep, "/"))

            s = INCLUDE_RE.sub(repl, s)
            if s != orig:
                open(path, "w").write(s)
                files_changed += 1

    print(f"patched includes: {fixed} in {files_changed} file(s)")


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
