#!/usr/bin/env python3
"""
跳过模块 vermagic 校验（用于 6.12.x 跨 sublevel 升级）

背景：
  厂商模块的 vermagic 是 6.12.69-android16-6-4k。
  升级到 6.12.96 后内核的 vermagic 变成 6.12.96-android16-6-4k，
  check_modinfo() 会拒绝加载并返回 -ENOEXEC。

  GKI 约定同一 KMI 代次（android16-6.12）内 ABI 稳定，
  因此跨 sublevel 只需放行 vermagic 字符串比较。

做法：
  kernel/module/main.c 的 check_modinfo() 中，
  把 vermagic 不符时的 return -ENOEXEC 改为仅告警。

用法：
  python3 patch_vermagic.py <内核源码根>
"""
import sys, os

OLD = '''	} else if (!same_magic(modmagic, vermagic, info->index.vers)) {
		pr_err("%s: version magic '%s' should be '%s'\\n",
		       info->name, modmagic, vermagic);
		return -ENOEXEC;
	}'''

NEW = '''	} else if (!same_magic(modmagic, vermagic, info->index.vers)) {
		/* PUDDING: allow vermagic mismatch across 6.12.x sublevels
		 * GKI 同一 KMI 代次内 ABI 保持稳定，仅字符串不同。
		 */
		pr_warn("%s: version magic '%s' should be '%s' -- ignored\\n",
			info->name, modmagic, vermagic);
	}'''


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    p = os.path.join(root, 'kernel/module/main.c')
    if not os.path.exists(p):
        print(f'✗ 找不到 {p}')
        return 1

    src = open(p, encoding='utf-8', errors='replace').read()
    if 'PUDDING: allow vermagic mismatch' in src:
        print('✓ 已打过 vermagic 补丁，跳过')
        return 0
    if OLD not in src:
        print('✗ 未匹配到 check_modinfo 的 vermagic 校验段')
        print('  可能源码版本不同，需人工确认')
        return 1

    src = src.replace(OLD, NEW, 1)
    open(p, 'w', encoding='utf-8').write(src)
    chk = open(p, encoding='utf-8').read()
    ok = 'PUDDING: allow vermagic mismatch' in chk and OLD not in chk
    print('✓ vermagic 校验已放行' if ok else '⚠ 替换结果异常')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
