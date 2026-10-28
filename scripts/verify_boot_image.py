#!/usr/bin/env python3
"""
校验打包出来的 boot 镜像 —— 构建期的硬门槛，不通过就让 CI 失败。

对于"整分区模板"（96MB，小米17 pudding）：
  1. 输出大小必须等于模板大小
  2. header 4KB 必须与模板逐字节相同
  3. kernel 段以外的所有字节必须与模板逐字节相同（vbmeta / AVB 页脚不能被破坏）
  4. kernel 段里的 gzip 解出来，md5 必须等于输入的 Image
  5. 必须还能找到 AVB0（vbmeta）和 AVBf（AVB 页脚）
  6. 若给了 kernel 段文件，长度必须正好等于模板的 kernel_size

用法:
    python3 verify_boot_image.py <模板> <输出镜像> <Image> [kernel_seg.bin]
"""
import sys, os, zlib, hashlib


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
    PAGE = 4096
    fail = []

    if len(tpl) > PAGE:                       # 整分区模板
        ks = int.from_bytes(tpl[8:12], 'little')
        print(f'模板 {len(tpl)} 字节, kernel 段 {ks}')
        if len(out) != len(tpl):
            fail.append(f'输出大小 {len(out)} != 模板 {len(tpl)}')
        if out[:PAGE] != tpl[:PAGE]:
            fail.append('header 4KB 被改动')
        if out[PAGE + ks:] != tpl[PAGE + ks:]:
            fail.append('kernel 段以外被改动（vbmeta / AVB 页脚被破坏）')
        d = zlib.decompressobj(31)
        got = d.decompress(out[PAGE:PAGE + ks])
        if md5b(got) != md5b(img):
            fail.append(f'kernel 段里的内核 md5 不符 (got {md5b(got[:0]) or md5b(got)})')
        avb0 = out.find(b'AVB0')
        avbf = out.find(b'AVBf')
        if avb0 < 0 or avbf < 0:
            fail.append('缺 vbmeta(AVB0) 或 AVB 页脚(AVBf)')
        if seg_p:
            if os.path.getsize(seg_p) != ks:
                fail.append(f'kernel 段文件长度 {os.path.getsize(seg_p)} != {ks}')
        print(f'  vbmeta AVB0 @ {hex(avb0)}, AVB 页脚 @ {hex(avbf)}, 内核 md5 {md5b(got)}')
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
