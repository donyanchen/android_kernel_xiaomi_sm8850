#!/usr/bin/env python3
"""
伪装内核版本串，使 /proc/version 与原厂完全一致

原理：
  1) init/version-timestamp.c 的 linux_banner
        "Linux version " UTS_RELEASE " (" LINUX_COMPILE_BY "@"
        LINUX_COMPILE_HOST ") (" LINUX_COMPILER ") " UTS_VERSION "\n";
  2) init/version.c 的 init_uts_ns.name
        .release = UTS_RELEASE, .version = UTS_VERSION

  把 UTS_RELEASE / LINUX_COMPILER / UTS_VERSION 三个宏都换成字面量，
  /proc/version 的每一项就都对齐原厂了：
      Linux version <release> (<by>@<host>) (<compiler>) #1 SMP PREEMPT <日期>

  注意：UTS_VERSION 里带编译日期，不换就会暴露真实的构建时间。

用法：
  python3 fake_version.py <内核源码根> [版本串|@文件]
"""
import sys, os, re

OFFICIAL_VER = '6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k'
OFFICIAL_COMPILER = (
    'Android (14043575, +pgo, +bolt, +lto, +mlgo, based on r536225) '
    'clang version 19.0.1 '
    '(https://android.googlesource.com/toolchain/llvm-project '
    'b3a530ec6537146650e42be89f1089e9a3588460), LLD 19.0.1'
)
# 兜底：pudding 原厂
OFFICIAL_UTS_VERSION = '#1 SMP PREEMPT Tue Sep  8 15:08:49 UTC 2026'


def read_proc_version(path):
    """从 uname.txt / /proc/version 提取 release 与 UTS_VERSION"""
    raw = open(path, 'rb').read()
    # 有些 uname.txt 是 gzip 存的
    if raw[:2] == b'\x1f\x8b':
        import gzip
        raw = gzip.decompress(raw)
    text = raw.decode('utf-8', 'replace')

    rel = uts = ''
    for line in text.splitlines():
        if 'Linux version' not in line:
            continue
        m = re.search(r'Linux version (\S+)', line)
        if m:
            rel = m.group(1)
        # UTS_VERSION 是编译器括号之后的那段：#N SMP PREEMPT <日期>
        m2 = re.search(r'\)\s*(#\S.*?)\s*$', line)
        if m2:
            uts = m2.group(1).strip()
        break
    return rel, uts


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    arg = sys.argv[2].strip() if len(sys.argv) > 2 else ''

    ver = arg
    uts_version = ''

    if arg.startswith('@'):
        path = arg[1:]
        try:
            ver, uts_version = read_proc_version(path)
            print(f'从 {path} 读取: release={ver}')
            print(f'                  uts_version={uts_version}')
        except Exception as e:
            print(f'⚠ 读取 {path} 失败: {e}')
            ver = ''

    if not ver:
        ver = OFFICIAL_VER
        uts_version = OFFICIAL_UTS_VERSION

    changed = 0

    # ---- 1) init/version-timestamp.c ----
    vf = os.path.join(root, 'init', 'version-timestamp.c')
    if os.path.exists(vf):
        src = orig = open(vf, encoding='utf-8', errors='replace').read()
        src = re.sub(r'"Linux version "\s*UTS_RELEASE',
                     f'"Linux version " "{ver}"', src)
        src = re.sub(r'release\s*=\s*UTS_RELEASE,', f'release = "{ver}",', src)
        src = re.sub(r'\bLINUX_COMPILER\b', f'"{OFFICIAL_COMPILER}"', src)
        if uts_version:
            src = re.sub(r'\bUTS_VERSION\b', f'"{uts_version}"', src)
        if src != orig:
            open(vf, 'w', encoding='utf-8').write(src)
            changed += 1
            print(f'✓ {vf} 已修改')
        else:
            print(f'⚠ {vf} 没有发生替换')

    # ---- 2) init/version.c（uts_namespace：release / version 在这里 ----
    vc = os.path.join(root, 'init', 'version.c')
    if os.path.exists(vc):
        src = orig = open(vc, encoding='utf-8', errors='replace').read()
        src = re.sub(r'release\s*=\s*UTS_RELEASE,', f'release = "{ver}",', src)
        src = re.sub(r'version\s*=\s*UTS_VERSION,', f'version = "{uts_version}",', src)
        src = re.sub(r'\bLINUX_COMPILER\b', f'"{OFFICIAL_COMPILER}"', src)
        if src != orig:
            open(vc, 'w', encoding='utf-8').write(src)
            changed += 1
            print(f'✓ {vc} 已修改')
        else:
            print(f'⚠ {vc} 没有发生替换（可能结构不同，非致命）')

    if not changed:
        print('✗ 两个文件都没改到，请检查内核源码结构')
        return 1

    print(f'✓ UTS_RELEASE    = {ver}')
    print(f'✓ LINUX_COMPILER 已伪装 ({len(OFFICIAL_COMPILER)} 字符)')
    if uts_version:
        print(f'✓ UTS_VERSION    = {uts_version}')
    else:
        print('⚠ UTS_VERSION 未提供，编译日期会暴露真实构建时间')
    return 0


if __name__ == '__main__':
    sys.exit(main())
