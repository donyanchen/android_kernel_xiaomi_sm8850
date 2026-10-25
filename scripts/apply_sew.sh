#!/usr/bin/env bash
# Pudding Kernel — 小米优化移植包执行器
#
# 不直接跑上游 setup.sh（它的 builtin_zram 依赖新版 ACK 已删除的
# android/gki_aarch64_modules），这里只调用需要的函数：
#   sew_kernel_opt  —— mi_rmap / unfairmem / kshrink_slabd / unionpower /
#                      boottime / binder_sched_opt / ssg-iosched / OS4 移植
#   other_opt       —— f2fs 与 IO 相关优化
#   set_defconfig   —— 默认配置调整
set -uo pipefail

SEW_DIR="${1:-}"
if [ -z "$SEW_DIR" ] || [ ! -d "$SEW_DIR" ]; then
  echo "用法: $0 <移植包目录>" >&2
  exit 2
fi

export MODULE_DIR="$SEW_DIR"
export KERNEL_ROOT="${KERNEL_ROOT:?KERNEL_ROOT 未设置}"
export DEFCONFIG="${DEFCONFIG:-arch/arm64/configs/gki_defconfig}"
export CUSTOM_EXTERNAL_MODULE_STAGE="${CUSTOM_EXTERNAL_MODULE_STAGE:-after_patch}"

cd "$SEW_DIR" || exit 2

[ -f module.conf ] && source module.conf

# ---------------------------------------------------------------- 预处理
# 移植包按 Linux 5.15 编写，会向 mm.h / vmscan.h 注入 vendor hook 声明。
# 但 ACK android16-6.12 已经把其中 4 个上游合入了（小米自己提交的），
# 重复注入会导致 redefinition 编译错误。这里在应用前把对应的 sed 语句注释掉。
SEW_SH="$SEW_DIR/scripts/sew_opt.sh"
if [ -f "$SEW_SH" ]; then
  python3 - "$SEW_SH" <<'PYEOF2'
import sys
p = sys.argv[1]
existing = [
    "android_vh_get_page_wmark",
    "android_vh_alloc_pages_slowpath_start",
    "android_vh_direct_reclaim_end",
    "android_vh_throttle_direct_reclaim_bypass",
]
lines = open(p).read().split("\n")
out = []
skipped = 0
for ln in lines:
    is_inject = ("sed -i" in ln) and ("DECLARE_HOOK" in ln)
    hits = [h for h in existing if h in ln]
    if is_inject and hits:
        out.append("# [pudding] ACK 已含 " + hits[0] + "，跳过注入: " + ln.strip()[:60])
        skipped += 1
    else:
        out.append(ln)
open(p, "w").write("\n".join(out))
print(f"  跳过 {skipped} 条重复 vendor hook 注入")
PYEOF2
fi

source scripts/libabk.sh
source scripts/sew_opt.sh
source scripts/other_opt.sh
source scripts/set_defconfig.sh

abk_log "KERNEL_ROOT=$KERNEL_ROOT"
abk_log "DEFCONFIG=$DEFCONFIG"

fail=0
for fn in sew_kernel_opt other_opt set_defconfig; do
  if declare -f "$fn" >/dev/null; then
    abk_log "==> 执行 $fn"
    if ("$fn"); then
      abk_log "    $fn 完成"
    else
      abk_log "    $fn 失败（继续下一个）"
      fail=$((fail+1))
    fi
  else
    abk_log "==> 跳过 $fn（未定义）"
  fi
done

abk_log "全部结束，失败项: $fail"
exit 0
