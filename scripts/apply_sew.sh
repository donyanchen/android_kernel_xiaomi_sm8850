#!/usr/bin/env bash
# Pudding Kernel — 小米优化移植包执行器（6.12 适配版）
#
# 移植包原本针对 Linux 5.15 编写，部分模块在 6.12 上不兼容。
# 这里保留能编的模块，禁用会破坏编译的模块。
#
# 禁用原因（实测）：
#   add_kshrink_lruvecd   改 mm/vmscan.c，插入不存在的变量 list，
#                         并在 trace 结构里造成 duplicate member android_vendor_data1
#   add_mi_rmap_efficiency 同类问题，改 mm/vmscan.c 与 vmscan.h
#   add_os4port_sched     sew_qos_inherit.c 需要 union futex_key 的完整定义，
#                         6.12 的 futex.h 未导出该类型
#   opt_page_clear        自写 clear_page.S 的指令在 KVM hyp 上下文无法汇编
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

# --- 预处理：跳过与 ACK 已含 hook 冲突的注入 ---
SEW_SH="$SEW_DIR/scripts/sew_opt.sh"
if [ -f "$SEW_SH" ]; then
  python3 - "$SEW_SH" <<'PYEOF'
import sys
p = sys.argv[1]
existing = [
    "android_vh_get_page_wmark",
    "android_vh_alloc_pages_slowpath_start",
    "android_vh_direct_reclaim_end",
    "android_vh_throttle_direct_reclaim_bypass",
    "android_rvh_before_do_sched_yield",
    "android_vh_handle_failed_page_trylock_mglru",
]
lines = open(p).read().split("\n")
out, skipped = [], 0
for ln in lines:
    is_inject = ("sed -i" in ln) and (
        ("DECLARE_HOOK" in ln)
        or ("DECLARE_RESTRICTED_HOOK" in ln)
        or ("trace_android_" in ln)
    )
    hits = [h for h in existing if h in ln]
    if is_inject and hits:
        out.append("# [pudding] ACK 已含 " + hits[0] + "，跳过注入")
        skipped += 1
    else:
        out.append(ln)
open(p, "w").write("\n".join(out))
print(f"  跳过 {skipped} 条重复 vendor hook 注入")
PYEOF
fi

source scripts/libabk.sh
source scripts/sew_opt.sh
source scripts/other_opt.sh
source scripts/set_defconfig.sh

# --- 禁用与 6.12 不兼容的模块 ---
add_kshrink_lruvecd()   { abk_log "跳过 add_kshrink_lruvecd（vmscan.c 不兼容）"; }
add_mi_rmap_efficiency() { abk_log "跳过 add_mi_rmap_efficiency（vmscan.c 不兼容）"; }
add_os4port_sched()     { abk_log "跳过 add_os4port_sched（futex_key 类型不可见）"; }
opt_page_clear()        { abk_log "跳过 opt_page_clear（clear_page.S 在 KVM hyp 无法汇编）"; }
opt_trace_printk()      { abk_log "跳过 opt_trace_printk（6.12 bpf 无 BPF_FUNC_pr_debug）"; }

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
