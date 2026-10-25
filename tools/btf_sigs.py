#!/usr/bin/env python3
"""
从设备 BTF 提取函数签名 —— 用于生成桩函数
"""
import struct, sys, json

BTF = '/var/minis/workspace/cq/v/vmlinux.btf'
d = open(BTF, 'rb').read()
magic, ver, flags, hdr_len, type_off, type_len, str_off, str_len = \
    struct.unpack('<HBBIIIII', d[:24])
types_blk = d[hdr_len + type_off: hdr_len + type_off + type_len]
str_blk = d[hdr_len + str_off: hdr_len + str_off + str_len]

def s(off):
    if off >= len(str_blk):
        return '?'
    e = str_blk.find(b'\x00', off)
    return str_blk[off:e].decode(errors='replace')

# 解析所有类型，建立 id -> (kind, name, size_type, vlen, params)
types = {}
pos = 0
tid = 1
KIND = {1:'INT',2:'PTR',3:'ARRAY',4:'STRUCT',5:'UNION',6:'ENUM',7:'FWD',
        8:'TYPEDEF',9:'VOLATILE',10:'CONST',11:'RESTRICT',12:'FUNC',
        13:'FUNC_PROTO',14:'VAR',15:'DATASEC',16:'FLOAT',17:'DECL_TAG',
        18:'TYPE_TAG',19:'ENUM64'}
while pos < len(types_blk):
    name_off, info, size_type = struct.unpack('<III', types_blk[pos:pos+12])
    pos += 12
    vlen = info & 0xffff
    kind = (info >> 24) & 0x1f
    kflag = (info >> 31) & 1
    name = s(name_off)
    extra = []
    if kind == 1:          # INT
        pos += 4
    elif kind == 3:        # ARRAY
        pos += 12
    elif kind in (4, 5):   # STRUCT / UNION
        for _ in range(vlen):
            mo, mt, mofs = struct.unpack('<III', types_blk[pos:pos+12])
            pos += 12
            extra.append((s(mo), mt, mofs & 0xffffff))
    elif kind == 6:        # ENUM
        pos += 8 * vlen
    elif kind == 13:       # FUNC_PROTO
        for _ in range(vlen):
            no, t = struct.unpack('<II', types_blk[pos:pos+8])
            pos += 8
            extra.append((s(no), t))
        extra = {'params': extra, 'ret': size_type}
    elif kind == 14:       # VAR
        pos += 4
    elif kind == 15:       # DATASEC
        pos += 12 * vlen
    elif kind == 17:       # DECL_TAG
        pos += 4
    elif kind == 19:       # ENUM64
        pos += 12 * vlen
    types[tid] = {'kind': kind, 'name': name, 'st': size_type,
                  'vlen': vlen, 'extra': extra, 'kflag': kflag}
    tid += 1

print('解析类型总数:', len(types), file=sys.stderr)

def type_name(tid, depth=0):
    """把类型 id 还原成 C 类型字符串"""
    if tid == 0 or depth > 12:
        return 'void'
    t = types.get(tid)
    if not t:
        return 'void'
    k = t['kind']
    if k == 1:                                  # INT
        return t['name'] or 'int'
    if k == 2:                                  # PTR
        return type_name(t['st'], depth+1) + ' *'
    if k in (9, 10, 11, 18):                    # qualifiers / type_tag
        return type_name(t['st'], depth+1)
    if k == 8:                                  # TYPEDEF
        return t['name']
    if k == 7:                                  # FWD
        return 'struct ' + t['name']
    if k in (4, 5):
        return ('struct ' if k == 4 else 'union ') + t['name']
    if k == 6 or k == 19:
        return 'enum ' + (t['name'] or 'anon')
    if k == 13:                                 # FUNC_PROTO (函数指针)
        return 'void *'
    if k == 3:                                  # ARRAY
        return type_name(t['st'], depth+1) + '[]'
    return 'void'

# 收集 FUNC 及其签名
funcs = {}
for tid, t in types.items():
    if t['kind'] != 12:
        continue
    proto = types.get(t['st'])
    if not proto or proto['kind'] != 13:
        continue
    ret = type_name(proto['extra']['ret'])
    params = []
    for pname, ptype in proto['extra']['params']:
        params.append((type_name(ptype), pname))
    funcs[t['name']] = {'ret': ret, 'params': params}

print('有签名的函数:', len(funcs), file=sys.stderr)
json.dump(funcs, open('/var/minis/workspace/cq/v/btf_funcs.json', 'w'))
print('已写入 btf_funcs.json', file=sys.stderr)
