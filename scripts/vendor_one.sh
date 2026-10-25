#!/usr/bin/env bash
# 下载一个依赖，切成 <90MB 的块提交进仓库。
#
# 用法： vendor_one.sh <名字> <版本> <块大小MB> <URL>
# 产物： vendor/<名字>/<名字>-<版本>.tar.gz.part-NN
#        vendor/<名字>/manifest.json
set -euo pipefail

NAME="${1:?名字}"
VER="${2:?版本}"
CHUNK_MB="${3:-90}"
URL="${4:?URL}"

CHUNK=$(( CHUNK_MB * 1024 * 1024 ))
DEST="vendor/${NAME}"
TMP="/tmp/vendor_${NAME}"

echo "===== ${NAME} (${VER}) ====="
echo "URL: ${URL}"

if [ -f "${DEST}/manifest.json" ]; then
  OLD=$(python3 -c "import json;print(json.load(open('${DEST}/manifest.json')).get('version',''))" 2>/dev/null || echo "")
  if [ "$OLD" = "$VER" ]; then
    echo "✓ 已是 ${VER}，跳过"
    exit 0
  fi
  echo "旧版本 ${OLD}，重新入库"
  rm -rf "${DEST}"
fi

mkdir -p "${TMP}"
echo "--- 下载"
curl -L --retry 3 --retry-delay 5 -o "${TMP}/src.tar.gz" "${URL}"
ls -lh "${TMP}/src.tar.gz"

echo "--- 切块 (${CHUNK_MB} MB)"
rm -rf "${DEST}" && mkdir -p "${DEST}"
cd "${TMP}"
split -b "${CHUNK}" -d -a 3 src.tar.gz part-
COUNT=$(ls part-* | wc -l)
echo "共 ${COUNT} 块"
for f in part-*; do
  mv "${f}" "${OLDPWD}/${DEST}/${NAME}-${VER}.tar.gz.${f}"
done
cd "${OLDPWD}"

echo "--- 生成清单"
python3 "${GITHUB_WORKSPACE}/scripts/gen_vendor_manifest.py" "${DEST}" "${VER}"
rm -rf "${TMP}"

echo "--- 提交"
git add "${DEST}"
if git diff --cached --quiet; then
  echo "无变化"
else
  git commit -m "vendor: ${NAME} ${VER}（$(ls ${DEST}/*.part-* | wc -l) 块，$(du -sh ${DEST} | cut -f1)）"
  git push
  echo "✓ 已提交"
fi
