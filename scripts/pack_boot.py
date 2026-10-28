#!/usr/bin/env python3
"""
pack_boot.py —— 打包 Android boot 镜像（保持模板分区布局）

【为什么重写】
小米17 (pudding) 的 boot 分区不是纯 boot.img，实测结构是：

    [4KB header + kernel 段][vbmeta @ 0x2304000][零填充][AVB 页脚 @ 末尾 64B]
     kernel 段 = gzip(Image) + 72B 空 FDT + 零填充，总长固定的 36,711,382

旧版脚本拼的是 `header + 裸 Image`，会把 vbmeta 段整段覆盖、AVB 页脚也一起丢掉，
刷进去必定卡第一屏（b81.img 就是这么废的）。AnyKernel3/magiskboot 重打包同理：
它把 kernel 段缩到 gzip 实际长度、把 vbmeta 挪到 0xfa4000，同样开不了机。

所以：**模板是什么布局，输出就是什么布局，只换 kernel 段里的 gzip 载荷。**

用法：
    python3 pack_boot.py <模板.img> <Image> <输出.img>

模板可以是：
  ① 96MB 整分区镜像（推荐，必须是一颗确认能开机的，如 boot_pudding_nokpm.img）
     -> 保持布局：gzip + 空 FDT + 零填充到模板 kernel_size，vbmeta/AVB 页脚原位不动
  ② 4KB header 文件（老用法，仅适用于没有内嵌 vbmeta 的机型）
     -> header + 裸 Image + 页对齐
"""
import sys, gzip, io, zlib, struct, hashlib

PAGE = 4096
FDT_MAGIC = b'\xd0\x0d\xfe\xed'


def gz(data):
    buf = io.BytesIO()
    with gzip.GzipFile(fileobj=buf, mode='wb', compresslevel=9, mtime=0) as g:
        g.write(data)
    return buf.getvalue()


def pack(tpl_path, image_path, out_path):
    tpl = bytearray(open(tpl_path, 'rb').read())
    img = open(image_path, 'rb').read()
    assert bytes(tpl[:8]) == b'ANDROID!', '模板 magic 不对'

    full_partition = len(tpl) > PAGE

    if full_partition:
        ksize = struct.unpack('<I', tpl[8:12])[0]
        print(f'模板: 整分区镜像 {len(tpl)} 字节, kernel 段 {ksize} 字节')

        payload = gz(img)
        # 模板 kernel 段里"紧随 gzip 流"的那个 72 字节空 FDT，原样带上。
        # 注意：有的机型模板里 kernel 段是裸 Image（未压缩，如 myron），此时没有 FDT，
        # 解压会抛异常——直接按"无尾"处理，不能让它把构建搞挂。
        tail = b''
        try:
            _o = zlib.decompressobj(31)
            _o.decompress(bytes(tpl[PAGE:PAGE + ksize]))
            tpl_gz_len = ksize - len(_o.unused_data)
            fdt = bytes(tpl[PAGE + tpl_gz_len:PAGE + tpl_gz_len + 72])
            if fdt[:4] == FDT_MAGIC:
                tail = fdt
            print(f'  模板 gzip {tpl_gz_len} 字节, 随后 FDT: {"有" if tail else "无"}')
        except zlib.error:
            print('  模板 kernel 段是裸 Image（未压缩），无 FDT 尾')
        body = payload + tail
        if len(body) > ksize:
            raise SystemExit(f'✗ 载荷 {len(body)} > kernel 段 {ksize}，压缩率变差，拒绝生成')
        body += b'\x00' * (ksize - len(body))
        print(f'  gzip 载荷 {len(payload)} 字节（压缩率 {len(payload)*100//len(img)}%）')

        tpl[PAGE:PAGE + ksize] = body

        # 完整性检查：vbmeta / AVB 页脚必须还在原位
        avb0 = bytes(tpl).find(b'AVB0')
        avbf = bytes(tpl).find(b'AVBf')
        print(f'  vbmeta AVB0 @ {hex(avb0)}, AVB 页脚 @ {hex(avbf)}')
        assert avb0 > 0 and avbf > 0, '模板本身缺 vbmeta/AVB 页脚，换一颗能开机的模板'
    else:
        hdr = bytearray(tpl) + bytes(PAGE - len(tpl))
        print('模板: 4KB header（无内嵌 vbmeta 的机型）')
        struct.pack_into('<I', hdr, 8, len(img))
        struct.pack_into('<I', hdr, 12, 0)
        tpl = bytearray(hdr) + bytearray(img)
        tpl += b'\x00' * ((-len(tpl)) % PAGE)

    open(out_path, 'wb').write(tpl)

    # 回读校验
    chk = open(out_path, 'rb').read()
    if full_partition:
        back = gzip.decompress(chk[PAGE:PAGE + len(gz(img))])
    else:
        back = chk[PAGE:PAGE + len(img)]
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
