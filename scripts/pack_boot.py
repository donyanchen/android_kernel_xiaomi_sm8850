#!/usr/bin/env python3
"""
pack_boot.py —— 打包 Android boot 镜像（严格保持模板分区布局）

模板的 kernel 段有两种编码，本脚本按模板原样保留，只替换内核本体：

  ① gzip(Image) [+ 72B 空 FDT] + 零填充     —— 绝大多数机型（含 K90 当前固件）
  ② 裸 arm64 Image [+ DTB] + 零填充        —— 旧布局（如 K90 的非活动槽）

其余字节（4KB header / vbmeta / AVB 页脚 / FDT 或 DTB 尾）一个字节都不动。
模板是什么编码，输出就是什么编码：不会把裸 Image 换成 gzip，也不会反过来。

用法:
    python3 pack_boot.py <模板.img> <Image> <输出.img>
"""
import gzip
import hashlib
import io
import os
import struct
import sys
import zlib

PAGE = 4096
FDT_MAGIC = b'\xd0\x0d\xfe\xed'
ARM64_MAGIC = b'ARM\x64'
GZIP_MAGIC = b'\x1f\x8b'


def gz(data):
    buf = io.BytesIO()
    with gzip.GzipFile(fileobj=buf, mode='wb', compresslevel=9, mtime=0) as g:
        g.write(data)
    return buf.getvalue()


def fdt_len(blob):
    """FDT 总长度（大端 totalsize）。"""
    if len(blob) < 8 or blob[:4] != FDT_MAGIC:
        return 0
    total = struct.unpack_from('>I', blob, 4)[0]
    return total if 8 <= total <= len(blob) else 0


def analyze_template(tpl):
    """解析模板 kernel 段布局。

    返回 dict：
        ksize     模板 kernel 段长度（header 里的 kernel_size）
        encoding  'gzip' / 'raw'
        suffix    内核本体之后必须原样保留的字节（72B 空 FDT 或 DTB）
        image_len 模板里内核本体占多少字节（仅用于打印）
    """
    ksize = struct.unpack('<I', bytes(tpl[8:12]))[0]
    seg = bytes(tpl[PAGE:PAGE + ksize])

    if seg[:2] == GZIP_MAGIC:
        o = zlib.decompressobj(31)
        try:
            o.decompress(seg)
        except zlib.error as e:
            raise SystemExit(f'✗ 模板 kernel 段的 gzip 流损坏: {e}')
        if not o.eof:
            raise SystemExit('✗ 模板 kernel 段的 gzip 流不完整（缺 CRC/长度尾）')
        gz_len = len(seg) - len(o.unused_data)
        tail = seg[gz_len:]
        suffix = b''
        if tail[:4] == FDT_MAGIC:
            n = fdt_len(tail)
            suffix = tail[:n] if n else tail[:72]
        return {'ksize': ksize, 'encoding': 'gzip', 'suffix': suffix, 'image_len': gz_len}

    if seg[56:60] == ARM64_MAGIC:
        size = struct.unpack_from('<Q', seg, 16)[0]
        if not (0 < size <= len(seg)):
            d = seg.find(FDT_MAGIC)
            size = d if d > 0 else len(seg)
        suffix = b''
        d = seg.find(FDT_MAGIC, size)
        if d == size:
            n = fdt_len(seg[d:])
            suffix = seg[d:d + n] if n else b''
        return {'ksize': ksize, 'encoding': 'raw', 'suffix': suffix, 'image_len': size}

    raise SystemExit('✗ 模板 kernel 段既不是 gzip 也不是裸 arm64 Image —— 模板选错了（多半是取了非活动槽）')


def pack(tpl_path, image_path, out_path):
    tpl = bytearray(open(tpl_path, 'rb').read())
    img = open(image_path, 'rb').read()
    assert bytes(tpl[:8]) == b'ANDROID!', '模板 magic 不对'

    if len(tpl) <= PAGE:
        # 老用法：4KB header 模板（无内嵌 vbmeta 的机型）
        hdr = bytearray(tpl) + bytes(PAGE - len(tpl))
        print('模板: 4KB header（无内嵌 vbmeta 的机型）')
        struct.pack_into('<I', hdr, 8, len(img))
        struct.pack_into('<I', hdr, 12, 0)
        tpl = bytearray(hdr) + bytearray(img)
        tpl += b'\x00' * ((-len(tpl)) % PAGE)
        open(out_path, 'wb').write(tpl)
        print(f'输出: {out_path}  {len(tpl)} 字节  md5={hashlib.md5(bytes(tpl)).hexdigest()}')
        return 0

    info = analyze_template(tpl)
    ksize = info['ksize']
    suffix = info['suffix']
    print(f'模板: 整分区镜像 {len(tpl)} 字节, kernel 段 {ksize} 字节')
    print(f'  模板 kernel 段编码: {info["encoding"]}（内核本体 {info["image_len"]} 字节'
          + (f', 尾部 {len(suffix)} 字节 FDT/DTB）' if suffix else ', 无尾部）'))

    if info['encoding'] == 'gzip':
        payload = gz(img)
        print(f'  gzip 载荷 {len(payload)} 字节（压缩率 {len(payload)*100//max(len(img),1)}%）')
    else:
        payload = img
        print(f'  裸 Image 载荷 {len(payload)} 字节（保持模板的裸 Image 编码，不压缩）')

    body = payload + suffix
    if len(body) > ksize:
        raise SystemExit(
            f'✗ 载荷 {len(body)} > kernel 段 {ksize}，装不下，拒绝生成\n'
            f'  （{"gzip 后压不进这个段；该段只有 %d 字节" % ksize}）')
    body += b'\x00' * (ksize - len(body))

    tpl[PAGE:PAGE + ksize] = body

    avb0 = bytes(tpl).find(b'AVB0')
    avbf = bytes(tpl).find(b'AVBf')
    print(f'  vbmeta AVB0 @ {hex(avb0)}, AVB 页脚 @ {hex(avbf)}')
    assert avb0 > 0 and avbf > 0, '模板本身缺 vbmeta/AVB 页脚，换一颗能开机的模板'

    open(out_path, 'wb').write(bytes(tpl))

    # 回读校验：kernel 段必须能还原出输入的 Image
    chk = open(out_path, 'rb').read()
    seg = chk[PAGE:PAGE + ksize]
    if info['encoding'] == 'gzip':
        o = zlib.decompressobj(31)
        back = o.decompress(seg)
        if not o.eof:
            raise SystemExit('✗ 输出里的 gzip 流不完整')
        rest = seg[len(seg) - len(o.unused_data):]
    else:
        back = seg[:len(img)]
        rest = seg[len(img):]
    if suffix and not rest.startswith(suffix):
        raise SystemExit('✗ 输出里内核之后的 FDT/DTB 尾被改动')
    if not rest[len(suffix):].strip(b'\x00'):
        pass
    else:
        raise SystemExit('✗ 输出里内核之后的填充区不是全零')
    md5_in = hashlib.md5(img).hexdigest()
    md5_back = hashlib.md5(back).hexdigest()
    print(f'输出: {out_path}  {len(chk)} 字节  md5={hashlib.md5(chk).hexdigest()}')
    print(f'  内核回读一致: {md5_back == md5_in}  ({md5_back})')
    assert md5_back == md5_in, '内核段回读不一致'
    return 0


if __name__ == '__main__':
    if len(sys.argv) < 4:
        print(__doc__)
        sys.exit(1)
    sys.exit(pack(sys.argv[1], sys.argv[2], sys.argv[3]))
