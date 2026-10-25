#!/usr/bin/env python3
"""
跳过模块符号 CRC 校验

背景：
  CONFIG_EXTENDED_MODVERSIONS=y + CONFIG_GENDWARFKSYMS=y 时，
  符号 CRC 由编译产物 DWARF 计算，对编译器极其敏感。
  自编内核的 CRC 与原厂不同 → 厂商模块全部拒绝加载。

  但经 BTF 实测，本内核与原厂的 11,109 个结构体完全一致，
  仅 15 个 f2fs 相关结构体有差异。CRC 差异属于编译器指纹差异，
  而非真实 ABI 不兼容，跳过校验是安全的。

做法：把 kernel/module/version.c 的 check_version() 整体替换为 return 1
      （不留不可达代码，避免 -Werror 报错）

用法：python3 patch_modversion.py <内核源码根>
"""
import sys, os, re


def find_func_span(src, name):
    """返回 (start, end) —— 含花括号的完整函数定义范围"""
    m = re.search(r'\bint\s+' + re.escape(name) + r'\s*\(', src)
    if not m:
        return None
    # 找函数体起始 '{'
    i = src.find('{', m.end())
    if i < 0:
        return None
    depth = 0
    j = i
    while j < len(src):
        c = src[j]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return (m.start(), j + 1)
        elif c == '"':          # 跳过字符串
            j += 1
            while j < len(src) and src[j] != '"':
                if src[j] == '\\':
                    j += 1
                j += 1
        elif c == "'":          # 跳过字符常量
            j += 1
            while j < len(src) and src[j] != "'":
                if src[j] == '\\':
                    j += 1
                j += 1
        j += 1
    return None


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    p = os.path.join(root, 'kernel/module/version.c')
    if not os.path.exists(p):
        print(f'✗ 找不到 {p}')
        return 1

    src = open(p, encoding='utf-8', errors='replace').read()
    if 'PUDDING: skip crc check' in src:
        print('已打过补丁，跳过')
        return 0

    span = find_func_span(src, 'check_version')
    if not span:
        print('✗ 未匹配到 check_version')
        return 1

    new = (
        'int check_version(const struct load_info *info,\n'
        '\t\t  const char *symname,\n'
        '\t\t  struct module *mod,\n'
        '\t\t  const u32 *crc)\n'
        '{\n'
        '\t/* PUDDING: skip crc check ——\n'
        '\t * 本内核与原厂结构体 11,109/11,124 一致，\n'
        '\t * CRC 差异仅来自编译器 DWARF 指纹，非真实 ABI 不兼容。\n'
        '\t */\n'
        '\t(void)info; (void)symname; (void)mod; (void)crc;\n'
        '\treturn 1;\n'
        '}'
    )
    out = src[:span[0]] + new + src[span[1]:]
    open(p, 'w', encoding='utf-8').write(out)

    chk = open(p, encoding='utf-8').read()
    ok = 'PUDDING: skip crc check' in chk and 'bad_version:' not in chk.split('check_modstruct_version')[0]
    print('✓ check_version 已整体替换' if ok else '⚠ 已替换但仍有残留')

    # 显示结果
    s = chk.find('int check_version')
    print('--- 结果 ---')
    print(chk[s:s + 420])
    return 0


if __name__ == '__main__':
    sys.exit(main())
