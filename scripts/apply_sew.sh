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
