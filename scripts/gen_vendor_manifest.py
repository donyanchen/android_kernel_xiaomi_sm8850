#!/usr/bin/env python3
"""生成分块源码清单 manifest.json（含整体 SHA256）。"""
import hashlib
import json
import os
import sys


def main():
    d = sys.argv[1] if len(sys.argv) > 1 else "vendor/ack"
    branch = os.environ.get("ACK_BRANCH", "")
    if not os.path.isdir(d):
        print(f"目录不存在: {d}")
        return 1

    parts = sorted(p for p in os.listdir(d) if ".part-" in p)
    if not parts:
        print("未找到分块文件")
        return 1

    h = hashlib.sha256()
    total = 0
    for p in parts:
        fp = os.path.join(d, p)
        total += os.path.getsize(fp)
        with open(fp, "rb") as f:
            for chunk in iter(lambda: f.read(1 << 20), b""):
                h.update(chunk)

    meta = {
        "branch": branch,
        "parts": parts,
        "total_bytes": total,
        "sha256": h.hexdigest(),
        "note": "用 cat 按顺序拼接后即得原始 tar.gz",
    }
    out = os.path.join(d, "manifest.json")
    open(out, "w").write(json.dumps(meta, indent=2))
    print(json.dumps(meta, indent=2)[:800])
    return 0


if __name__ == "__main__":
    sys.exit(main())
