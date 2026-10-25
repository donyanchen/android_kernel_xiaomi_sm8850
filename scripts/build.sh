#!/usr/bin/env bash
# Pudding Kernel 本地构建脚本
#
# 用法：
#   ./scripts/build.sh              # 完整构建
#   ./scripts/build.sh --clean      # 清理后重建
#
# 依赖：curl tar make bc bison flex python3 cpio
# 磁盘：约 40 GB
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
WORK="${ROOT}/.work"
ACK_BRANCH="${ACK_BRANCH:-android16-6.12-2026-03}"
CLANG_VER="${CLANG_VER:-r536225}"
RUST_VER="${RUST_VER:-1.82.0}"
JOBS="${JOBS:-$(nproc)}"

GC="https://android.googlesource.com/platform/prebuilts"

log() { printf '\033[1;34m==>\033[0m %s\n' "$*"; }

if [[ "${1:-}" == "--clean" ]]; then
  log "清理 ${WORK}"
  rm -rf "${WORK}"
fi

mkdir -p "${WORK}"
cd "${WORK}"

# ---------------------------------------------------------------- ACK 源码
if [[ ! -d common/include ]]; then
  log "下载 ACK ${ACK_BRANCH}"
  curl -L --retry 3 -o ack.tar.gz \
    "https://android.googlesource.com/kernel/common/+archive/refs/heads/${ACK_BRANCH}.tar.gz"
  mkdir -p common
  tar xzf ack.tar.gz -C common
  rm -f ack.tar.gz
else
  log "ACK 源码已存在，跳过下载"
fi

# ---------------------------------------------------------------- 工具链
if [[ ! -x clang19/bin/clang ]]; then
  log "下载 clang ${CLANG_VER}"
  curl -L --retry 3 -o clang.tar.gz \
    "${GC}/clang/host/linux-x86/+archive/refs/heads/main/clang-${CLANG_VER}.tar.gz"
  mkdir -p clang19 && tar xzf clang.tar.gz -C clang19 && rm -f clang.tar.gz
fi

if [[ ! -x rust/bin/rustc ]]; then
  log "下载 rust ${RUST_VER}"
  curl -L --retry 3 -o rust.tar.gz \
    "${GC}/rust/+archive/refs/heads/main/linux-x86/${RUST_VER}.tar.gz"
  mkdir -p rust && tar xzf rust.tar.gz -C rust && rm -f rust.tar.gz
fi

export PATH="${WORK}/clang19/bin:${WORK}/rust/bin:${PATH}"

# ---------------------------------------------------------------- FinaSU
cd common
if [[ ! -d drivers/kernelsu ]]; then
  log "集成 FinaSU"
  curl -LSs "https://raw.githubusercontent.com/donyanchen/FinaSU/refs/heads/pudding/kernel/setup.sh" | bash -s pudding

  log "拷贝 uapi 头文件"
  UAPI_SRC=$(find . -maxdepth 3 -type d -name uapi | grep -i kernelsu | head -1 || true)
  if [[ -n "${UAPI_SRC}" ]]; then
    mkdir -p drivers/kernelsu/uapi
    cp -f "${UAPI_SRC}"/*.h drivers/kernelsu/uapi/ || true
  fi

  log "应用兼容性补丁"
  python3 "${ROOT}/patches/fix_ksu_612.py"
else
  log "FinaSU 已集成，跳过"
fi

# ---------------------------------------------------------------- 配置
log "生成配置"
sed -i '/^# Pudding Kernel 配置片段/,$d' arch/arm64/configs/gki_defconfig 2>/dev/null || true
sed -i '/^CONFIG_LOCALVERSION=/d' arch/arm64/configs/gki_defconfig
cat "${ROOT}/configs/pudding.fragment" >> arch/arm64/configs/gki_defconfig

# ---------------------------------------------------------------- 版本串
SHA=$(git -C "${ROOT}" rev-parse --short=12 HEAD 2>/dev/null || echo 000000000000)
DISP="6.12.69-android16-6-g${SHA}-abogki$(printf '%09d' 0)-4k"
VF=init/version-timestamp.c
sed -i "s|\"Linux version \" UTS_RELEASE|\"Linux version \" \"${DISP}\"|" "${VF}"
sed -i "s|release\t= UTS_RELEASE,|release\t= \"${DISP}\",|" "${VF}"
log "显示版本: ${DISP}"

# ---------------------------------------------------------------- 编译
log "编译（${JOBS} 线程）"
export ARCH=arm64 CC="ccache clang" LLVM=1
export KBUILD_BUILD_USER=kleaf
export KBUILD_BUILD_HOST=build-host
export KBUILD_BUILD_TIMESTAMP="2026-09-08 15:08:49 UTC"

make ARCH=arm64 gki_defconfig
make ARCH=arm64 -j"${JOBS}" Image

OUT="${ROOT}/out/Image"
mkdir -p "${ROOT}/out"
cp arch/arm64/boot/Image "${OUT}"

log "完成: ${OUT}"
log "vermagic: $(strings -a "${OUT}" | grep -m1 'SMP preempt' || true)"
