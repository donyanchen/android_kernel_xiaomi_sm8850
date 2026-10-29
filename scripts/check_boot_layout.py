#!/usr/bin/env python3
"""
校验 boot 模板的分区布局，和 configs/known_layouts.json 里记录的是否一致。

为什么要有这道闸门：OTA 之后 boot 分区的布局会变（kernel 段长度、编码、vbmeta 偏移
都可能不一样）。拿旧模板硬拼出来的镜像刷进去会卡第一屏 —— 而且刷的时候不报错，
因为校验发生在引导器里，不在刷机时。所以打包之前先对一下，对不上就不出包。

用法:
    python3 check_boot_layout.py <模板.img> <device> [known_layouts.json]
"""
import json
import struct
import sys
import zlib

PAGE = 4096
GZIP_MAGIC = b'\x1f\x8b'
ARM64_MAGIC = b'ARM\x64'
FDT_MAGIC = b'\xd0\x0d\xfe\xed'


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    tpl_p, dev = sys.argv[1:3]
    layouts_p = sys.argv[3] if len(sys.argv) > 3 else 'configs/known_layouts.json'

    data = open(tpl_p, 'rb').read()
    lay = json.load(open(layouts_p))
    want = lay.get(dev)
    if not want:
        print(f'::warning::known_layouts.json 里没有 {dev} 的记录，跳过布局校验')
        return 0

    ks = struct.unpack_from('<I', data, 8)[0]
    seg = data[PAGE:PAGE + ks]
    if seg[:2] == GZIP_MAGIC:
        enc = 'gzip'
    elif len(seg) > 60 and seg[56:60] == ARM64_MAGIC:
        enc = 'raw'
    else:
        enc = 'unknown'

    fdt_bytes = 0
    if enc == 'gzip':
        o = zlib.decompressobj(31)
        try:
            o.decompress(seg)
            if o.eof:
                gz_len = len(seg) - len(o.unused_data)
                tail = seg[gz_len:]
                if tail[:4] == FDT_MAGIC:
                    n = struct.unpack_from('>I', tail, 4)[0]
                    fdt_bytes = n if 8 <= n <= len(tail) else 0
        except zlib.error:
            pass

    avb0 = data.find(b'AVB0', PAGE + ks)
    avbf = data.rfind(b'AVBf')

    got = {
        'kernel_size': ks,
        'encoding': enc,
        'avb0_offset': avb0,
        'avbf_offset': avbf,
        'fdt_tail_bytes': fdt_bytes,
    }
    print(f'模板 {tpl_p}: {got}')

    fail = []
    for key in ('kernel_size', 'encoding', 'avb0_offset', 'avbf_offset', 'fdt_tail_bytes'):
        if key not in want:
            continue
        if got[key] != want[key]:
            fail.append(f'{key}: 模板是 {got[key]}，known_layouts.json 记的是 {want[key]}')
    if fail:
        print('::error::boot 模板布局与 known_layouts.json 不一致 —— 拒绝出包')
        for f in fail:
            print(f'::error::  {f}')
        print('::error::多半是拿错槽位了（活动槽 vs 非活动槽）或固件 OTA 后布局变了。')
        print('::error::修法：手机 root 跑 scripts/dump_boot_template.sh，'
              '按它打印的值更新 known_layouts.json 并重传模板。')
        return 1
    print('::notice::boot 模板布局与 known_layouts.json 一致')
    return 0


if __name__ == '__main__':
    sys.exit(main())
