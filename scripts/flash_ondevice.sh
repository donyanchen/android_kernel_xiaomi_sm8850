#!/system/bin/sh
#
# 小米17 (pudding) 手机端刷内核 —— 只替换 boot 分区里 kernel 段的 gzip 载荷
#
# 背景：pudding 的 boot 分区是 [header + kernel 段 36,711,382][vbmeta @0x2304000]
#       [零填充][AVB 页脚 @末尾]，三段偏移固定。任何 magiskboot / AnyKernel3 重打包
#       都会改写 kernel 段长度、把 vbmeta 挪位置，刷完必定卡第一屏（刷的时候不报错，
#       因为校验发生在引导器里，不在刷机时）。
#
# 本脚本不解析、不重打包，只做三次 dd，vbmeta 和 AVB 页脚一个字节都不动。
#
# 用法（root 执行）：
#   1) 下载 kernel_seg_pudding.bin.gz 并解压
#   2) sh flash_ondevice.sh /sdcard/Download/kernel_seg_pudding.bin
#   3) 重启
#
set -e

SEG="$1"
if [ -z "$SEG" ] || [ ! -f "$SEG" ]; then
    echo "用法: sh $0 <kernel_seg.bin>"
    exit 1
fi

SLOT=$(getprop ro.boot.slot_suffix)
[ -z "$SLOT" ] && SLOT=_b
BLK="/dev/block/by-name/boot${SLOT}"
TMP=/data/local/tmp/_boot_splice.img

echo "分区: $BLK"
dd if="$BLK" of="$TMP" bs=4096 2>/dev/null

KS=$(od -An -tu4 -j8 -N4 "$TMP" | tr -d ' ')
SZ=$(stat -c %s "$SEG")
echo "kernel 段: $KS 字节 / 载荷: $SZ 字节"

if [ "$SZ" -ne "$KS" ]; then
    echo "✗ 载荷长度与分区 kernel 段不一致，拒绝写入"
    rm -f "$TMP"
    exit 1
fi

# 只覆盖 kernel 段（gzip + 空 FDT + 零填充，已经算好，长度正好 KS）
dd if="$SEG" of="$TMP" bs=4096 seek=1 conv=notrunc 2>/dev/null
sync

echo "写回分区…"
dd if="$TMP" of="$BLK" bs=4096 2>/dev/null
sync
rm -f "$TMP"
echo "完成，重启生效。"
