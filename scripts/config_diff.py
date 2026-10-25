#!/usr/bin/env python3
"""
对比设备内核配置与实际构建出的 .config

用法: python3 config_diff.py <基准配置> <.config> [--all]
"""
import sys, re

def load(p):
    d = {}
    for ln in open(p, errors='replace'):
        ln = ln.strip()
        m = re.match(r'^(CONFIG_[A-Z0-9_]+)=(.*)$', ln)
        if m:
            d[m.group(1)] = m.group(2)
            continue
        m = re.match(r'^# (CONFIG_[A-Z0-9_]+) is not set$', ln)
        if m:
            d[m.group(1)] = 'n'
    return d


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    base = load(sys.argv[1])
    cur = load(sys.argv[2])
    show_all = '--all' in sys.argv

    # 影响 ABI 的关键项（struct 布局相关）
    KEY = ('MODULE_SCMVERSION', 'RUST', 'CFI_CLANG', 'CFI_ICALL_NORMALIZE_INTEGERS',
           'DEBUG_INFO_BTF', 'DEBUG_INFO_BTF_MODULES', 'TRIM_UNUSED_KSYMS',
           'EXTENDED_MODVERSIONS', 'MODVERSIONS', 'NUMA', 'SMP', 'PREEMPT',
           'SWIOTLB', 'SWIOTLB_DYNAMIC', 'NET_NS', 'CFG80211', 'MAC80211',
           'SYSFS', 'GENERIC_BUG', 'KALLSYMS', 'TRACEPOINTS', 'TREE_SRCU',
           'BPF_EVENTS', 'JUMP_LABEL', 'TRACING', 'EVENT_TRACING',
           'FTRACE_MCOUNT_RECORD', 'KPROBES', 'LIVEPATCH', 'KUNIT',
           'MODULE_UNLOAD', 'DYNAMIC_DEBUG_CORE', 'CONSTRUCTORS',
           'FUNCTION_ERROR_INJECTION', 'STACKTRACE_BUILD_ID', 'ARCH_USES_CFI_TRAPS',
           'RANDSTRUCT', 'LTO', 'PAGE_SIZE', 'ARM64_4K', 'MITIGATION_ITS')

    print('基准 %d 项 / 实际 %d 项' % (len(base), len(cur)))
    print()

    missing = [k for k in base if k not in cur]
    extra = [k for k in cur if k not in base]
    changed = [k for k in base if k in cur and base[k] != cur[k]]

    print('=== ABI 关键项 ===')
    for k in KEY:
        c = 'CONFIG_' + k
        a = base.get(c, '<无>')
        b = cur.get(c, '<无>')
        if a != b:
            print('  ✗ %-34s 设备=%-10s 实际=%s' % (k, a, b))
    print('  （无输出表示全部一致）')
    print()

    print('=== 设备有、实际没有 (%d 项) ===' % len(missing))
    for k in missing[:60]:
        print('  %-46s =%s' % (k, base[k]))
    if len(missing) > 60:
        print('  ... 共 %d 项' % len(missing))
    print()

    print('=== 实际有、设备没有 (%d 项) ===' % len(extra))
    for k in extra[:40]:
        print('  %-46s =%s' % (k, cur[k]))
    print()

    print('=== 值不同 (%d 项) ===' % len(changed))
    for k in changed[:60]:
        print('  %-46s 设备=%-12s 实际=%s' % (k, base[k], cur[k]))
    if len(changed) > 60:
        print('  ... 共 %d 项' % len(changed))
    return 0


if __name__ == '__main__':
    sys.exit(main())
