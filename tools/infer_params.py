#!/usr/bin/env python3
"""
批量反汇编 404 个 .ko，精确推断每个外部符号的参数个数

方法：
  · objdump -d -r 反汇编每个模块
  · 找所有 bl <sym> 指令
  · 向前回溯最多 40 条指令，记录 x0..x7 哪些被写入
  · 最大写入寄存器序号 + 1 = 参数个数
  · 多个调用点取众数
"""
import subprocess, re, os, sys, json, collections, glob

KO_DIR = '/var/minis/workspace/cq/ko'
OUT = '/var/minis/workspace/cq/v/call_params_full.json'

files = sorted(glob.glob(f'{KO_DIR}/*.ko'))
print(f'模块数: {len(files)}', file=sys.stderr)

pat = re.compile(r'^\s+([0-9a-f]+):\s+([0-9a-f]+)\s+(\S+)\s*(.*)$')
WRITE_RE = re.compile(
    r'^(?:mov|movz|movk|movn|adrp|adr|ldr|ldp|ldrb|ldrh|ldrsb|ldrsh|ldrsw|'
    r'ldur|ldurb|ldurh|ldursb|ldursh|ldursw|ldar|ldaxr|ldxr|'
    r'orr|add|sub|adds|subs|and|ands|eor|bic|orn|eon|'
    r'mul|madd|msub|smull|umull|smaddl|umaddl|'
    r'sxtb|sxth|sxtw|uxtb|uxth|uxtw|'
    r'ubfx|sbfx|bfi|bfxil|uxtb|lsr|lsl|asr|ror|'
    r'csel|csinc|csinv|csneg|cset|csetm|'
    r'neg|mvn|rev|rev16|rev32|clz|cls|'
    r'fmov|scvtf|ucvtf|fcvtzs|fcvtzu|'
    r'movk)\b')

def regnum(r):
    r = r.strip().strip('[]!,#')
    if len(r) > 1 and r[0] in 'xw' and r[1:].isdigit():
        n = int(r[1:])
        return n if n <= 7 else None
    return None

results = collections.defaultdict(list)
processed = 0
errors = 0

for path in files:
    name = os.path.basename(path)
    try:
        out = subprocess.run(['objdump', '-d', '-r', path],
                             capture_output=True, text=True, timeout=120).stdout
    except Exception:
        errors += 1
        continue
    if not out:
        errors += 1
        continue

    instrs = []
    for ln in out.split('\n'):
        m = pat.match(ln)
        if m:
            instrs.append({'op': m.group(3), 'args': m.group(4).strip()})

    for i, ins in enumerate(instrs):
        if ins['op'] not in ('bl', 'blr'):
            continue
        if '<' not in ins['args']:
            continue
        target = ins['args'].split('<')[-1].split('>')[0].strip()
        if not target or target.startswith('.'):
            continue
        written = set()
        for j in range(i - 1, max(-1, i - 41), -1):
            p = instrs[j]
            if p['op'] in ('bl', 'blr', 'ret', 'b', 'br'):
                break
            if not WRITE_RE.match(p['op']):
                continue
            ops = p['args'].split(',')
            if not ops:
                continue
            d = regnum(ops[0])
            if d is not None:
                written.add(d)
        nact = (max(written) + 1) if written else 0
        results[target].append(nact)

    processed += 1
    if processed % 50 == 0:
        print(f'  {processed}/{len(files)} …', file=sys.stderr)

print(f'\n处理完成: {processed} 个模块, {errors} 个失败', file=sys.stderr)
print(f'推断出参数的符号: {len(results)}', file=sys.stderr)

# 每个符号取众数，并记录置信度
final = {}
for sym, counts in results.items():
    c = collections.Counter(counts)
    best, freq = c.most_common(1)[0]
    final[sym] = {'nargs': best, 'votes': len(counts),
                  'confidence': round(freq / len(counts), 2)}

json.dump(final, open(OUT, 'w'), indent=1)
print(f'已写入 {OUT}', file=sys.stderr)

# 报告
low = [s for s, v in final.items() if v['confidence'] < 0.6]
print(f'\n置信度 < 0.6 的符号: {len(low)}', file=sys.stderr)
