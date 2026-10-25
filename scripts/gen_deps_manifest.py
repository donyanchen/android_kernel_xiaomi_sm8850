#!/usr/bin/env python3
"""生成依赖清单 deps.json（含大小与 SHA256）。"""
import hashlib
import json
import os
import subprocess
import sys


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main():
    dist = sys.argv[1] if len(sys.argv) > 1 else "dist"
    if not os.path.isdir(dist):
        print(f"目录不存在: {dist}")
        return 1

    files = {}
    for fn in sorted(os.listdir(dist)):
        if fn == "deps.json":
            continue
        p = os.path.join(dist, fn)
        if not os.path.isfile(p):
            continue
        files[fn] = {"bytes": os.path.getsize(p), "sha256": sha256(p)}

    meta = {
        "ack_branch": os.environ.get("ACK_BRANCH", ""),
        "generated": subprocess.check_output(
            ["date", "-u", "+%Y-%m-%dT%H:%M:%SZ"], text=True
        ).strip(),
        "files": files,
    }
    out = os.path.join(dist, "deps.json")
    open(out, "w").write(json.dumps(meta, indent=2, ensure_ascii=False))
    print(json.dumps(meta, indent=2, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
