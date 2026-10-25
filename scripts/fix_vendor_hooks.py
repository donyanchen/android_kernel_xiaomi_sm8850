#!/usr/bin/env python3
"""移除 include/trace/hooks/ 下重复的 DECLARE_HOOK。

背景：小米优化移植包按 Linux 5.15 的情况向 mm.h / vmscan.h 注入 vendor hook
声明，但 ACK android16-6.12 已经把其中一部分（如 android_vh_get_page_wmark）
上游合入了。重复声明会导致：

    error: redefinition of 'trace_android_vh_get_page_wmark'

这里扫描全部 hook 头文件，同一个 hook 名字只保留第一次出现的声明。
"""
import os
import re
import sys

HOOK_DIR = "include/trace/hooks"
CALL_RE = re.compile(r"^\s*DECLARE_HOOK\(([A-Za-z0-9_]+)", re.M)


def dedupe_file(path):
    src = open(path, errors="ignore").read()
    # 按 DECLARE_HOOK 起点切块
    matches = list(CALL_RE.finditer(src))
    if len(matches) < 2:
        return 0

    seen = set()
    remove = []
    for idx, m in enumerate(matches):
        name = m.group(1)
        start = m.start()
        end = matches[idx + 1].start() if idx + 1 < len(matches) else len(src)
        block = src[start:end]
        if name in seen:
            remove.append((start, end))
        else:
            seen.add(name)

    if not remove:
        return 0

    # 从后往前删除，避免偏移失效
    out = src
    for start, end in reversed(remove):
        out = out[:start] + out[end:]
    open(path, "w").write(out)
    return len(remove)


def main(root="."):
    hook_dir = os.path.join(root, HOOK_DIR)
    if not os.path.isdir(hook_dir):
        print(f"skip: {hook_dir} not found")
        return 0
    total = 0
    for fn in sorted(os.listdir(hook_dir)):
        if not fn.endswith(".h"):
            continue
        p = os.path.join(hook_dir, fn)
        n = dedupe_file(p)
        if n:
            print(f"  {fn}: 移除 {n} 处重复声明")
            total += n
    print(f"共移除 {total} 处重复 DECLARE_HOOK")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1] if len(sys.argv) > 1 else "."))
