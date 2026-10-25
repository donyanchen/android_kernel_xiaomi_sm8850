#!/usr/bin/env python3
"""
伪装内核版本串，使 /proc/version 与原厂完全一致

原理：
  init/version-timestamp.c 里
    const char linux_banner[] =
        "Linux version " UTS_RELEASE " (" LINUX_COMPILE_BY "@"
        LINUX_COMPILE_HOST ") (" LINUX_COMPILER ") " UTS_VERSION "\\n";
  把 LINUX_COMPILER 宏替换成字符串字面量，即可覆盖编译器构建号
  （无需更换 clang，因为构建号来自编译器二进制自身）

用法：
  python3 fake_version.py <内核源码根> [版本串]
"""
import sys, os, re

# 小米17 (pudding) 原厂 OS4.0.5.0.XPCCNXM 的真实值
OFFICIAL_VER = '6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k'
OFFICIAL_COMPILER = (
    'Android (14043575, +pgo, +bolt, +lto, +mlgo, based on r536225) '
    'clang version 19.0.1 '
    '(https://android.googlesource.com/toolchain/llvm-project '
    'b3a530ec6537146650e42be89f1089e9a3588460), LLD 19.0.1'
)


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    ver = sys.argv[2].strip() if len(sys.argv) > 2 else ''
    if not ver:
        ver = OFFICIAL_VER

    vf = os.path.join(root, 'init', 'version-timestamp.c')
    if not os.path.exists(vf):
        print(f'✗ 找不到 {vf}')
        return 1

    src = open(vf, encoding='utf-8', errors='replace').read()
    orig = src

    # 1) UTS_RELEASE -> 固定版本串
    src = re.sub(r'"Linux version "\s*UTS_RELEASE', f'"Linux version " "{ver}"', src)
    src = re.sub(r'release\s*=\s*UTS_RELEASE,', f'release = "{ver}",', src)

    # 2) LINUX_COMPILER -> 字面量（C 字符串自动拼接）
    src = re.sub(r'\bLINUX_COMPILER\b', f'"{OFFICIAL_COMPILER}"', src)

    if src == orig:
        print('⚠ 没有发生替换，请检查 version-timestamp.c 内容')
        return 1

    open(vf, 'w', encoding='utf-8').write(src)
    print(f'✓ UTS_RELEASE = {ver}')
    print(f'✓ LINUX_COMPILER 已伪装 ({len(OFFICIAL_COMPILER)} 字符)')
    return 0


if __name__ == '__main__':
    sys.exit(main())
