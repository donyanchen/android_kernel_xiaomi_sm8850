#!/system/bin/sh
#
# 导出当前 boot 分区，作为 CI 打包用的"整分区模板"
#
# 什么时候要跑：手机 OTA / 刷回官方固件之后（boot 分区布局可能变了）。
# 平时内核天天更新**不用**跑 —— 模板只是分区骨架（header + kernel 段占位 +
# vbmeta + AVB 页脚），每次构建都会把新编出来的 Image 塞进它的 kernel 段。
#
# 关键：**导出的是活动槽**（ro.boot.slot_suffix）。两个槽位的布局可能不一样
# （红米K90 就是：活动槽 boot_a 是 gzip 内核段，非活动槽 boot_b 是裸 Image + 内嵌 DTB），
# 拿错槽位硬拼出来的镜像刷进去必砖。本脚本会顺手把另一个槽也看一眼并提醒。
#
# 用法（root）：
#   sh dump_boot_template.sh
# 产物：
#   /sdcard/Download/boot_template_<dev>.img(.gz)
# 然后把它上传成私有仓库 Release(deps) 里的
#   boot_template_<dev>.img.gz（同名覆盖即可），CI 下次构建自动用新的。
#
# 同时把下面打印的 "known_layouts.json" 片段更新到公开仓的 configs/known_layouts.json，
# CI 打包前会拿它做布局闸门。
#
set -e

DEV=$(getprop ro.product.device)
[ -z "$DEV" ] && DEV=pudding
SLOT=$(getprop ro.boot.slot_suffix)
if [ -z "$SLOT" ]; then
    echo "✗ 读不到 ro.boot.slot_suffix，无法确定导出哪个槽位"
    exit 1
fi
BLK="/dev/block/by-name/boot${SLOT}"
OTHER=$(getprop ro.boot.slot_suffix.other)
[ -z "$OTHER" ] && OTHER=$([ "$SLOT" = "_a" ] && echo "_b" || echo "_a")
OUT="/sdcard/Download/boot_template_${DEV}.img"

echo "设备: $DEV  活动槽: $SLOT  分区: $BLK"
[ -e "$BLK" ] || { echo "✗ 找不到 $BLK"; exit 1; }

dd if="$BLK" of="$OUT" bs=4096
SZ=$(stat -c %s "$OUT")
KS=$(od -An -tu4 -j8 -N4 "$OUT" | tr -d ' ')
HEAD=$(od -An -tx1 -j4096 -N4 "$OUT" | tr -d ' \n')
echo "导出: $OUT  $SZ 字节  kernel 段 $KS 字节  段首 $HEAD"

if command -v gzip >/dev/null 2>&1; then
    gzip -9 -c "$OUT" > "$OUT.gz"
    echo "压缩: $OUT.gz  $(stat -c %s "$OUT.gz") 字节"
else
    echo "（本机无 gzip，直接上传 .img）"
fi

# ---- 布局摘要：用来更新 known_layouts.json ----
AVB0=$(od -An -tx1 -v "$OUT" | tr -d ' \n' | grep -bo 41564230 | head -1 | cut -d: -f1)
AVBF=$(od -An -tx1 -v "$OUT" | tr -d ' \n' | grep -bo 41564266 | tail -1 | cut -d: -f1)
echo
echo "---- known_layouts.json 片段 ----"
echo "  \"$DEV\": {"
echo "    \"kernel_size\": $KS,"
case "$HEAD" in
    1f8b*) echo "    \"encoding\": \"gzip\"," ;;
    *) echo "    \"encoding\": \"raw\"," ;;
esac
echo "    \"avb0_offset\": ${AVB0:-0},"
echo "    \"avbf_offset\": ${AVBF:-0},"
echo "    \"fdt_tail_bytes\": 0"
echo "  }"

# ---- 另一个槽的布局不一样就提醒 ----
OBLK="/dev/block/by-name/boot${OTHER}"
if [ -e "$OBLK" ]; then
    OHEAD=$(dd if="$OBLK" bs=1 skip=4096 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n')
    OKS=$(dd if="$OBLK" bs=4 skip=2 count=1 2>/dev/null | od -An -tu4 | tr -d ' ')
    echo
    echo "另一个槽 $OTHER: kernel 段 $OKS 字节  段首 $OHEAD"
    if [ "$OHEAD" != "$HEAD" ] || [ "$OKS" != "$KS" ]; then
        echo "⚠ 两个槽的布局不一样！CI 模板必须用活动槽 $SLOT 的（也就是刚导出的这个）"
    fi
fi

echo
echo "下一步：把 boot_template_${DEV}.img.gz 上传到私有仓库 Release(deps)"
echo "  资产名 boot_template_${DEV}.img.gz（同名覆盖）"
