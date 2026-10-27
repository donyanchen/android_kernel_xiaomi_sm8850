#!/usr/bin/env python3
"""
伪装内核版本串，使 /proc/version 与原厂完全一致

原理（v2 —— 单点源头修改）：
  ACK 6.12 的版本串由三处共同决定：

  1) include/generated/utsrelease.h      -> UTS_RELEASE
        内核构建时由 scripts/setlocalversion 生成
  2) init/version-timestamp.c            -> 定义 UTS_VERSION 宏
        #define UTS_VERSION "#1 SMP PREEMPT <编译日期>"
  3) 上面两个宏被 init/version-timestamp.c 的 linux_banner[] 与
     init/version.c 的 init_uts_ns.name 引用

  旧做法是在消费端（linux_banner / init_uts_ns）逐个替换宏，
  **容易漏掉一处**，导致内核里出现两条内容不同的 "Linux version ..." 字符串。
  kptools 按 kallsyms_names 反查 banner 位置，一旦两条 banner 长度不同，
  符号表基准就错位 1 字节，kpatch 的 hook 全部挂错 -> KPM 静默失效。

  v2 改为在**定义端**修改：
    - 直接把 init/version-timestamp.c 里的 UTS_VERSION 宏值改掉
    - 直接把 init/version.c / version-timestamp.c 里的 UTS_RELEASE 用法改掉
    - LINUX_COMPILER 仍按消费端替换（它没有集中的宏定义）
  这样 linux_banner 与 init_uts_ns.name 都引用同一个字面量，
  编译后内核里只会有一份完整的 "Linux version ..." 文本。

用法：
  python3 fake_version.py <内核源码根> [版本串|@文件]
"""
import sys
import os
import re
import subprocess


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


def write_if_changed(path, new, tag):
    old = open(path, encoding='utf-8', errors='replace').read()
    if old == new:
        print(f'⚠ {tag}: {path} 未发生变化')
        return False
    open(path, 'w', encoding='utf-8').write(new)
    print(f'✓ {tag}: {path} 已修改')
    return True


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
    if not uts_version:
        uts_version = OFFICIAL_UTS_VERSION

    changed = 0

    # ---------------------------------------------------------------
    # STEP 1: init/version-timestamp.c
    #   这里定义了 UTS_VERSION 宏，也是 linux_banner[] 所在。
    #   把 UTS_VERSION 的**定义**改成字面量，后面所有引用自动统一。
    #   ACK 6.12 里大致是：
    #       #define UTS_VERSION "#1 SMP PREEMPT " __DATE__ " " __TIME__
    #       const char linux_banner[] =
    #           "Linux version " UTS_RELEASE " (" LINUX_COMPILE_BY "@"
    #           LINUX_COMPILE_HOST ") (" LINUX_COMPILER ") " UTS_VERSION "\n";
    # ---------------------------------------------------------------
    vf = os.path.join(root, 'init', 'version-timestamp.c')
    if os.path.exists(vf):
        src = open(vf, encoding='utf-8', errors='replace').read()
        orig = src

        # 1a) 重定义 UTS_VERSION 宏 —— 关键改动
        pat_uts_define = re.compile(
            r'^[ \t]*#[ \t]*define[ \t]+UTS_VERSION[ \t]+.*$',
            re.MULTILINE)
        new_define = f'#define UTS_VERSION "{uts_version}"'
        if pat_uts_define.search(src):
            src = pat_uts_define.sub(new_define, src, count=1)
            print(f'  · UTS_VERSION 宏已重定义')
        else:
            # 宏可能不在这个文件里，退化为替换使用处
            print(f'  ! 未找到 UTS_VERSION 宏定义，退化为替换使用处')

        # 1b) 兜底：把 linux_banner 里残留的 UTS_VERSION / UTS_RELEASE 也换掉
        src = re.sub(r'"Linux version "\s*UTS_RELEASE',
                     f'"Linux version " "{ver}"', src)
        src = re.sub(r'\brelease\s*=\s*UTS_RELEASE,', f'release = "{ver}",', src)
        # 只替换"宏引用"形式，避免破坏刚写的 #define 行
        src = re.sub(r'(?<!define\s)\bUTS_VERSION\b(?!\s*")',
                     f'"{uts_version}"', src)
        src = re.sub(r'\bLINUX_COMPILER\b', f'"{OFFICIAL_COMPILER}"', src)

        # 修回被误伤的 #define 行
        src = re.sub(r'^([ \t]*#[ \t]*define[ \t]+UTS_VERSION[ \t]+)"+',
                     r'\1"', src, flags=re.MULTILINE)

        if write_if_changed(vf, src, 'version-timestamp.c'):
            changed += 1
    else:
        print(f'⚠ 找不到 {vf}')

    # ---------------------------------------------------------------
    # STEP 2: init/version.c
    #   init_uts_ns.name 的 .release / .version 在这里。
    #   统一改成字面量，与 linux_banner 完全一致。
    # ---------------------------------------------------------------
    vc = os.path.join(root, 'init', 'version.c')
    if os.path.exists(vc):
        src = open(vc, encoding='utf-8', errors='replace').read()
        src = re.sub(r'\brelease\s*=\s*UTS_RELEASE,',
                     f'release = "{ver}",', src)
        src = re.sub(r'\bversion\s*=\s*UTS_VERSION,',
                     f'version = "{uts_version}",', src)
        src = re.sub(r'\bLINUX_COMPILER\b', f'"{OFFICIAL_COMPILER}"', src)
        if write_if_changed(vc, src, 'version.c'):
            changed += 1
    else:
        print(f'⚠ 找不到 {vc}')

    # ---------------------------------------------------------------
    # STEP 3: include/generated/utsrelease.h
    #   有些 ACK 分支这里直接写死 UTS_RELEASE。
    # ---------------------------------------------------------------
    ur = os.path.join(root, 'include', 'generated', 'utsrelease.h')
    if os.path.exists(ur):
        src = open(ur, encoding='utf-8', errors='replace').read()
        new = re.sub(r'^[ \t]*#[ \t]*define[ \t]+UTS_RELEASE[ \t]+.*$',
                     f'#define UTS_RELEASE "{ver}"', src, flags=re.MULTILINE)
        if new != src:
            if write_if_changed(ur, new, 'utsrelease.h'):
                changed += 1
    else:
        print(f'  · 无 {ur}（由构建过程生成，跳过）')

    if not changed:
        print('✗ 没有文件被修改，请检查内核源码结构')
        return 1

    print()
    print(f'✓ UTS_RELEASE       = {ver}')
    print(f'✓ LINUX_COMPILER    已伪装（{len(OFFICIAL_COMPILER)} 字符）')
    print(f'✓ UTS_VERSION       = {uts_version}')
    print()
    print('  注意：本版在**宏定义端**统一，内核里应只出现一条完整 banner。')
    return 0


if __name__ == '__main__':
    sys.exit(main())
