# Pudding Kernel — ABI 兼容进展

> 目标机型：小米 17（pudding / canoe / sm8850，HyperOS OS4.0.5.0.XPCCNXM）
> 最后更新：2026-10-25

## 一、当前结论

**编译已通过，但 ABI CRC 尚未对齐。**

```
构建 #54 (40163180526)   ✅ 成功
Image 大小               39.7 MB
vmlinux.symvers          10,061 条
module_layout CRC        0xbc47a22e   （设备 0x797f2b3e ❌）
与设备 4,593 个真实 CRC 对比：一致 891 / 2,799 = 31.8%
```

## 二、已确认的事实

### 设备基准（真机提取）

| 项目 | 值 |
|---|---|
| 内核 | `6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k` |
| vermagic | `6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64` |
| 内核本体导出符号 | 9,933（`__ksymtab_*` 无 `[模块]` 后缀） |
| 模块导出符号 | 4,801 |
| 404 个厂商模块依赖内核提供的符号 | **2,716** |
| `struct module` | 1,600 字节 / 75 成员 |
| 槽位 | `_b`，boot_b = `/dev/block/sde57`，header v4，内核段裸 Image |

### 源码版本

```
ACK 分支        android16-6.12-2026-03（SUBLEVEL 69，与设备一致）
头文件比对      6,306 / 6,321 逐字节相同（剥离注释后）
差异文件        15 个（小米/高通定制 patch）
结构体成员名    16,936 个共有，仅 8 个差异
```

差异头文件：
```
blkdev.h  compaction.h  slab.h  vmalloc.h  sched/ext.h  sched/task_stack.h
net/af_unix.h  net/bluetooth/l2cap.h  scsi/scsi_device.h
trace/events/f2fs.h  trace/hooks/{blk,fault,fs,vmscan}.h  uapi/linux/f2fs.h
```

### 符号覆盖

```
需要内核导出                 2,716
ACK 源码提供                 2,672  (98.4%)
无法补（宏/内联）               30
```

去掉 30 个后不需要任何桩函数 —— 全部由内核自身提供。

## 三、CRC 不符的分界

```
memset / strlen / snprintf / sscanf / strncmp       ✅ 一致
ktime_get_with_offset（枚举参数）                    ✅ 一致
__alloc_skb / __amba_driver_register / devm_kmalloc  ❌ 不符
```

**genksyms 算法正确，问题在类型定义本身。**

已定位并修复的一处：

```kconfig
config MODULE_SCMVERSION
	depends on LOCALVERSION_AUTO        ← 曾因关闭 AUTO 导致 scmversion 字段缺失
```

`scripts/patch_kconfig.py` 解除该依赖，保留 `LOCALVERSION_AUTO=n` 以免 UTM_RELEASE 带 `-g<sha>`。

## 四、版本串伪装

`/proc/version` 需要与原厂逐字一致：

```
Linux version 6.12.69-android16-6-g43b5ab7e247d-abogki561813157-4k
(kleaf@build-host)
(Android (14043575, +pgo, +bolt, +lto, +mlgo, based on r536225) clang version 19.0.1 (...), LLD 19.0.1)
#1 SMP PREEMPT Tue Sep  8 15:08:49 UTC 2026
```

两种实现：

| 方式 | 脚本 | 说明 |
|---|---|---|
| 编译期 | `scripts/fake_version.py` | 替换 `init/version-timestamp.c` 的 `release=` 与 `LINUX_COMPILER` |
| 离线 | `scripts/patch_image.py` | 对已编译 Image 做等长二进制替换（版本串 52 字节、编译器号 8 位数字均可等长替换） |

`KBUILD_BUILD_TIMESTAMP` 必须是 `Tue Sep  8 15:08:49 UTC 2026`（date 默认格式），
写成 ISO 格式会导致 `uname -v` 与原厂不同。

## 五、工具

| 脚本 | 用途 |
|---|---|
| `scripts/config_diff.py` | 构建出的 `.config` 与设备配置全量 diff |
| `scripts/fake_version.py` | 编译期版本串伪装 |
| `scripts/patch_image.py` | 离线镜像版本串补丁 |
| `scripts/patch_kconfig.py` | 解除 MODULE_SCMVERSION 依赖 |
| `tools/extract_crc.py` | 从 404 个 `.ko` 提取真实符号 CRC |
| `tools/infer_params.py` | 反汇编推断外部符号参数个数 |
| `tools/gen_stubs.py` | 生成 ABI 桩函数 |
| `tools/cmp_structs.py` | BTF 结构体布局比对 |

## 六、待办

1. 拿到构建产物的 `.config`，与设备配置全量 diff（诊断步骤已加）
2. 找出导致结构体类型差异的 CONFIG 项
3. CRC 对齐后再评估刷机
