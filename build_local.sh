#!/usr/bin/env bash
#
# 小米 17（pudding）GKI 内核 —— 本地/云主机一键构建
#
# 环境要求：
#   Ubuntu 22.04 / 24.04  x86_64
#   8 核以上，32 GB 内存，100 GB 可用磁盘
#
# 用法：
#   ./build_local.sh                 # 全流程
#   ./build_local.sh --skip-ccache   # 清 ccache 重建
#
# 产物：
#   out/Image                       内核镜像
#   out/vmlinux.symvers             符号表
#   out/.config                     最终配置
#
set -euo pipefail

REPO="donyanchen/android_kernel_xiaomi_sm8850"
RAW="https://raw.githubusercontent.com/${REPO}/main"
ACK_BRANCH="${ACK_BRANCH:-android16-6.12-2026-03}"
WORK="${WORK:-$PWD/pudding-build}"
CCACHE_DIR="${CCACHE_DIR:-$WORK/.ccache}"
JOBS="${JOBS:-$(nproc)}"

log() { printf '\n\033[1;36m==> %s\033[0m\n' "$*"; }

# ---------------------------------------------------------------- 依赖
install_deps() {
  log "检查依赖"
  local need=(git curl bison flex bc rsync ccache build-essential
              libssl-dev libelf-dev python3 pahole)
  local miss=()
  for p in "${need[@]}"; do
    dpkg -s "$p" >/dev/null 2>&1 || miss+=("$p")
  done
  if [ ${#miss[@]} -gt 0 ]; then
    log "安装缺失依赖: ${miss[*]}"
    sudo apt-get update -qq
    sudo apt-get install -y -qq "${miss[@]}"
  fi
  echo "pahole: $(pahole --version 2>/dev/null || echo 无)"
}

# ---------------------------------------------------------------- 同步仓库
fetch_repo() {
  log "同步仓库配置与脚本"
  mkdir -p "$WORK/repo"
  if [ -d "$WORK/repo/.git" ]; then
    git -C "$WORK/repo" pull --ff-only || true
  else
    git clone --depth=1 "https://github.com/${REPO}.git" "$WORK/repo"
  fi
}

# ---------------------------------------------------------------- 源码
prepare_ack() {
  if [ -f "$WORK/common/Makefile" ]; then
    log "ACK 源码已存在，跳过下载"
    return
  fi
  log "下载 ACK 源码 ($ACK_BRANCH)"
  mkdir -p "$WORK/common"
  local url="${MIRROR:-https://github.com/${REPO}/releases/download/deps/ack-common.tar.gz}"
  if ! curl -fL --retry 3 -o "$WORK/ack.tar.gz" "$url" 2>/dev/null; then
    url="https://android.googlesource.com/kernel/common/+archive/refs/heads/${ACK_BRANCH}.tar.gz"
    curl -L --retry 3 -o "$WORK/ack.tar.gz" "$url"
  fi
  tar xzf "$WORK/ack.tar.gz" -C "$WORK/common"
  rm -f "$WORK/ack.tar.gz"
  echo "文件数: $(find "$WORK/common" -type f | wc -l)"
}

# ---------------------------------------------------------------- 工具链
prepare_toolchain() {
  GC=https://android.googlesource.com/platform/prebuilts

  if [ ! -x "$WORK/clang/bin/clang" ]; then
    log "下载 clang r536225"
    curl -L --retry 3 -o "$WORK/clang.tar.gz" \
      "$GC/clang/host/linux-x86/+archive/refs/heads/main/clang-r536225.tar.gz"
    mkdir -p "$WORK/clang"
    tar xzf "$WORK/clang.tar.gz" -C "$WORK/clang"
    rm -f "$WORK/clang.tar.gz"
  fi
  "$WORK/clang/bin/clang" --version | head -2

  if [ ! -x "$WORK/rust/bin/rustc" ]; then
    log "下载 rust 1.82.0"
    curl -L --retry 3 -o "$WORK/rust.tar.gz" \
      "$GC/rust/+archive/refs/heads/main/linux-x86/1.82.0.tar.gz"
    mkdir -p "$WORK/rust"
    tar xzf "$WORK/rust.tar.gz" -C "$WORK/rust"
    rm -f "$WORK/rust.tar.gz"
  fi
  "$WORK/rust/bin/rustc" --version || true

  # bindgen：CONFIG_RUST / ASHMEM 必需，必须独立安装，不要依赖缓存
  if ! command -v bindgen >/dev/null 2>&1; then
    log "安装 bindgen（ASHMEM/RUST 必需）"
    if [ -x "$WORK/rust/bin/cargo" ]; then
      export PATH="$WORK/rust/bin:$PATH"
    fi
    cargo install --locked bindgen-cli 2>&1 | tail -5 || \
      pip3 install --break-system-packages bindgen-cli 2>/dev/null || \
      echo "⚠ bindgen 安装失败：CONFIG_RUST 会被丢弃，ASHMEM 会连带丢失"
  fi
  command -v bindgen && bindgen --version || echo "⚠ 无 bindgen"
}

# ---------------------------------------------------------------- SukiSU
integrate_sukisu() {
  log "集成 SukiSU（builtin 分支，自带 SUSFS 集成）"
  cd "$WORK/common"
  curl -LSs "https://raw.githubusercontent.com/donyanchen/SukiSU-Ultra/refs/heads/pudding/kernel/setup.sh" | bash -s pudding

  local uapi
  uapi=$(find . -maxdepth 3 -type d -name uapi | grep -i kernelsu | head -1)
  [ -z "$uapi" ] && uapi=$(find . -maxdepth 3 -type d -name uapi | head -1)
  mkdir -p drivers/kernelsu/uapi
  [ -n "$uapi" ] && cp -f "$uapi"/*.h drivers/kernelsu/uapi/ 2>/dev/null || true

  local n
  n=$(grep -c "config KSU_SUSFS" drivers/kernelsu/Kconfig 2>/dev/null || echo 0)
  echo "Kconfig 中 KSU_SUSFS 定义: $n 项（builtin 分支应为 19）"
}

# ---------------------------------------------------------------- 补丁
apply_patches() {
  log "应用兼容性与功能补丁"
  cd "$WORK/common"

  # 6.12 兼容：include 路径 + cb_mutex
  python3 "$WORK/repo/patches/fix_ksu_612.py" || true
  # 6.12 兼容：LSM security_add_hooks 需 struct lsm_id
  python3 "$WORK/repo/patches/fix_ksu_lsm_612.py" . || true
  # 跳过符号 CRC 校验
  python3 "$WORK/repo/scripts/patch_modversion.py" . || true
  # 放行 vermagic（跨 sublevel 时才生效）
  python3 "$WORK/repo/scripts/patch_vermagic.py" . || true
  # 解除 MODULE_SCMVERSION 对 LOCALVERSION_AUTO 的依赖
  python3 "$WORK/repo/scripts/patch_kconfig.py" . || true
  # 版本串对齐原厂
  python3 "$WORK/repo/scripts/fake_version.py" . "${DISP_VERSION:-}"
}

# ---------------------------------------------------------------- SUSFS
apply_susfs() {
  log "应用 SUSFS 内核补丁（50_）"
  cd "$WORK"
  rm -rf susfs4ksu
  if git clone --depth=1 -b oki-android16-6.12 \
       https://github.com/cctv18/susfs4oki.git susfs4ksu 2>&1 | tail -2; then
    cp susfs4ksu/kernel_patches/fs/* common/fs/ 2>/dev/null || true
    cp susfs4ksu/kernel_patches/include/linux/* common/include/linux/ 2>/dev/null || true
    local P="$PWD/susfs4ksu/kernel_patches/50_add_susfs_in_gki-android16-6.12.patch"
    if [ -f "$P" ] && (cd common && patch -p1 --dry-run -F3 < "$P" >/dev/null 2>&1); then
      (cd common && patch -p1 -F3 < "$P")
      echo "SUSFS 50_ 补丁成功"
      export SUSFS_OK=1
    else
      echo "⚠ SUSFS 50_ 补丁不适用"
    fi
  else
    echo "⚠ susfs4oki 克隆失败"
  fi
  cd "$WORK/common"
  python3 "$WORK/repo/scripts/patch_susfs_kconfig.py" . || true
}

# ---------------------------------------------------------------- 配置
assemble_config() {
  log "组装内核配置"
  cd "$WORK/common"
  local R="$WORK/repo/configs"

  cp "$R/pudding_full.defconfig" arch/arm64/configs/pudding_defconfig
  cat "$R/pudding_abi.fragment"  >> arch/arm64/configs/pudding_defconfig
  [ -f "$R/pudding_extra.config" ] && cat "$R/pudding_extra.config" >> arch/arm64/configs/pudding_defconfig

  # ABI 白名单（TRIM_UNUSED_KSYMS）
  [ -f "$R/abi_symbollist.raw" ] && cp "$R/abi_symbollist.raw" abi_symbollist.raw
  # MODULE_SIG_PROTECT 名单
  if [ -f "$R/protected_module_names_list" ]; then
    cp "$R/protected_module_names_list" protected_module_names_list
  else
    : > protected_module_names_list
  fi
  cp protected_module_names_list ../protected_module_names_list 2>/dev/null || true

  # SUSFS 配置
  if [ "${SUSFS_OK:-0}" = "1" ]; then
    for k in KSU_SUSFS KSU_SUSFS_HAS_MAGIC_MOUNT KSU_SUSFS_SUS_PATH \
             KSU_SUSFS_SUS_MOUNT KSU_SUSFS_AUTO_ADD_SUS_KSU_DEFAULT_MOUNT \
             KSU_SUSFS_AUTO_ADD_SUS_BIND_MOUNT KSU_SUSFS_SUS_KSTAT \
             KSU_SUSFS_TRY_UMOUNT KSU_SUSFS_AUTO_ADD_TRY_UMOUNT_FOR_BIND_MOUNT \
             KSU_SUSFS_SPOOF_UNAME KSU_SUSFS_ENABLE_LOG \
             KSU_SUSFS_HIDE_KSU_SUSFS_SYMBOLS; do
      echo "CONFIG_$k=y" >> arch/arm64/configs/pudding_defconfig
    done
  fi
  echo "defconfig 行数: $(wc -l < arch/arm64/configs/pudding_defconfig)"
}

# ---------------------------------------------------------------- 编译
build_kernel() {
  log "编译内核（-j$JOBS）"
  cd "$WORK/common"
  export PATH="$WORK/clang/bin:$WORK/build-tools/bin:$WORK/rust/bin:$PATH"
  export ARCH=arm64 LLVM=1
  export CC="ccache clang"
  export CCACHE_DIR CCACHE_COMPILERCHECK=none
  export KBUILD_BUILD_USER=kleaf
  export KBUILD_BUILD_HOST=build-host
  export KBUILD_BUILD_TIMESTAMP="Tue Sep  8 15:08:49 UTC 2026"
  export KCFLAGS="-Wno-error=visibility -Wno-error=logical-op-parentheses \
-Wno-error=implicit-function-declaration -Wno-error=unused-result"

  rm -f build.log
  make ARCH=arm64 pudding_defconfig > build.log 2>&1
  make ARCH=arm64 -j"$JOBS" Image >> build.log 2>&1 || {
    echo "✗ 编译失败，最后 40 行："
    tail -40 build.log
    exit 1
  }

  mkdir -p "$WORK/out"
  cp arch/arm64/boot/Image    "$WORK/out/Image"
  cp vmlinux.symvers          "$WORK/out/" 2>/dev/null || true
  cp .config                  "$WORK/out/"
  ls -lh "$WORK/out/Image"
}

# ---------------------------------------------------------------- 校验
verify() {
  log "校验产物"
  local IMG="$WORK/out/Image"
  echo "--- vermagic ---"
  strings -a "$IMG" | grep -E "^6\.12\..*SMP preempt" | head -1
  echo "--- 版本串 ---"
  strings -a "$IMG" | grep -m1 "Linux version 6\.12" | cut -c1-160
  echo "--- 关键 CONFIG ---"
  for k in TRIM_UNUSED_KSYMS EXTENDED_MODVERSIONS CFI_ICALL_NORMALIZE_INTEGERS \
           MODULE_SCMVERSION DEBUG_INFO_BTF_MODULES RUST ASHMEM; do
    printf "  %-34s %s\n" "$k" \
      "$(grep -E "^(CONFIG_${k}=|# CONFIG_${k} is not set)" "$WORK/out/.config" | head -1 || echo 未定义)"
  done
  echo "--- SUSFS ---"
  grep -c "^CONFIG_KSU_SUSFS" "$WORK/out/.config" 2>/dev/null || echo 0
  echo "--- 符号数 ---"
  wc -l < "$WORK/out/vmlinux.symvers" 2>/dev/null || echo "无 symvers"
}

# ---------------------------------------------------------------- 打包
pack_boot() {
  local HDR="${BOOT_HDR:-}"
  if [ -z "$HDR" ] || [ ! -f "$HDR" ]; then
    log "跳过打包（未提供 BOOT_HDR）"
    echo "  打包方法："
    echo "    adb shell su -c 'dd if=/dev/block/by-name/boot_b of=/sdcard/hdr.bin bs=4096 count=1'"
    echo "    adb pull /sdcard/hdr.bin hdr.bin"
    echo "    BOOT_HDR=hdr.bin $0"
    return
  fi
  log "打包 boot.img"
  python3 "$WORK/repo/scripts/pack_boot.py" "$HDR" "$WORK/out/Image" "$WORK/out/boot_pudding.img"
}

# ---------------------------------------------------------------- main
main() {
  [ "${1:-}" = "--skip-ccache" ] && rm -rf "$CCACHE_DIR"
  mkdir -p "$WORK"
  install_deps
  fetch_repo
  prepare_ack
  prepare_toolchain
  integrate_sukisu
  apply_patches
  apply_susfs
  assemble_config
  build_kernel
  verify
  pack_boot
  log "完成，产物在 $WORK/out"
}

main "$@"
