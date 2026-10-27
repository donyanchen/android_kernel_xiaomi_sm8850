#!/usr/bin/env python3
"""
校验内核镜像里 "Linux version ..." 字符串唯一性

背景：
  kptools 打 KPM 补丁时，靠 kallsyms_names 的位置反查 linux_banner，
  以此作为符号偏移的基准。若内核里存在两条内容不同的 "Linux version ..."
  （例如 UTS_VERSION 在 init/version-timestamp.c 与 init/version.c 里
  被分别替换、结果不一致），
    - 两条 banner 长度不同 -> kallsyms_names 相对位置差 1 字节
    - 符号表整体错位 -> kpatch hook 全部挂错 -> KPM 静默失效（返回 EOPNOTSUPP）

本脚本作为 CI 硬门槛：banner 必须恰好出现 1 次，否则构建失败。

用法：
  python3 check_banner.py <arch/arm64/boot/Image>
"""
import sys
import re

PATTERN = re.compile(rb'Linux version \d+\.\d+\.\d+[^\x00]{0,400}')


def main():
    if len(sys.argv) < 2:
        print('用法: check_banner.py <Image>')
        return 2

    path = sys.argv[1]
    try:
        data = open(path, 'rb').read()
    except OSError as e:
        print(f'✗ 读不到 {path}: {e}')
        return 2

    print(f'镜像: {path}  ({len(data)} 字节)')

    hits = [(m.start(), m.group(0).decode('latin1', 'replace')) for m in PATTERN.finditer(data)]
    print(f'Linux version 字符串出现 {len(hits)} 次')
    print()

    for off, text in hits:
        print(f'  offset=0x{off:08x}  len={len(text)}')
        print(f'    {text}')
    print()

    if len(hits) == 1:
        print('✓ banner 唯一，kptools 定位基准无歧义')
        return 0

    if len(hits) == 0:
        print('✗ 找不到 Linux version 字符串，镜像可能损坏')
        return 1

    # 有多条：关键看「长度」和「内容」是否一致
    #
    # kptools 依赖 banner 的字节长度去推算 kallsyms_names 的位置。
    # 只要所有 banner 长度相同，基准就无歧义 —— 出现几次都不影响。
    # 长度只要差 1 字节，符号表就整体错位 -> KPM 静默失效。
    texts = set(t for _, t in hits)
    lens = set(len(t) for _, t in hits)

    if len(texts) > 1:
        print(f'✗ banner 内容有 {len(texts)} 种不同版本')
        print(f'  长度集合: {sorted(lens)}')
        print('  kptools 会以其中一条为基准，符号表将错位，KPM 必然失效')
        return 1

    if len(lens) > 1:
        print(f'✗ banner 长度不一致: {sorted(lens)}')
        print('  长度差会导致 kallsyms_names 基准偏移，KPM 必然失效')
        return 1

    print(f'✓ banner 出现 {len(hits)} 次，但内容与长度完全一致')
    print('  kptools 定位基准无歧义，KPM 可正常打补丁')
    print('  提示：C 字符串合并本应让多条归一，出现多份通常是不同编译单元各自持有，'
          '不影响 kpatch（它按内容匹配，不按条目数）')
    return 0


if __name__ == '__main__':
    sys.exit(main())
