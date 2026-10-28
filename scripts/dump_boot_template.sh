#!/system/bin/sh
#
# 导出当前 boot 分区，作为 CI 打包用的"整分区模板"
#
# 什么时候要跑：手机 OTA / 刷回官方固件之后（boot 分区布局可能变了）。
# 平时内核天天更新**不用**跑 —— 模板只是分区骨架（header + kernel 段占位 +
# vbmeta + AVB 页脚），每次构建都会把新编出来的 Image 塞进它的 kernel 段。
#
# 用法（root）：
#   sh dump_boot_template.sh
# 产物：
#   /sdcard/Download/boot_template_pudding.img(.gz)
# 然后把它上传成 pudding-private 仓库 Release(deps) 里的
#   boot_template_pudding.img.gz（同名覆盖即可），CI 下次构建自动用新的。
#
set -e

DEV=$(getprop ro.product.device)
[ -z "$DEV" ] && DEV=pudding
SLOT=$(getprop ro.boot.slot_suffix)
[ -z "$SLOT" ] && SLOT=_b
BLK="/dev/block/by-name/boot${SLOT}"
OUT="/sdcard/Download/boot_template_${DEV}.img"

echo "设备: $DEV  槽位: $SLOT  分区: $BLK"
[ -e "$BLK" ] || { echo "✗ 找不到 $BLK"; exit 1; }

dd if="$BLK" of="$OUT" bs=4096
SZ=$(stat -c %s "$OUT")
KS=$(od -An -tu4 -j8 -N4 "$OUT" | tr -d ' ')
echo "导出: $OUT  $SZ 字节  kernel 段 $KS 字节"

if command -v gzip >/dev/null 2>&1; then
    gzip -9 -c "$OUT" > "$OUT.gz"
    echo "压缩: $OUT.gz  $(stat -c %s "$OUT.gz") 字节"
else
    echo "（本机无 gzip，直接上传 .img）"
fi

echo
echo "下一步：把 boot_template_${DEV}.img.gz 上传到"
echo "  https://github.com/donyanchen/pudding-private/releases/tag/deps"
echo "  资产名 boot_template_${DEV}.img.gz（同名覆盖）"
