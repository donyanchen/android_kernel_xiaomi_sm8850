#!/usr/bin/env python3
"""
对已构建的内核 Image 做等长二进制替换，使 /proc/version 与原厂一致

不需要重新编译：版本串与编译器构建号都是定长字符串，
在 .rodata 里原地替换即可。

用法：
  python3 patch_image.py <Image> [输出路径]
"""
import sys, re, os, shutil

OFFICIAL_VER = '6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k'
OFFICIAL_CC_BUILD = '14043575'          # 原厂 clang 构建号
FAKE_CC_BUILDS = re.compile(rb'Android \((\d{8})')

VER_PAT = re.compile(rb'6\.12\.69-android16-6-g[0-9a-f]{7,12}-abogki\d{9}-4k')


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    src = sys.argv[1]
    dst = sys.argv[2] if len(sys.argv) > 2 else src.replace('.img', '.patched.img')
    if dst == src:
        dst = src + '.patched'

    d = bytearray(open(src, 'rb').read())
    print(f'输入: {src}  ({len(d):,} 字节)')

    # --- 1. 版本串 ---
    hits = list(VER_PAT.finditer(d))
    if not hits:
        print('⚠ 未找到版本串，跳过')
        ver_done = 0
    else:
        official = OFFICIAL_VER.encode()
        assert len(official) == len(hits[0].group()), \
            f'长度不等: 官方{len(official)} vs 现有{len(hits[0].group())}'
        for h in hits:
            d[h.start():h.end()] = official
        ver_done = len(hits)
        print(f'✓ 版本串替换 {ver_done} 处 -> {OFFICIAL_VER}')

    # --- 2. 编译器构建号 ---
    cc = list(FAKE_CC_BUILDS.finditer(d))
    cc_done = 0
    for m in cc:
        cur = m.group(1)
        if cur.decode() != OFFICIAL_CC_BUILD:
            d[m.start(1):m.end(1)] = OFFICIAL_CC_BUILD.encode()
            cc_done += 1
    print(f'✓ 编译器构建号替换 {cc_done} 处 -> {OFFICIAL_CC_BUILD}')

    open(dst, 'wb').write(bytes(d))
    print(f'输出: {dst}  ({os.path.getsize(dst):,} 字节)')
    return 0


if __name__ == '__main__':
    sys.exit(main())
