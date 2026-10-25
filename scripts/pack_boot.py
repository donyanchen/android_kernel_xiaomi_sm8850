#!/usr/bin/env python3
"""
打包 Android boot.img（header v4，ramdisk_size=0）

header v4 结构（1584 字节）:
  0   magic[8] = "ANDROID!"
  8   kernel_size  (u32)
  12  ramdisk_size (u32)
  16  os_version   (u32)
  20  header_size  (u32) = 1584
  24  reserved[4]
  40  header_version (u32) = 4
  44  cmdline[1536]

用法:
  python3 pack_boot.py <header模板4KB> <Image> <输出>
"""
import sys, struct

PAGE = 4096


def load_template(path):
    d = bytearray(open(path, 'rb').read())
    assert d[:8] == b'ANDROID!', 'magic 不对'
    if len(d) < PAGE:
        d += b'\x00' * (PAGE - len(d))
    return d[:PAGE]


def pack(tpl_path, image_path, out_path):
    hdr = load_template(tpl_path)
    img = open(image_path, 'rb').read()

    hdr_size = struct.unpack('<I', hdr[20:24])[0]
    hdr_ver = struct.unpack('<I', hdr[40:44])[0]
    cmdline = hdr[44:1580].split(b'\x00')[0].decode(errors='replace')

    print('模板: header_size=%d version=%d' % (hdr_size, hdr_ver))
    print('cmdline: %s...' % cmdline[:70])
    print('新内核: %s 字节' % format(len(img), ','))

    struct.pack_into('<I', hdr, 8, len(img))
    struct.pack_into('<I', hdr, 12, 0)

    out = bytearray(hdr) + bytearray(img)
    pad = (-len(out)) % PAGE
    out += b'\x00' * pad

    open(out_path, 'wb').write(bytes(out))
    print('输出: %s  %s 字节' % (out_path, format(len(out), ',')))

    chk = open(out_path, 'rb').read()
    ks = struct.unpack('<I', chk[8:12])[0]
    rs = struct.unpack('<I', chk[12:16])[0]
    print('校验: kernel_size=%d ramdisk_size=%d magic=%s' % (ks, rs, chk[:8]))
    assert ks == len(img), 'kernel_size 不符'
    assert chk[PAGE:PAGE + len(img)] == img, '内核段不符'
    print('OK 结构自校验通过')
    return 0


if __name__ == '__main__':
    if len(sys.argv) < 4:
        print(__doc__)
        sys.exit(1)
    sys.exit(pack(sys.argv[1], sys.argv[2], sys.argv[3]))
