#!/usr/bin/env python3
"""
从设备 kheaders 和 ACK 源码中提取 struct 定义，逐个比对成员列表

只关心会影响 CRC 的：struct/union 的成员名与顺序
"""
import re, os, sys, json, collections

DEV = '/var/minis/workspace/cq/v/kh'
ACK = '/var/minis/workspace/cq/v/ack_tree'

def strip_comments(text):
    text = re.sub(r'/\*.*?\*/', ' ', text, flags=re.S)
    text = re.sub(r'//[^\n]*', ' ', text)
    return text

def extract_structs(path):
    """从单个头文件提取 struct/union 定义"""
    try:
        raw = open(path, errors='replace').read()
    except Exception:
        return {}
    txt = strip_comments(raw)
    # 找到 struct XXX { ... }; 形式
    out = {}
    i = 0
    n = len(txt)
    pat = re.compile(r'\b(struct|union)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\{')
    for m in pat.finditer(txt):
        kind, name = m.group(1), m.group(2)
        start = m.end()
        depth = 1
        j = start
        while j < n and depth > 0:
            c = txt[j]
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
            j += 1
        body = txt[start:j-1]
        if depth != 0:
            continue
        # 提取成员名：形如 "type name;"
        members = []
        for seg in body.split(';'):
            seg = ' '.join(seg.split())
            if not seg:
                continue
            # 处理位域 type name : width
            mm = re.search(r'([A-Za-z_][A-Za-z0-9_]*)\s*(?::\s*\d+)?$', seg)
            if mm:
                nm = mm.group(1)
                if nm not in ('struct', 'union', 'enum', 'const', 'unsigned',
                              'signed', 'void', 'char', 'int', 'long', 'short',
                              'volatile', '__attribute__'):
                    members.append(nm)
        if members:
            out[name] = members
    return out

dev_structs = {}
for dirpath, _, files in os.walk(DEV):
    for fn in files:
        if not fn.endswith('.h'):
            continue
        p = os.path.join(dirpath, fn)
        rel = os.path.relpath(p, DEV)
        for k, v in extract_structs(p).items():
            dev_structs.setdefault(k, (rel, v))

ack_structs = {}
for dirpath, _, files in os.walk(ACK):
    for fn in files:
        if not fn.endswith('.h'):
            continue
        p = os.path.join(dirpath, fn)
        rel = os.path.relpath(p, ACK)
        for k, v in extract_structs(p).items():
            ack_structs.setdefault(k, (rel, v))

print('设备 struct/union 数:', len(dev_structs))
print('ACK  struct/union 数:', len(ack_structs))
common = set(dev_structs) & set(ack_structs)
print('共有:', len(common))

diff = []
for name in sorted(common):
    dl, dm = dev_structs[name]
    al, am = ack_structs[name]
    if dm != am:
        only_dev = [m for m in dm if m not in am]
        only_ack = [m for m in am if m not in dm]
        diff.append((name, dl, only_dev, only_ack))

print('成员列表不同:', len(diff))
print()
for name, loc, od, oa in diff[:40]:
    print(f'  {name}  ({loc})')
    if od:
        print(f'     设备多: {od[:8]}')
    if oa:
        print(f'     ACK多 : {oa[:8]}')

json.dump([{'name': n, 'loc': l, 'dev_only': od, 'ack_only': oa}
           for n, l, od, oa in diff],
          open('/var/minis/workspace/cq/v/struct_diff.json', 'w'), ensure_ascii=False, indent=1)
print(f'\n已写入 struct_diff.json（{len(diff)} 项）')
