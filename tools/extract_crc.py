import struct, glob, os, json, collections

def parse_ko(path):
    d=open(path,'rb').read()
    if len(d)<64: return {}
    e_shoff=struct.unpack('<Q', d[0x28:0x30])[0]
    e_sh=struct.unpack('<H', d[0x3a:0x3c])[0]
    e_n=struct.unpack('<H', d[0x3c:0x3e])[0]
    e_si=struct.unpack('<H', d[0x3e:0x40])[0]
    if e_shoff==0 or e_shoff>=len(d): return {}
    def sh(i):
        o=e_shoff+i*e_sh
        if o+64>len(d): return None
        return struct.unpack('<IIQQQQIIQQ', d[o:o+64])
    r=sh(e_si)
    if not r: return {}
    st=d[r[4]:r[4]+r[5]]
    secs={}
    for i in range(e_n):
        x=sh(i)
        if not x: continue
        if x[0]>=len(st): continue
        nm=st[x[0]:st.index(b'\x00',x[0])].decode(errors='replace')
        secs[nm]={'off':x[4],'size':x[5]}
    out={}
    # 新式：__version_ext_crcs + __version_ext_names
    if '__version_ext_crcs' in secs and '__version_ext_names' in secs:
        co,no=secs['__version_ext_crcs'],secs['__version_ext_names']
        crcs=[struct.unpack('<I', d[co['off']+i*4:co['off']+i*4+4])[0]
              for i in range(co['size']//4)]
        blk=d[no['off']:no['off']+no['size']]
        names=[x.decode(errors='replace') for x in blk.split(b'\x00') if x]
        for n,c in zip(names,crcs): out[n]=c
    # 老式：__versions（struct modversion_info: u64 crc + char name[56]）
    if not out and '__versions' in secs:
        s=secs['__versions']
        for i in range(s['size']//64):
            o=s['off']+i*64
            crc=struct.unpack('<Q', d[o:o+8])[0] & 0xffffffff
            nm=d[o+8:o+64].split(b'\x00')[0].decode(errors='replace')
            if nm: out[nm]=crc
    return out

db={}
for p in sorted(glob.glob('/var/minis/workspace/cq/ko/*.ko')):
    r=parse_ko(p)
    for k,v in r.items(): db.setdefault(k,set()).add(v)
print('符号总数:', len(db))
# 检查一致性：同一符号在不同模块里 CRC 应相同
conflict={k:v for k,v in db.items() if len(v)>1}
print('CRC 不一致的符号:', len(conflict))
for k in list(conflict)[:5]: print('   ', k, [hex(x) for x in conflict[k]])

final={k:list(v)[0] for k,v in db.items()}
json.dump(final, open('/var/minis/workspace/cq/v/symbol_crc.json','w'), indent=1)
print('已写入 symbol_crc.json')
