#!/usr/bin/env python3
"""
修复 SukiSU builtin 分支在 6.12 上的 LSM API 不兼容

问题：
  drivers/kernelsu/hook/lsm_hook.c:194
    security_add_hooks(ksu_hooks, ARRAY_SIZE(ksu_hooks), "ksu");
  6.12 起第三个参数是 const struct lsm_id *，
  传字符串报 -Wincompatible-pointer-types（-Werror 下直接失败）。

做法：
  在文件作用域加一个 static const struct lsm_id，
  调用处改传它的地址。用 LINUX_VERSION_CODE 保护，低版本保持原样。

用法：
  python3 fix_ksu_lsm_612.py <内核源码根>
"""
import sys, os

CALL_OLD = '    security_add_hooks(ksu_hooks, ARRAY_SIZE(ksu_hooks), "ksu");'
CALL_NEW = '''#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
    security_add_hooks(ksu_hooks, ARRAY_SIZE(ksu_hooks), &ksu_lsmid);
#else
    security_add_hooks(ksu_hooks, ARRAY_SIZE(ksu_hooks), "ksu");
#endif'''

DECL = '''
/* PUDDING: 6.12 起 security_add_hooks 需要 struct lsm_id */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
static const struct lsm_id ksu_lsmid = { .name = "ksu", .id = 0 };
#endif
'''


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    p = os.path.join(root, 'drivers/kernelsu/hook/lsm_hook.c')
    if not os.path.exists(p):
        print(f'✗ 找不到 {p}')
        return 1

    src = open(p, encoding='utf-8', errors='replace').read()
    if 'ksu_lsmid' in src:
        print('✓ 已打过 LSM 补丁，跳过')
        return 0
    if CALL_OLD not in src:
        print('⚠ 未匹配到 security_add_hooks 调用，可能已适配')
        return 0

    src = src.replace(CALL_OLD, CALL_NEW, 1)

    # 在 ksu_lsm_hook_init 定义前插入声明
    anchor = 'void __init ksu_lsm_hook_init(void)'
    if anchor not in src:
        # 退化：放到文件末尾之前
        src = src + DECL
    else:
        src = src.replace(anchor, DECL + '\n' + anchor, 1)

    open(p, 'w', encoding='utf-8').write(src)
    chk = open(p, encoding='utf-8').read()
    ok = 'ksu_lsmid' in chk and '&ksu_lsmid' in chk
    print('✓ LSM 接口已适配 6.12' if ok else '⚠ 补丁结果异常')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
