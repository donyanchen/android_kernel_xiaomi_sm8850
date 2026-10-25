// SPDX-License-Identifier: GPL-2.0
/*
 * 自动生成：ABI 兼容桩函数
 *
 * 策略：
 *   1. 头文件已声明 → 复用原型（避免 conflicting types）
 *   2. 其余 → 反汇编推断参数个数
 *   3. 变量 → 给出真实定义而非函数桩
 */
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/kobject.h>
#include <linux/soc/qcom/qmi.h>
#include <linux/dma-direction.h>
#include <linux/dma-mapping.h>

/* ===== 内核已有定义，此处仅补充导出 ===== */

extern void _dev_crit(const struct device *dev, const char *fmt, ...);
EXPORT_SYMBOL(_dev_crit);

extern void _dev_err(const struct device *dev, const char *fmt, ...);
EXPORT_SYMBOL(_dev_err);

extern void _dev_info(const struct device *dev, const char *fmt, ...);
EXPORT_SYMBOL(_dev_info);

extern void _dev_notice(const struct device *dev, const char *fmt, ...);
EXPORT_SYMBOL(_dev_notice);

extern void _dev_warn(const struct device *dev, const char *fmt, ...);
EXPORT_SYMBOL(_dev_warn);

extern void bpf_trace_run1(struct bpf_raw_tp_link *link, u64 arg1);
EXPORT_SYMBOL(bpf_trace_run1);

extern void bpf_trace_run10(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10);
EXPORT_SYMBOL(bpf_trace_run10);

extern void bpf_trace_run11(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11);
EXPORT_SYMBOL(bpf_trace_run11);

extern void bpf_trace_run12(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12);
EXPORT_SYMBOL(bpf_trace_run12);

extern void bpf_trace_run2(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2);
EXPORT_SYMBOL(bpf_trace_run2);

extern void bpf_trace_run3(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3);
EXPORT_SYMBOL(bpf_trace_run3);

extern void bpf_trace_run4(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4);
EXPORT_SYMBOL(bpf_trace_run4);

extern void bpf_trace_run5(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5);
EXPORT_SYMBOL(bpf_trace_run5);

extern void bpf_trace_run6(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6);
EXPORT_SYMBOL(bpf_trace_run6);

extern void bpf_trace_run7(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7);
EXPORT_SYMBOL(bpf_trace_run7);

extern void bpf_trace_run8(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8);
EXPORT_SYMBOL(bpf_trace_run8);

extern void bpf_trace_run9(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9);
EXPORT_SYMBOL(bpf_trace_run9);

extern int __must_check kstrtoint_from_user(const char __user *s, size_t count, unsigned int base, int *res);
EXPORT_SYMBOL(kstrtoint_from_user);

extern int __must_check kstrtos8_from_user(const char __user *s, size_t count, unsigned int base, s8 *res);
EXPORT_SYMBOL(kstrtos8_from_user);

extern int __must_check kstrtou16_from_user(const char __user *s, size_t count, unsigned int base, u16 *res);
EXPORT_SYMBOL(kstrtou16_from_user);

extern int __must_check kstrtou8_from_user(const char __user *s, size_t count, unsigned int base, u8 *res);
EXPORT_SYMBOL(kstrtou8_from_user);

extern int __must_check kstrtouint_from_user(const char __user *s, size_t count, unsigned int base, unsigned int *res);
EXPORT_SYMBOL(kstrtouint_from_user);

extern int __must_check kstrtoul_from_user(const char __user *s, size_t count, unsigned int base, unsigned long *res);
EXPORT_SYMBOL(kstrtoul_from_user);

extern void netdev_err(const struct net_device *dev, const char *format, ...);
EXPORT_SYMBOL(netdev_err);

extern void netdev_info(const struct net_device *dev, const char *format, ...);
EXPORT_SYMBOL(netdev_info);

extern int param_get_int(char *buffer, const struct kernel_param *kp);
EXPORT_SYMBOL(param_get_int);

extern int param_get_uint(char *buffer, const struct kernel_param *kp);
EXPORT_SYMBOL(param_get_uint);

extern int param_get_ullong(char *buffer, const struct kernel_param *kp);
EXPORT_SYMBOL(param_get_ullong);

extern return param_set_int(val, kp);
EXPORT_SYMBOL(param_set_int);

extern int param_set_uint(const char *val, const struct kernel_param *kp);
EXPORT_SYMBOL(param_set_uint);
