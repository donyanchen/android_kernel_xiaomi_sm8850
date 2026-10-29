#!/system/bin/sh
#
# 手机端刷内核 —— 只替换 boot 分区里的 kernel 段，vbmeta / AVB 页脚一个字节都不动。
#
# 背景：这些机型的 boot 分区是 [4KB header + kernel 段][vbmeta][零填充][AVB 页脚]，
#       段偏移固定。任何 magiskboot / AnyKernel3 重打包都会改写 kernel 段长度、
#       把 vbmeta 挪位置，刷完必定卡第一屏（刷的时候不报错，校验发生在引导器里）。
#       本脚本不解析、不重打包，只做 dd。
#
# 安全措施（不要删）：
#   1. 刷之前把原分区整份备份到 /sdcard/Download（手机端唯一能回退的东西）
#   2. 槽位取不到就退出，不猜 —— 宁可什么都不做，也不要写错槽
#   3. 写之前校验载荷的编码与分区里现有的一致（gzip / 裸 Image）
#   4. 写完回读校验，不一致就报错
#
# 用法（root 执行）：
#   1) 下载 kernel_seg_<dev>.bin.gz 并解压
#   2) sh flash_ondevice.sh /sdcard/Download/kernel_seg_<dev>.bin
#   3) 重启
#
set -e

SEG="$1"
if [ -z "$SEG" ] || [ ! -f "$SEG" ]; then
    echo "用法: sh $0 <kernel_seg.bin>"
    exit 1
fi

# ---- 槽位：取不到就退出，绝不猜 ----
SLOT=$(getprop ro.boot.slot_suffix)
if [ -z "$SLOT" ]; then
    echo "✗ 读不到 ro.boot.slot_suffix，无法确定刷哪个槽位，已放弃（不猜）"
    echo "  手动指定：sh $0 <kernel_seg.bin> <_a|_b>"
    exit 1
fi
if [ -n "$2" ]; then
    case "$2" in
        _a|_b) SLOT="$2" ;;
        *) echo "✗ 槽位只能是 _a 或 _b"; exit 1 ;;
    esac
fi

BLK="/dev/block/by-name/boot${SLOT}"
TMP=/data/local/tmp/_boot_splice.img
STAMP=$(date +%Y%m%d-%H%M%S)
BACKUP="/sdcard/Download/boot_backup_${SLOT}_${STAMP}.img"

[ -e "$BLK" ] || { echo "✗ 找不到分区 $BLK"; exit 1; }

SZ=$(stat -c %s "$SEG")
echo "分区: $BLK   槽位: $SLOT   载荷: $SZ 字节"

# ---- 先备份原分区（手机端唯一的回退手段）----
echo "备份原分区 → $BACKUP"
dd if="$BLK" of="$BACKUP" bs=4096 2>/dev/null
BKSZ=$(stat -c %s "$BACKUP")
if [ "$BKSZ" -ne "$(stat -c %s "$BLK")" ]; then
    echo "✗ 备份大小异常（$BKSZ），放弃写入"
    exit 1
fi
echo "备份完成: $BACKUP"

# ---- 读出当前分区，确认 kernel 段长度与编码 ----
dd if="$BLK" of="$TMP" bs=4096 2>/dev/null
KS=$(od -An -tu4 -j8 -N4 "$TMP" | tr -d ' ')
echo "分区 kernel 段: $KS 字节 / 载荷: $SZ 字节"

if [ "$SZ" -ne "$KS" ]; then
    echo "✗ 载荷长度与分区 kernel 段不一致，拒绝写入"
    echo "  （这个载荷不是给本机 $SLOT 槽准备的）"
    exit 1
fi

# ---- 编码一致性：载荷头 4 字节必须与分区里现有 kernel 段一致 ----
CUR_HEAD=$(dd if="$TMP" bs=1 skip=4096 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n')
NEW_HEAD=$(od -An -tx1 -N4 "$SEG" | tr -d ' \n')
echo "分区内核段头: $CUR_HEAD   载荷头: $NEW_HEAD"
case "$CUR_HEAD" in
    1f8b*)
        case "$NEW_HEAD" in
            1f8b*) ;;
            *)
                echo "✗ 分区里是 gzip 内核，载荷不是 gzip（$NEW_HEAD），拒绝写入"
                exit 1
                ;;
        esac
        ;;
    *)
        # 裸 arm64 Image：magic 'ARMd' 在段内 +56 字节处
        CUR_ARM=$(dd if="$TMP" bs=1 skip=4152 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n')
        NEW_ARM=$(dd if="$SEG" bs=1 skip=56 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n')
        if [ "$CUR_ARM" != "41524d64" ]; then
            echo "✗ 分区 kernel 段既不是 gzip 也不是裸 arm64 Image，放弃"
            exit 1
        fi
        if [ "$NEW_ARM" != "41524d64" ]; then
            echo "✗ 分区里是裸 Image 内核，载荷不是裸 Image，拒绝写入"
            exit 1
        fi
        ;;
esac

# ---- 只覆盖 kernel 段 ----
dd if="$SEG" of="$TMP" bs=4096 seek=1 conv=notrunc 2>/dev/null
sync

echo "写回分区…"
dd if="$TMP" of="$BLK" bs=4096 2>/dev/null
sync

# ---- 回读校验 ----
CHK=$(dd if="$BLK" bs=4096 skip=1 2>/dev/null | head -c "$SZ" | md5sum | cut -d' ' -f1)
WANT=$(md5sum "$SEG" | cut -d' ' -f1)
if [ "$CHK" != "$WANT" ]; then
    echo "✗ 回读校验失败（分区 $CHK ≠ 载荷 $WANT）"
    echo "  用备份恢复：fastboot flash boot${SLOT} $BACKUP"
    exit 1
fi
echo "✓ 回读校验一致"

rm -f "$TMP"
echo
echo "完成，重启生效。"
echo "备份留在: $BACKUP（要回退：fastboot flash boot${SLOT} $BACKUP）"
