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

__cold void _dev_crit(const struct device *dev, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(_dev_crit);

__cold void _dev_err(const struct device *dev, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(_dev_err);

__cold void _dev_info(const struct device *dev, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(_dev_info);

__cold void _dev_notice(const struct device *dev, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(_dev_notice);

__cold void _dev_warn(const struct device *dev, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(_dev_warn);

void bpf_trace_run1(struct bpf_raw_tp_link *link, u64 arg1)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run1);

void bpf_trace_run10(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run10);

void bpf_trace_run11(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run11);

void bpf_trace_run12(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run12);

void bpf_trace_run2(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run2);

void bpf_trace_run3(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run3);

void bpf_trace_run4(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run4);

void bpf_trace_run5(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run5);

void bpf_trace_run6(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run6);

void bpf_trace_run7(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run7);

void bpf_trace_run8(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run8);

void bpf_trace_run9(struct bpf_raw_tp_link *link, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9)
{
	/* no-op */
}
EXPORT_SYMBOL(bpf_trace_run9);

int __must_check kstrtoint_from_user(const char __user *s, size_t count, unsigned int base, int *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtoint_from_user);

int __must_check kstrtos8_from_user(const char __user *s, size_t count, unsigned int base, s8 *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtos8_from_user);

int __must_check kstrtou16_from_user(const char __user *s, size_t count, unsigned int base, u16 *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtou16_from_user);

int __must_check kstrtou8_from_user(const char __user *s, size_t count, unsigned int base, u8 *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtou8_from_user);

int __must_check kstrtouint_from_user(const char __user *s, size_t count, unsigned int base, unsigned int *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtouint_from_user);

int __must_check kstrtoul_from_user(const char __user *s, size_t count, unsigned int base, unsigned long *res)
{
	return 0;
}
EXPORT_SYMBOL(kstrtoul_from_user);

int memory_cgrp_subsys_enabled_key(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memory_cgrp_subsys_enabled_key);

int memory_cgrp_subsys_on_dfl_key(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memory_cgrp_subsys_on_dfl_key);

__cold void netdev_err(const struct net_device *dev, const char *format, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(netdev_err);

__cold void netdev_info(const struct net_device *dev, const char *format, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(netdev_info);

extern int param_get_int(char *buffer, const struct kernel_param *kp)
{
	return 0;
}
EXPORT_SYMBOL(param_get_int);

extern int param_get_uint(char *buffer, const struct kernel_param *kp)
{
	return 0;
}
EXPORT_SYMBOL(param_get_uint);

extern int param_get_ullong(char *buffer, const struct kernel_param *kp)
{
	return 0;
}
EXPORT_SYMBOL(param_get_ullong);

return param_set_int(val, kp)
{
	return 0;
}
EXPORT_SYMBOL(param_set_int);

extern int param_set_uint(const char *val, const struct kernel_param *kp)
{
	return 0;
}
EXPORT_SYMBOL(param_set_uint);
