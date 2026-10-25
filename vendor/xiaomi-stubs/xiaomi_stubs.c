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
