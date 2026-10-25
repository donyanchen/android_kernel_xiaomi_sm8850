#!/usr/bin/env python3
"""解除 MODULE_SCMVERSION 对 LOCALVERSION_AUTO 的依赖"""
import sys, os, re
root = sys.argv[1] if len(sys.argv) > 1 else '.'
p = os.path.join(root, 'kernel/module/Kconfig')
if not os.path.exists(p):
    print('未找到', p); sys.exit(0)
s = open(p).read()
n = s
n = re.sub(r'(config MODULE_SCMVERSION\n\tbool "[^"]*"\n)\tdepends on LOCALVERSION_AUTO\n',
           r'\1', n)
if n != s:
    open(p, 'w').write(n)
    print('✓ 已解除 MODULE_SCMVERSION 的 LOCALVERSION_AUTO 依赖')
else:
    print('⚠ 未匹配到依赖行（可能已是无依赖）')
