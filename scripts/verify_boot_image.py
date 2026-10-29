#!/usr/bin/env python3
"""
校验打包出来的 boot 镜像 —— 构建期的硬门槛，不通过就让 CI 失败。

对于整分区模板（96MB）：
  1. 输出大小必须等于模板大小
  2. header 4KB 必须与模板逐字节相同
  3. kernel 段以外的所有字节必须与模板逐字节相同（vbmeta / AVB 页脚不能被破坏）
  4. kernel 段里的内核本体必须就是输入的 Image
     - gzip 模板：必须是完整 gzip 流（eof + CRC 都过），解压后 md5 == Image 的 md5
     - 裸 Image 模板：段首字节必须就是 Image
  5. 内核本体之后的 FDT/DTB 尾必须与模板一致，其后必须全零
  6. 必须还能找到 AVB0（vbmeta）和 AVBf（AVB 页脚）
  7. 若给了 kernel 段文件：长度必须等于模板 kernel_size，
     且内容必须与镜像里的 kernel 段逐字节相同（不只比长度）

用法:
    python3 verify_boot_image.py <模板> <输出镜像> <Image> [kernel_seg.bin]
"""
import hashlib
import os
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pack_boot import ARM64_MAGIC, FDT_MAGIC, PAGE, analyze_template, fdt_len  # noqa: E402


def md5b(b):
    return hashlib.md5(b).hexdigest()


def main():
    if len(sys.argv) < 4:
        print(__doc__)
        return 2
    tpl_p, out_p, img_p = sys.argv[1:4]
    seg_p = sys.argv[4] if len(sys.argv) > 4 else None

    tpl = open(tpl_p, 'rb').read()
    out = open(out_p, 'rb').read()
    img = open(img_p, 'rb').read()
    fail = []

    if len(tpl) > PAGE:                       # 整分区模板
        info = analyze_template(tpl)
        ks = info['ksize']
        suffix = info['suffix']
        print(f'模板 {len(tpl)} 字节, kernel 段 {ks}, 编码 {info["encoding"]}')

        if len(out) != len(tpl):
            fail.append(f'输出大小 {len(out)} != 模板 {len(tpl)}')
        if out[:PAGE] != tpl[:PAGE]:
            fail.append('header 4KB 被改动')
        if out[PAGE + ks:] != tpl[PAGE + ks:]:
            fail.append('kernel 段以外被改动（vbmeta / AVB 页脚被破坏）')

        seg = out[PAGE:PAGE + ks]
        if info['encoding'] == 'gzip':
            d = zlib.decompressobj(31)
            try:
                got = d.decompress(seg)
            except zlib.error as e:
                got = b''
                fail.append(f'kernel 段里的 gzip 流解压失败: {e}')
            if not d.eof:
                fail.append('kernel 段里的 gzip 流不完整（缺 CRC/长度尾）')
            rest = seg[len(seg) - len(d.unused_data):] if got else b''
        else:
            got = seg[:len(img)]
            rest = seg[len(img):]

        if md5b(got) != md5b(img):
            fail.append(f'kernel 段里的内核 md5 不符 (got {md5b(got)}, want {md5b(img)})')
        if suffix:
            if not rest.startswith(suffix):
                fail.append('kernel 段里的 FDT/DTB 尾被改动')
            else:
                pad = rest[len(suffix):]
                if pad.strip(b'\x00'):
                    fail.append('kernel 段里 FDT/DTB 之后不是全零填充')
        elif rest.strip(b'\x00'):
            fail.append('kernel 段里内核之后不是全零填充')

        avb0 = out.find(b'AVB0')
        avbf = out.find(b'AVBf')
        if avb0 < 0 or avbf < 0:
            fail.append('缺 vbmeta(AVB0) 或 AVB 页脚(AVBf)')
        print(f'  vbmeta AVB0 @ {hex(avb0)}, AVB 页脚 @ {hex(avbf)}, 内核 md5 {md5b(got)}')

        if seg_p:
            sz = os.path.getsize(seg_p)
            if sz != ks:
                fail.append(f'kernel 段文件长度 {sz} != {ks}')
            else:
                content = open(seg_p, 'rb').read()
                if content != seg:
                    fail.append(f'kernel 段文件内容与镜像里的 kernel 段不一致 '
                                f'(md5 {md5b(content)} != {md5b(seg)})')
    else:                                      # 4KB header 模板（无内嵌 vbmeta 的机型）
        print('模板为 4KB header（无内嵌 vbmeta 的机型），只校验内核段')
        if out[PAGE:PAGE + len(img)] != img:
            fail.append('内核段不符')

    if fail:
        for f in fail:
            print(f'::error::{f}')
        return 1
    print('::notice::boot 镜像布局校验通过')
    return 0


if __name__ == '__main__':
    sys.exit(main())
