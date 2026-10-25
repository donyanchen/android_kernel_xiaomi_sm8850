#!/usr/bin/env python3
"""
生成桩函数（v2）：
  · 头文件里已有声明的符号 → 直接复用原型，避免 conflicting types
  · 其余 → 反汇编推断参数
  · 变参函数 → 显式 ... 声明
"""
import json, os, re, subprocess, collections

V = '/var/minis/workspace/cq/v'
OUT = '/var/minis/workspace/cq/xiaomi-stubs'
ACK = '/var/minis/workspace/cq/acksrc/include'
os.makedirs(OUT, exist_ok=True)

stubs = sorted(set(json.load(open(f'{V}/stub_v3.json'))))

# 排除：头文件里已声明为变量/函数，且内核本体已定义但未导出
# 硬定义会 duplicate symbol，签名不符会 conflicting types
EXCLUDE = {
    'cpu_scale', 'kernel_cpustat', 'ksoftirqd', 'softnet_data',
    'param_ops_int', 'param_ops_long', 'param_ops_uint',
    'param_ops_ullong', 'param_ops_ulong',
    'phy_read', 'phy_write', 'get_random_u8', 'get_random_u16',
    'get_random_u32', 'get_dmabuf_debugfs_data',
}
before = len(stubs)
stubs = [s for s in stubs if s not in EXCLUDE]
print(f'排除 {before - len(stubs)} 个已定义符号')
pmap = json.load(open(f'{V}/call_params_v2.json'))
types = json.load(open(f'{V}/miss_types.json'))
objs = set(types['obj']) & set(stubs)

print(f'桩符号: {len(stubs)}  其中变量 {len(objs)}')

# ---------- 从头文件提取完整原型 ----------
def collect_prototypes():
    """返回 {symbol: 完整声明字符串(不含分号)}"""
    proto = {}
    files = subprocess.run(['rg', '-l', '-t', 'c', '-g', '*.h',
                            r'\b[A-Za-z_][A-Za-z0-9_]*\s*\(', ACK],
                           capture_output=True, text=True).stdout.split('\n')
    want = set(stubs)
    for p in files:
        if not p:
            continue
        try:
            txt = open(p, errors='replace').read()
        except Exception:
            continue
        txt = re.sub(r'/\*.*?\*/', ' ', txt, flags=re.S)
        txt = re.sub(r'//[^\n]*', ' ', txt)
        for m in re.finditer(r'([A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)\s*\(([^;{)]*)\)\s*;',
                             txt, re.S):
            name = m.group(2)
            if name in want and name not in proto:
                ret = ' '.join(m.group(1).split())
                args = ' '.join(m.group(3).split())
                # 排除预处理残留、函数指针、typedef
                if '#' in ret or '#' in args:
                    continue
                if '(' in args or 'typedef' in ret:
                    continue
                if ret in ('', 'extern'):
                    continue
                proto[name] = f'{ret} {name}({args})' if args.strip() and args.strip() != 'void' \
                              else f'{ret} {name}(void)'
    return proto

print('扫描头文件原型 ...', flush=True)
PROTO = collect_prototypes()
hit = [s for s in stubs if s in PROTO]
print(f'  匹配到头文件原型: {len(hit)}')

# ---------- 内核已定义但未导出的符号 ----------
print('扫描常规定义 ...', flush=True)
_out = subprocess.run(['rg', '-n', '--no-heading', '-t', 'c', '-g', '*.c',
                       r'^[A-Za-z_][A-Za-z0-9_ \t\*]*\b([A-Za-z_][A-Za-z0-9_]*)\s*\(',
                       '/var/minis/workspace/cq/acksrc'],
                      capture_output=True, text=True).stdout
