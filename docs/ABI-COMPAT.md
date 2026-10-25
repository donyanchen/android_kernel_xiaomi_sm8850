# Pudding Kernel — 完整 ABI 兼容方案

> 目标：让自编译内核能加载小米 17（pudding / canoe / sm8850）全部 404 个厂商模块
> 数据来源：全部从真机与官方固件提取，无推测

---

## 一、覆盖度核算

```
设备导出符号                        14,734
404 个厂商模块真正依赖的符号          6,150

产物原本已有                         2,727  (44.3%)
闭源符号桩函数                         842  (13.7%)
高通开源子系统                        2,581  (42.0%)
                                   ─────────
合计覆盖                            6,150  (100.0%)
```

## 二、三层方案

### 第 1 层：配置对齐（44.3%）

设备 `/proc/config.gz` 的 2369 项作为 defconfig 基线，叠加 ABI 严格对齐项。

**关键 ABI 开关**（缺一项 `module_layout` CRC 就错）：

| CONFIG | 作用 |
|---|---|
| `TRIM_UNUSED_KSYMS=y` | 按白名单裁剪 ksymtab |
| `EXTENDED_MODVERSIONS=y` | CRC 迁入 `__ksymtab`，条目 12 字节 |
| `CFI_ICALL_NORMALIZE_INTEGERS=y` | CFI 间接调用归一化 |
| `MODULE_SCMVERSION=y` | `struct module` +256 `scmversion` |
| `DEBUG_INFO_BTF_MODULES=y` | `struct module` +1364 `btf_base_data_size` |
| `RUST=y` | 3655 个 `_RNv*` 符号 + KABI 保留位 |

**白名单**：`configs/abi_symbollist.raw`，14,734 项，从设备 `__ksymtab_*` 提取。

### 第 2 层：闭源符号桩（13.7%）

`vendor/xiaomi-stubs/xiaomi_stubs.c`，842 个符号。

**签名推断来源**：

```
404 个 .ko 全部反汇编  →  30,288 个调用点
                          ↓
              x0-x7 寄存器写入分析
                          ↓
                  参数个数（642 个，多数置信度 1.00）
```

**变参函数特殊处理**（参数分布从 2 到 8 发散，即变参）：

```c
int __mca_log_err(const char *fmt, const char *func, int line, ...);
int __mca_log_info(const char *fmt, const char *func, int line, ...);
int __mca_log_debug(const char *fmt, const char *func, int line, ...);
```

反汇编实证：

```
adrp x0, .rodata / add x0    → 格式串
adrp x1, .rodata / add x1    → 函数名
mov  w2, #159                → 行号
bl   __mca_log_err
```

**变量类符号**（31 个，非函数）：用真实定义，例如 QMI 描述符 `_ei` 后缀

```c
struct qmi_elem_info data_ep_id_type_v01_ei[1];
```

### 第 3 层：高通开源子系统（42.0%）

从 `OnePlusOSS/android_kernel_modules_and_devicetree_oneplus_sm8850`
（分支 `oneplus/sm8850_b_16.0.0_oneplus_15`）sparse-checkout 拉取：

```
vendor/qcom/opensource/dataipa            → ipa_* / ipa3_* / gsi_*
vendor/qcom/opensource/synx-kernel        → synx_*
vendor/qcom/opensource/dsp-kernel         → fastrpc_* / adsp_*
vendor/qcom/opensource/datarmnet          → rmnet_*
vendor/qcom/opensource/securemsm-kernel   → qce_*
```

其余由 CONFIG 打开（`CFG80211` / `MHI_BUS` / `CORESIGHT` / `SLIMBUS` /
`SOUNDWIRE` / `QCOM_QMI_HELPERS` 等）。

## 三、CI 流水线

```
1. 准备 ACK 源码
2. 准备工具链（clang 19 / rust 1.82）
3. 集成 SukiSU
4. 兼容性补丁
5. 集成高通开源子系统（sparse-checkout）
6. 桩函数挂进 drivers/Makefile + Kconfig
7. 配置内核（设备真配置 + ABI 对齐 + 子系统 CONFIG）
8. 编译（装 pahole 生成 BTF）
9. ABI 硬校验 ← module_layout CRC 必须 == 0x797f2b3e
```

## 四、验证基准

| 项目 | 设备基准 | 校验方式 |
|---|---|---|
| `module_layout` CRC | `0x797f2b3e` | `vmlinux.symvers` 比对 |
| `struct module` | 1600 字节 / 75 成员 | `pahole -C module vmlinux` |
| 导出符号数 | 14,734 | `wc -l vmlinux.symvers` |
| vermagic | `6.12.69-android16-6-4k SMP preempt mod_unload modversions aarch64` | strings |

## 五、数据文件

| 文件 | 内容 |
|---|---|
| `configs/pudding_full.defconfig` | 设备 2369 项配置 |
| `configs/pudding_abi.fragment` | ABI 严格对齐 |
| `configs/abi_symbollist.raw` | 14,734 项导出符号白名单 |
| `vendor/xiaomi-stubs/xiaomi_stubs.c` | 842 个闭源符号桩 |

## 六、已知限制

1. **功能退化**：`mca_*`（小米充电）桩函数返回 0，充电策略逻辑失效，
   但不影响模块加载与系统启动。
2. **200 个无调用点符号**：参数个数按命名规律推断，CRC 可能与设备不同，
   会导致对应模块加载失败（不影响其它模块）。可从设备符号表进一步反推收敛。
3. **源码版本差异**：一加 sm8850 与小米 sm8850 同平台但出厂时间不同，
   个别符号签名可能有差异。
