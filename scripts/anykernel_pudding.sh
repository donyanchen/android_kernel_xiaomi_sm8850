### AnyKernel3 Ramdisk Mod Script
## osm0sis @ xda-developers
## pudding 专用：只替换 kernel 段，vbmeta / AVB 一个字节都不动
##
## 与 scripts/flash_ondevice.sh 同一套逻辑，并额外加了三道保险：
##   1) 写前把原分区整份备份到 /sdcard/Download（手机端唯一能回退的东西）
##   2) 写前校验载荷编码与分区里现有 kernel 段一致（gzip / 裸 arm64 Image）
##   3) 写后回读校验，不一致就报错并提示用备份恢复
##
## ⚠ 不要用标准 AK3（走 magiskboot unpack/pack 的那种）：
##    重打包会把 kernel 段缩到只剩压缩后长度、并把 vbmeta 挪位，
##    刷完必卡第一屏（而且刷的时候不报错，校验发生在引导器里）。

### AnyKernel setup
properties() { '
kernel.string=Xiaomi 17 (pudding) Kernel 6.12.69 (kernel-seg splice)
do.devicecheck=1
do.modules=0
do.systemless=1
do.cleanup=1
do.cleanuponabort=0
device.name1=pudding
device.name2=canoe
device.name3=
device.name4=
device.name5=
supported.versions=
supported.patchlevels=
supported.vendorpatchlevels=
'; } # end properties

### AnyKernel install
## boot shell variables
# 注意：BLOCK / IS_SLOT_DEVICE 必须写，ak3-core 靠它解析出真正的 boot_<slot>；
# 缺了会在 source 阶段直接 abort "Unable to determine  partition"。
# IS_SLOT_DEVICE=1 时 ak3-core 会自动解析成当前活动槽的 boot_a / boot_b，
# 刷哪个槽不用自己猜。
BLOCK=/dev/block/by-name/boot;
IS_SLOT_DEVICE=1;
RAMDISK_COMPRESSION=auto;

. tools/ak3-core.sh;

# 不用 split_boot / write_boot：pudding 的 boot 分区是
# [header + kernel 段][vbmeta][零填充][AVB 尾]，三段偏移固定，
# magiskboot 重打包会缩 kernel 段并把 vbmeta 挪位 -> 刷完卡第一屏。
# 这里只做三次 dd，载荷 kernel_seg.bin 长度严格等于分区 kernel_size。

ui_print " ";
ui_print "  pudding 布局保护模式（只替换 kernel 段）";

DEV="$BLOCK";
TMP="$AKHOME/_boot_splice.img";
BACKUP="/sdcard/Download/boot_backup_$(date +%Y%m%d-%H%M%S).img";

ui_print "  分区: $DEV";

# ---- 1) 先备份原分区 ----
ui_print "  备份原分区 -> $BACKUP";
dd if="$DEV" of="$BACKUP" bs=4096 2>/dev/null;
if [ ! -s "$BACKUP" ]; then
  abort "  备份失败，放弃写入";
fi;
ui_print "  备份完成: $BACKUP";

dd if="$DEV" of="$TMP" bs=4096 2>/dev/null;

KS=$(od -An -tu4 -j8 -N4 "$TMP" | tr -d ' ');
SZ=$(stat -c %s "$AKHOME/kernel_seg.bin" 2>/dev/null);
ui_print "  kernel 段: $KS 字节 / 载荷: $SZ 字节";

if [ "$SZ" != "$KS" ]; then
  rm -f "$TMP";
  abort "  载荷长度与分区 kernel 段不一致，拒绝写入（模板和固件不匹配？）";
fi;

# ---- 2) 编码一致性：载荷头必须与分区里现有 kernel 段一致 ----
CUR_HEAD=$(dd if="$TMP" bs=1 skip=4096 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n');
NEW_HEAD=$(od -An -tx1 -N4 "$AKHOME/kernel_seg.bin" | tr -d ' \n');
ui_print "  分区内核段头: $CUR_HEAD   载荷头: $NEW_HEAD";
case "$CUR_HEAD" in
  1f8b*)
    case "$NEW_HEAD" in
      1f8b*) ;;
      *) rm -f "$TMP"; abort "  分区里是 gzip 内核，载荷不是 gzip，拒绝写入" ;;
    esac
    ;;
  *)
    CUR_ARM=$(dd if="$TMP" bs=1 skip=4152 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n');
    NEW_ARM=$(dd if="$AKHOME/kernel_seg.bin" bs=1 skip=56 count=4 2>/dev/null | od -An -tx1 | tr -d ' \n');
    if [ "$CUR_ARM" != "41524d64" ]; then
      rm -f "$TMP"; abort "  分区 kernel 段既不是 gzip 也不是裸 arm64 Image，放弃";
    fi;
    if [ "$NEW_ARM" != "41524d64" ]; then
      rm -f "$TMP"; abort "  分区里是裸 Image 内核，载荷不是裸 Image，拒绝写入";
    fi
    ;;
esac;

dd if="$AKHOME/kernel_seg.bin" of="$TMP" bs=4096 seek=1 conv=notrunc 2>/dev/null;
sync;

ui_print "  写回分区...";
dd if="$TMP" of="$DEV" bs=4096 2>/dev/null;
sync;

# ---- 3) 回读校验 ----
CHK=$(dd if="$DEV" bs=4096 skip=1 2>/dev/null | head -c "$SZ" | md5sum | cut -d' ' -f1);
WANT=$(md5sum "$AKHOME/kernel_seg.bin" | cut -d' ' -f1);
rm -f "$TMP";
if [ "$CHK" != "$WANT" ]; then
  abort "  回读校验失败（分区 $CHK != 载荷 $WANT），请用备份恢复: fastboot flash boot $BACKUP";
fi;
ui_print "  ✓ 回读校验一致";

ui_print " ";
ui_print "  完成！重启生效。";
ui_print "  备份留在: $BACKUP（回退: fastboot flash boot $BACKUP）";
## end boot install