DEFINED = set()
for _l in _out.split('\n'):
    _m = re.match(r'[^:]+:\d+:(.*)', _l)
    if not _m:
        continue
    _t = _m.group(1)
    if _t.strip().startswith(('*', '/*', '//')):
        continue
    _mm = re.search(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(', _t)
    if _mm:
        DEFINED.add(_mm.group(1))
print(f'  内核已有定义: {len(DEFINED)}')

export_only = [s for s in stubs if s in PROTO]
skip_noproto = [s for s in stubs if s in DEFINED and s not in PROTO]
print(f'  可只加导出(有原型): {len(export_only)}')
print(f'  已定义但无原型(跳过): {len(skip_noproto)} {skip_noproto[:8]}')

stubs = [s for s in stubs if s not in PROTO]  # 有原型的全部只加导出

# ---------- 变参 ----------
VARARGS = {
    '__mca_log_err':   ('int', 'const char *fmt, const char *func, int line, ...'),
    '__mca_log_info':  ('int', 'const char *fmt, const char *func, int line, ...'),
    '__mca_log_debug': ('int', 'const char *fmt, const char *func, int line, ...'),
    'ipc_log_string':  ('void', 'void *ctxt, const char *fmt, ...'),
    'mca_log_str':     ('int', 'const char *fmt, ...'),
    '_dev_err':        ('void', 'const struct device *dev, const char *fmt, ...'),
    '_dev_warn':       ('void', 'const struct device *dev, const char *fmt, ...'),
    '_dev_info':       ('void', 'const struct device *dev, const char *fmt, ...'),
    '_dev_dbg':        ('void', 'const struct device *dev, const char *fmt, ...'),
    '_dev_notice':     ('void', 'const struct device *dev, const char *fmt, ...'),
    '_dev_crit':       ('void', 'const struct device *dev, const char *fmt, ...'),
}


def ret_type_of(sym, info):
    c = sym.lstrip('_')
    if sym.startswith('_dev_') and sym.endswith(('err', 'warn', 'info', 'dbg', 'notice', 'crit')):
        return 'void'
    if re.search(r'_(is|has|check)_', c) or c.startswith(('is_', 'has_')):
        return 'bool'
    if re.search(r'_(free|release|destroy|remove|unregister|exit|disable|'
                 r'cancel|stop|close|clear|reset|drop|put|deinit|dump)$', c):
        return 'void'
    if re.search(r'^(get_|_get_)|_alloc$|_create$|_find$', c):
        return 'void *'
    return 'int'


def body_for(ret):
    """按返回类型生成函数体；处理 __cold/__init 等属性前缀"""
    r = ret.strip()
    # 去掉属性宏
    for attr in ('__cold', '__init', '__exit', '__always_inline', 'inline',
                 'static', 'const', 'noinline', '__maybe_unused'):
        r = r.replace(attr, ' ')
    r = ' '.join(r.split())

    if r.endswith('void') and '*' not in r:
        return '/* no-op */'
    if r.endswith('bool'):
        return 'return false;'
    if '*' in r:
        return 'return NULL;'
    return 'return 0;'


lines = []
w = lines.append
w('// SPDX-License-Identifier: GPL-2.0')
w('/*')
w(' * 自动生成：ABI 兼容桩函数')
w(' *')
w(' * 策略：')
w(' *   1. 头文件已声明 → 复用原型（避免 conflicting types）')
w(' *   2. 其余 → 反汇编推断参数个数')
w(' *   3. 变量 → 给出真实定义而非函数桩')
w(' */')
w('#include <linux/module.h>')
w('#include <linux/types.h>')
w('#include <linux/kernel.h>')
w('#include <linux/errno.h>')
w('#include <linux/device.h>')
w('#include <linux/kobject.h>')
w('#include <linux/soc/qcom/qmi.h>')
w('#include <linux/dma-direction.h>')
w('#include <linux/dma-mapping.h>')
w('')

nf = nv = nproto = 0

# ---- 已有定义，仅补导出 ----
if export_only:
    w('/* ===== 内核已有定义，此处仅补充导出 ===== */')
    w('')
    for sym in sorted(export_only):
        _d = PROTO[sym]
        if not _d.startswith('extern '):
            _d = 'extern ' + _d
        w(f'{_d};')
        w(f'EXPORT_SYMBOL({sym});')
        w('')

for sym in stubs:
    if sym in objs:
        if sym.endswith('_ei'):
            w(f'struct qmi_elem_info {sym}[1];')
        elif sym.endswith('_kobject'):
            w(f'struct kobject {sym};')
        elif sym in ('slimbus_bus', 'soundwire_type'):
            w(f'struct bus_type {sym};')
        elif sym.endswith('_header'):
            w(f'const unsigned char {sym}[8] = {{0}};')
        elif re.search(r'_(level|ok|count|state|id)$', sym):
            w(f'int {sym};')
        else:
            w(f'void *{sym};')
        w(f'EXPORT_SYMBOL({sym});')
        w('')
        nv += 1
        continue

    if sym in PROTO:
        decl = PROTO[sym]
        ret = decl.split('(')[0].rsplit(None, 1)[0].strip()
        w(decl)
        w('{')
        w(f'\t{body_for(ret)}')
        w('}')
        w(f'EXPORT_SYMBOL({sym});')
        w('')
        nproto += 1
        continue

    if sym in VARARGS:
        ret, args = VARARGS[sym]
        w(f'{ret} {sym}({args})')
        w('{')
        w(f'\t{body_for(ret)}')
        w('}')
        w(f'EXPORT_SYMBOL({sym});')
        w('')
        nf += 1
        continue

    info = pmap.get(sym)
    n = info['nargs'] if info else 1
    ret = ret_type_of(sym, info)
    args = ', '.join(f'void *a{i}' for i in range(max(n, 0))) or 'void'
    w(f'{ret} {sym}({args})')
    w('{')
    w(f'\t{body_for(ret)}')
    w('}')
    w(f'EXPORT_SYMBOL({sym});')
    w('')
    nf += 1

content = '\n'.join(lines)
open(f'{OUT}/xiaomi_stubs.c', 'w').write(content)
print(f'用头文件原型: {nproto}')
print(f'推断签名:     {nf}')
print(f'变量定义:     {nv}')
print(f'合计:         {nproto + nf + nv}')
print(f'大小:         {len(content)} 字节')
