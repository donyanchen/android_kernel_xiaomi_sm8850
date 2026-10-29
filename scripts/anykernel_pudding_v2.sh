### AnyKernel3 Ramdisk Mod Script
## osm0sis @ xda-developers
## pudding 专用：只替换 kernel 段，vbmeta / AVB 一个字节都不动
##
## v2：载荷现场生成（gzip + 补零到分区 kernel 段长度）。
## 这样才兼容 SukiSU 的「KPM 补丁模式」——管理器先把 kpimg 打进 Image，
## 这里再把**打过补丁的那个 Image** 压进段里；不会像固定载荷那样写到旧的段。
##
## 三道保险：
##   1) 写前把原分区整份备份到 /sdcard/Download
##   2) 写前校验：载荷长度 <= 分区 kernel 段，且编码都是 gzip
##   3) 写后回读校验，不一致就报错并提示用备份恢复

### AnyKernel setup
properties() { '
kernel.string=Xiaomi 17 (pudding) Kernel 6.12.69 kernel-seg splice v2
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
BLOCK=/dev/block/by-name/boot;
IS_SLOT_DEVICE=1;
RAMDISK_COMPRESSION=auto;

. tools/ak3-core.sh;

ui_print " ";
ui_print "  pudding 布局保护模式 v2（只换 kernel 段）";

DEV="$BLOCK";
TMP="$AKHOME/_boot_splice.img";
SEG="$AKHOME/_kernel_seg.bin";
BACKUP="/sdcard/Download/boot_backup_$(date +%Y%m%d-%H%M%S).img";
BB="$AKHOME/tools/busybox";
[ -x "$BB" ] || BB=busybox;

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
ui_print "  分区 kernel 段: $KS 字节";

# ---- 2) 现场把 Image 压成载荷 ----
if [ ! -f "$AKHOME/Image" ]; then
  rm -f "$TMP";
  abort "  找不到 Image";
fi;
ui_print "  压缩 Image（含 KPM 补丁，如果有）...";
$BB gzip -1 -c "$AKHOME/Image" > "$SEG" || { rm -f "$TMP" "$SEG"; abort "  gzip 失败"; }
SZ=$(stat -c %s "$SEG" 2>/dev/null);
ui_print "  压缩后: $SZ 字节 / 上限: $KS";

if [ -z "$SZ" ] || [ "$SZ" -gt "$KS" ]; then
  rm -f "$TMP" "$SEG";
  abort "  载荷长度超过分区 kernel 段，拒绝写入（$SZ > $KS）";
fi;

# 编码一致性：分区段是 gzip，载荷也必须是 gzip
CUR_HEAD=$(dd if="$TMP" bs=1 skip=4096 count=2 2>/dev/null | od -An -tx1 | tr -d ' \n');
NEW_HEAD=$(od -An -tx1 -N2 "$SEG" | tr -d ' \n');
ui_print "  分区段头: $CUR_HEAD   载荷头: $NEW_HEAD";
if [ "$CUR_HEAD" != "1f8b" ]; then
  rm -f "$TMP" "$SEG";
  abort "  分区 kernel 段不是 gzip，本包不适用（模板和固件不匹配）";
fi;
if [ "$NEW_HEAD" != "1f8b" ]; then
  rm -f "$TMP" "$SEG";
  abort "  载荷不是 gzip，拒绝写入";
fi;

# 补零到与分区 kernel 段等长
if ! $BB truncate -s "$KS" "$SEG" 2>/dev/null; then
  PAD=$((KS - SZ));
  dd if=/dev/zero bs=1 count="$PAD" >> "$SEG" 2>/dev/null;
fi;
WANT=$(md5sum "$SEG" | cut -d' ' -f1);

# ---- 3) 写入 + 回读校验 ----
dd if="$SEG" of="$TMP" bs=4096 seek=1 conv=notrunc 2>/dev/null;
sync;
ui_print "  写回分区...";
dd if="$TMP" of="$DEV" bs=4096 2>/dev/null;
sync;

CHK=$(dd if="$DEV" bs=4096 skip=1 2>/dev/null | head -c "$KS" | md5sum | cut -d' ' -f1);
rm -f "$TMP" "$SEG";
if [ "$CHK" != "$WANT" ]; then
  abort "  回读校验失败（分区 $CHK != 载荷 $WANT），请用备份恢复: fastboot flash boot $BACKUP";
fi;
ui_print "  ✓ 回读校验一致";

ui_print " ";
ui_print "  完成！重启生效。";
ui_print "  备份留在: $BACKUP（回退: fastboot flash boot $BACKUP）";
## end boot install
