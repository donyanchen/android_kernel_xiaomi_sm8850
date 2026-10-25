// SPDX-License-Identifier: GPL-2.0
/*
 * Pudding Kernel — 闭源符号桩（自动生成）
 *
 * 目的：为小米/高通闭源代码导出的符号提供定义，使 404 个厂商模块可加载。
 *
 * 数据来源（全部从真机提取）：
 *   · /proc/kallsyms 的 __ksymtab_*                       14,734 项
 *   · 404 个厂商 .ko 的 __versions 依赖表
 *   · 404 个 .ko 的 aarch64 反汇编                         30,288 个调用点
 *   · 404 个 .ko 的 .symtab 符号类型（FUNC / OBJECT）
 *
 * 符号总数：2081（函数 2055，变量 26）
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/kobject.h>
#include <linux/soc/qcom/qmi.h>

/* ==================== 函数桩 ==================== */

/* ---- adc_* (4) ---- */
int adc_tm_absolute_rthr_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_absolute_rthr_gen3);

int adc_tm_channel_measure_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_channel_measure_gen3);

int adc_tm_disable_chan_meas_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_disable_chan_meas_gen3);

int adc_tm_scale_therm_voltage_100k_gen3(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_scale_therm_voltage_100k_gen3);

/* ---- add_* (4) ---- */
int add_common_data_to_buf(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(add_common_data_to_buf);

int add_hw_component_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(add_hw_component_info);

int add_hw_monitor_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(add_hw_monitor_info);

int add_input_event_timeline_before_event_time(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(add_input_event_timeline_before_event_time);

/* ---- adsp_* (1) ---- */
int adsp_sleepmon_log_master_stats(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adsp_sleepmon_log_master_stats);

/* ---- altmode_* (5) ---- */
int altmode_deregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(altmode_deregister_client);

int altmode_deregister_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(altmode_deregister_notifier);

int altmode_register_client(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(altmode_register_client);

int altmode_register_notifier(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(altmode_register_notifier);

int altmode_send_data(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(altmode_send_data);

/* ---- attach_* (1) ---- */
int attach_mpam_msc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(attach_mpam_msc);

/* ---- audio_* (12) ---- */
int audio_notifier_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(audio_notifier_deregister);

int audio_notifier_probe_status(void)
{
	return 0;
}
EXPORT_SYMBOL(audio_notifier_probe_status);

int audio_notifier_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(audio_notifier_register);

int audio_pdr_service_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(audio_pdr_service_deregister);

int audio_pdr_service_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(audio_pdr_service_register);

int audio_prm_set_cdc_earpa_duty_cycling_req(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(audio_prm_set_cdc_earpa_duty_cycling_req);

int audio_prm_set_lpass_clk_cfg(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(audio_prm_set_lpass_clk_cfg);

int audio_prm_set_lpass_hw_core_req(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(audio_prm_set_lpass_hw_core_req);

int audio_prm_set_lpi_logging_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(audio_prm_set_lpi_logging_status);

int audio_prm_set_vote_against_sleep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(audio_prm_set_vote_against_sleep);

int audio_ssr_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(audio_ssr_deregister);

int audio_ssr_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(audio_ssr_register);

/* ---- bm_* (1) ---- */
int bm_send_nl(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(bm_send_nl);

/* ---- bootprof_* (1) ---- */
int bootprof_lock(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(bootprof_lock);

/* ---- boottime_* (1) ---- */
int boottime_ok(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(boottime_ok);

/* ---- bpf_* (12) ---- */
int bpf_trace_run1(void)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run1);

int bpf_trace_run10(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run10);

int bpf_trace_run11(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run11);

int bpf_trace_run12(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run12);

int bpf_trace_run2(void)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run2);

int bpf_trace_run3(void)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run3);

int bpf_trace_run4(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run4);

int bpf_trace_run5(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run5);

int bpf_trace_run6(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run6);

int bpf_trace_run7(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run7);

int bpf_trace_run8(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run8);

int bpf_trace_run9(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(bpf_trace_run9);

/* ---- btfm_* (1) ---- */
void * btfm_get_btfmcodec(void)
{
	return NULL;
}
EXPORT_SYMBOL(btfm_get_btfmcodec);

/* ---- btfmcodec_* (2) ---- */
int btfmcodec_register_hw_ep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btfmcodec_register_hw_ep);

int btfmcodec_unregister_hw_ep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btfmcodec_unregister_hw_ep);

/* ---- btpower_* (2) ---- */
void * btpower_get_chipset_version(void)
{
	return NULL;
}
EXPORT_SYMBOL(btpower_get_chipset_version);

int btpower_register_slimdev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btpower_register_slimdev);

/* ---- build_* (1) ---- */
int build_fingerprint(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(build_fingerprint);

/* ---- cam_* (105) ---- */
int cam_cci_dump_registers(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_cci_dump_registers);

int cam_cdm_acquire(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_acquire);

int cam_cdm_detect_hang_error(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_detect_hang_error);

int cam_cdm_flush_hw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_flush_hw);

void * cam_cdm_get_iommu_handle(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cam_cdm_get_iommu_handle);

int cam_cdm_handle_error(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_handle_error);

int cam_cdm_publish_ops(void)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_publish_ops);

void cam_cdm_release(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_cdm_release);

int cam_cdm_reset_hw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_reset_hw);

int cam_cdm_stream_off(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_stream_off);

int cam_cdm_stream_on(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_stream_on);

int cam_cdm_submit_bls(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(cam_cdm_submit_bls);

void cam_common_mem_free(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_common_mem_free);

int cam_common_mem_kdup(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_common_mem_kdup);

int cam_cpas_activate_llcc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_activate_llcc);

int cam_cpas_axi_util_drv_vote_lvl_to_string(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_axi_util_drv_vote_lvl_to_string);

int cam_cpas_axi_util_path_type_to_string(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_axi_util_path_type_to_string);

int cam_cpas_axi_util_trans_type_to_string(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_axi_util_trans_type_to_string);

int cam_cpas_configure_staling_llcc(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_configure_staling_llcc);

int cam_cpas_csid_input_core_info_update(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_csid_input_core_info_update);

int cam_cpas_csid_process_resume(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_csid_process_resume);

int cam_cpas_deactivate_llcc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_deactivate_llcc);

int cam_cpas_dump_camnoc_buff_fill_info(void)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_dump_camnoc_buff_fill_info);

int cam_cpas_dump_state_monitor_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_dump_state_monitor_info);

int cam_cpas_enable_clks_for_domain_id(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_enable_clks_for_domain_id);

int cam_cpas_enable_tpg_mux_sel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_enable_tpg_mux_sel);

void * cam_cpas_get_hw_info(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return NULL;
}
EXPORT_SYMBOL(cam_cpas_get_hw_info);

void * cam_cpas_get_scid(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cam_cpas_get_scid);

bool cam_cpas_is_feature_supported(void *a0, void *a1, void *a2)
{
	return false;
}
EXPORT_SYMBOL(cam_cpas_is_feature_supported);

bool cam_cpas_is_fw_based_sys_caching_supported(void)
{
	return false;
}
EXPORT_SYMBOL(cam_cpas_is_fw_based_sys_caching_supported);

bool cam_cpas_is_notif_staling_supported(void)
{
	return false;
}
EXPORT_SYMBOL(cam_cpas_is_notif_staling_supported);

int cam_cpas_log_votes(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_log_votes);

int cam_cpas_notif_increment_staling_counter(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_notif_increment_staling_counter);

int cam_cpas_notify_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_notify_event);

int cam_cpas_prepare_subpart_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_prepare_subpart_info);

int cam_cpas_query_domain_id_security_support(void)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_query_domain_id_security_support);

int cam_cpas_query_drv_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_query_drv_enable);

int cam_cpas_read_llcc_status(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_read_llcc_status);

int cam_cpas_reg_read(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_reg_read);

int cam_cpas_reg_write(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_reg_write);

int cam_cpas_register_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_register_client);

int cam_cpas_select_qos_settings(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_select_qos_settings);

int cam_cpas_set_addr_trans(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_set_addr_trans);

int cam_cpas_start(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_start);

void cam_cpas_stop(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_cpas_stop);

int cam_cpas_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_unregister_client);

int cam_cpas_update_ahb_vote(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_update_ahb_vote);

int cam_cpas_update_axi_vote(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_update_axi_vote);

int cam_cpas_util_vote_type_to_string(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_cpas_util_vote_type_to_string);

void cam_ife_csid_hw_ver1_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_ife_csid_hw_ver1_deinit);

int cam_ife_csid_hw_ver1_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_ife_csid_hw_ver1_init);

void cam_ife_csid_hw_ver2_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_ife_csid_hw_ver2_deinit);

int cam_ife_csid_hw_ver2_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_ife_csid_hw_ver2_init);

void * cam_mem_get_cpu_buf(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cam_mem_get_cpu_buf);

void * cam_mem_get_io_buf(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return NULL;
}
EXPORT_SYMBOL(cam_mem_get_io_buf);

int cam_mem_mgr_cache_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_cache_ops);

int cam_mem_mgr_cpu_access_op(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_cpu_access_op);

int cam_mem_mgr_free_memory_region(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_free_memory_region);

int cam_mem_mgr_release_mem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_release_mem);

int cam_mem_mgr_request_mem(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_request_mem);

int cam_mem_mgr_reserve_memory_region(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_mgr_reserve_memory_region);

int cam_mem_put_cpu_buf(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_put_cpu_buf);

int cam_mem_put_kref(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_mem_put_kref);

void * cam_mem_trace_alloc(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return NULL;
}
EXPORT_SYMBOL(cam_mem_trace_alloc);

void cam_mem_trace_free(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_mem_trace_free);

int cam_record_bind_latency(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_record_bind_latency);

int cam_register_subdev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_register_subdev);

void * cam_req_mgr_get_id_subscribed(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return NULL;
}
EXPORT_SYMBOL(cam_req_mgr_get_id_subscribed);

int cam_req_mgr_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_req_mgr_init);

bool cam_req_mgr_is_open(void)
{
	return false;
}
EXPORT_SYMBOL(cam_req_mgr_is_open);

bool cam_req_mgr_is_shutdown(void *a0)
{
	return false;
}
EXPORT_SYMBOL(cam_req_mgr_is_shutdown);

int cam_req_mgr_notify_message(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_req_mgr_notify_message);

int cam_res_mgr_gpio_free_arry(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_res_mgr_gpio_free_arry);

void * cam_res_mgr_gpio_get_value(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return NULL;
}
EXPORT_SYMBOL(cam_res_mgr_gpio_get_value);

int cam_res_mgr_gpio_request(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_res_mgr_gpio_request);

int cam_res_mgr_gpio_set_value(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_res_mgr_gpio_set_value);

int cam_res_mgr_led_trigger_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_res_mgr_led_trigger_event);

int cam_res_mgr_led_trigger_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_res_mgr_led_trigger_register);

void cam_res_mgr_led_trigger_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cam_res_mgr_led_trigger_unregister);

bool cam_res_mgr_util_check_if_gpio_is_shared(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return false;
}
EXPORT_SYMBOL(cam_res_mgr_util_check_if_gpio_is_shared);

void * cam_res_mgr_util_get_idx_from_shared_gpio(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cam_res_mgr_util_get_idx_from_shared_gpio);

void * cam_res_mgr_util_get_idx_from_shared_pctrl_gpio(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cam_res_mgr_util_get_idx_from_shared_pctrl_gpio);

bool cam_res_mgr_util_shared_gpio_check_hold(void *a0)
{
	return false;
}
EXPORT_SYMBOL(cam_res_mgr_util_shared_gpio_check_hold);

int cam_smmu_alloc_firmware(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_alloc_firmware);

int cam_smmu_buffer_tracker_putref(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_buffer_tracker_putref);

int cam_smmu_dealloc_firmware(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_dealloc_firmware);

int cam_smmu_destroy_handle(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_destroy_handle);

void * cam_smmu_get_handle(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cam_smmu_get_handle);

void * cam_smmu_get_iova(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return NULL;
}
EXPORT_SYMBOL(cam_smmu_get_iova);

void * cam_smmu_get_region_info(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cam_smmu_get_region_info);

void * cam_smmu_get_stage2_iova(void)
{
	return NULL;
}
EXPORT_SYMBOL(cam_smmu_get_stage2_iova);

int cam_smmu_map_kernel_iova(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_map_kernel_iova);

int cam_smmu_map_phy_mem_region(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_map_phy_mem_region);

int cam_smmu_map_stage2_iova(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_map_stage2_iova);

int cam_smmu_map_user_iova(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_map_user_iova);

int cam_smmu_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_ops);

int cam_smmu_put_iova(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_put_iova);

int cam_smmu_release_buf_region(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_release_buf_region);

int cam_smmu_reserve_buf_region(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_reserve_buf_region);

int cam_smmu_unmap_kernel_iova(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_unmap_kernel_iova);

int cam_smmu_unmap_phy_mem_region(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_unmap_phy_mem_region);

int cam_smmu_unmap_stage2_iova(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_unmap_stage2_iova);

int cam_smmu_unmap_user_iova(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(cam_smmu_unmap_user_iova);

int cam_subdev_notify_message(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cam_subdev_notify_message);

int cam_unregister_subdev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cam_unregister_subdev);

/* ---- camlog_* (1) ---- */
int camlog_send_message(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(camlog_send_message);

/* ---- cdev_* (5) ---- */
int cdev_tevent_add_int(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_add_int);

int cdev_tevent_add_str(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_add_str);

void * cdev_tevent_alloc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cdev_tevent_alloc);

void cdev_tevent_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cdev_tevent_destroy);

int cdev_tevent_write(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_write);

/* ---- cdsprm_* (10) ---- */
int cdsprm_compute_core_set_priority(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_compute_core_set_priority);

int cdsprm_compute_vtcm_set_partition_map(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_compute_vtcm_set_partition_map);

int cdsprm_cxlimit_camera_activity_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_camera_activity_notify);

int cdsprm_cxlimit_npu_activity_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_activity_notify);

int cdsprm_cxlimit_npu_corner_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_corner_notify);

int cdsprm_cxlimit_npu_limit_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_limit_deregister);

int cdsprm_cxlimit_npu_limit_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_limit_register);

int cdsprm_register_cdspl3gov(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_register_cdspl3gov);

int cdsprm_sysmon_dcvs_clients_votes(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_sysmon_dcvs_clients_votes);

int cdsprm_unregister_cdspl3gov(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_unregister_cdspl3gov);

/* ---- charger_* (30) ---- */
void * charger_partition_alloc(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_alloc);

int charger_partition_dealloc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_dealloc);

void * charger_partition_get_eu_model(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_get_eu_model);

void * charger_partition_get_mishow(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_get_mishow);

int charger_partition_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read);

int charger_partition_read_batt_emerg_sn(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_emerg_sn);

int charger_partition_read_batt_missing_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_missing_count);

int charger_partition_read_batt_missing_time(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_missing_time);

int charger_partition_read_batt_safe_ilim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_safe_ilim);

int charger_partition_read_batt_safe_vlim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_safe_vlim);

int charger_partition_read_cuv_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_cuv_count);

int charger_partition_read_double85(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_double85);

int charger_partition_read_hscd_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_hscd_count);

int charger_partition_read_memory_test(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_memory_test);

int charger_partition_read_ocd_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_ocd_count);

int charger_partition_read_soc_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_soc_limit);

int charger_partition_write(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write);

int charger_partition_write_batt_emerg_sn(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_emerg_sn);

int charger_partition_write_batt_missing_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_missing_count);

int charger_partition_write_batt_missing_time(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_missing_time);

int charger_partition_write_batt_safe_ilim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_safe_ilim);

int charger_partition_write_batt_safe_vlim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_safe_vlim);

int charger_partition_write_cuv_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_cuv_count);

int charger_partition_write_double85(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_double85);

int charger_partition_write_eu_model(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_eu_model);

int charger_partition_write_hcsd_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_hcsd_count);

int charger_partition_write_memory_test(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_memory_test);

int charger_partition_write_ocd_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_ocd_count);

int charger_partition_write_remove_temp_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_remove_temp_limit);

int charger_partition_write_soc_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_soc_limit);

/* ---- cld80211_* (1) ---- */
void * cld80211_get_genl_family(void)
{
	return NULL;
}
EXPORT_SYMBOL(cld80211_get_genl_family);

/* ---- clk_* (3) ---- */
int clk_debug_measure_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(clk_debug_measure_register);

int clk_debug_mux_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(clk_debug_mux_ops);

int clk_dummy_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(clk_dummy_ops);

/* ---- cma_* (1) ---- */
int cma_pool_init_shrinker(void)
{
	return 0;
}
EXPORT_SYMBOL(cma_pool_init_shrinker);

/* ---- cnss_* (114) ---- */
int cnss_athdiag_read(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(cnss_athdiag_read);

int cnss_athdiag_write(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(cnss_athdiag_write);

bool cnss_audio_is_direct_link_supported(void *a0)
{
	return false;
}
EXPORT_SYMBOL(cnss_audio_is_direct_link_supported);

int cnss_audio_smmu_map(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_audio_smmu_map);

int cnss_audio_smmu_unmap(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_audio_smmu_unmap);

int cnss_auto_resume(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_auto_resume);

int cnss_auto_suspend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_auto_suspend);

int cnss_deinitialize_prealloc_pool(void)
{
	return 0;
}
EXPORT_SYMBOL(cnss_deinitialize_prealloc_pool);

int cnss_device_crashed(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_device_crashed);

int cnss_force_collect_rddm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_force_collect_rddm);

int cnss_force_fw_assert(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_force_fw_assert);

void * cnss_get_audio_shared_iommu_group_cap(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_audio_shared_iommu_group_cap);

void * cnss_get_boot_timeout(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_boot_timeout);

void * cnss_get_cpumask_for_wlan_rx_interrupts(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_cpumask_for_wlan_rx_interrupts);

void * cnss_get_cpumask_for_wlan_tx_comp_interrupts(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_cpumask_for_wlan_tx_comp_interrupts);

void * cnss_get_curr_therm_cdev_state(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_curr_therm_cdev_state);

void * cnss_get_direct_link_sid(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_direct_link_sid);

void * cnss_get_fw_cap(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_fw_cap);

void * cnss_get_fw_files_for_target(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_fw_files_for_target);

void * cnss_get_fw_lpass_shared_mem(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_fw_lpass_shared_mem);

void * cnss_get_mem_seg_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_mem_seg_count);

void * cnss_get_mem_segment_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_mem_segment_info);

void * cnss_get_msi_address(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_msi_address);

void * cnss_get_msi_irq(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_msi_irq);

void * cnss_get_pci_slot(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_pci_slot);

void * cnss_get_platform_cap(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_platform_cap);

void * cnss_get_soc_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_soc_info);

void * cnss_get_user_msi_assignment(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_user_msi_assignment);

void * cnss_get_virt_ramdump_mem(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_virt_ramdump_mem);

void * cnss_get_wifi_kobj(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_get_wifi_kobj);

int cnss_idle_restart(void)
{
	return 0;
}
EXPORT_SYMBOL(cnss_idle_restart);

void cnss_idle_shutdown(void)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_idle_shutdown);

int cnss_initialize_prealloc_pool(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_initialize_prealloc_pool);

int cnss_ipa_wlan_shared_smmu_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_ipa_wlan_shared_smmu_supported);

bool cnss_is_one_msi(void *a0)
{
	return false;
}
EXPORT_SYMBOL(cnss_is_one_msi);

int cnss_pci_allow_l1(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_allow_l1);

void cnss_pci_force_wake_release(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_pci_force_wake_release);

int cnss_pci_force_wake_request(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_force_wake_request);

int cnss_pci_force_wake_request_sync(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_force_wake_request_sync);

void * cnss_pci_get_iova_info(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_pci_get_iova_info);

void cnss_pci_get_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_pci_get_reg_dump);

bool cnss_pci_is_device_awake(void *a0, void *a1, void *a2, void *a3)
{
	return false;
}
EXPORT_SYMBOL(cnss_pci_is_device_awake);

bool cnss_pci_is_device_down(void *a0, void *a1, void *a2, void *a3)
{
	return false;
}
EXPORT_SYMBOL(cnss_pci_is_device_down);

bool cnss_pci_is_drv_connected(void *a0)
{
	return false;
}
EXPORT_SYMBOL(cnss_pci_is_drv_connected);

int cnss_pci_link_down(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_link_down);

int cnss_pci_lock_reg_window(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_lock_reg_window);

int cnss_pci_prevent_l1(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_prevent_l1);

int cnss_pci_unlock_reg_window(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_pci_unlock_reg_window);

int cnss_plat_ipc_qmi_daemon_config(void)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_daemon_config);

int cnss_plat_ipc_qmi_file_download(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_download);

int cnss_plat_ipc_qmi_file_download_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_download_ind_msg_v01_ei);

int cnss_plat_ipc_qmi_file_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_download_req_msg_v01_ei);

int cnss_plat_ipc_qmi_file_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_download_resp_msg_v01_ei);

int cnss_plat_ipc_qmi_file_upload(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_upload);

int cnss_plat_ipc_qmi_file_upload_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_upload_ind_msg_v01_ei);

int cnss_plat_ipc_qmi_file_upload_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_upload_req_msg_v01_ei);

int cnss_plat_ipc_qmi_file_upload_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_file_upload_resp_msg_v01_ei);

int cnss_plat_ipc_qmi_init_setup_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_init_setup_req_msg_v01_ei);

int cnss_plat_ipc_qmi_init_setup_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_init_setup_resp_msg_v01_ei);

int cnss_plat_ipc_qmi_reg_client_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_reg_client_req_msg_v01_ei);

int cnss_plat_ipc_qmi_reg_client_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_qmi_reg_client_resp_msg_v01_ei);

int cnss_plat_ipc_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_plat_ipc_register);

void cnss_plat_ipc_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_plat_ipc_unregister);

void cnss_power_down(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_power_down);

int cnss_power_up(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_power_up);

int cnss_qmi_send(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(cnss_qmi_send);

int cnss_qmi_send_get(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_qmi_send_get);

void cnss_qmi_send_put(void *a0, void *a1, void *a2, void *a3)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_qmi_send_put);

int cnss_register_driver_async_data_cb(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_register_driver_async_data_cb);

int cnss_register_tsf_captured_handler(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_register_tsf_captured_handler);

int cnss_remove_pm_qos(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_remove_pm_qos);

int cnss_request_bus_bandwidth(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_request_bus_bandwidth);

int cnss_request_pm_qos(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_request_pm_qos);

int cnss_reset_afcmem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_reset_afcmem);

int cnss_reset_time_sync_period(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_reset_time_sync_period);

int cnss_schedule_recovery(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_schedule_recovery);

int cnss_self_recovery(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_self_recovery);

int cnss_send_buffer_to_afcmem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_send_buffer_to_afcmem);

int cnss_set_cxpc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_cxpc);

int cnss_set_fw_log_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_fw_log_mode);

int cnss_set_host_param(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_host_param);

int cnss_set_pcie_gen_speed(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_pcie_gen_speed);

int cnss_set_vendor_wonder_priv_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_vendor_wonder_priv_data);

int cnss_set_wfc_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_set_wfc_mode);

void * cnss_smmu_get_domain(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_smmu_get_domain);

int cnss_smmu_map(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_smmu_map);

int cnss_smmu_s1_enabled(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_smmu_s1_enabled);

int cnss_smmu_unmap(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_smmu_unmap);

int cnss_thermal_cdev_register(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cnss_thermal_cdev_register);

void cnss_thermal_cdev_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_thermal_cdev_unregister);

int cnss_unregister_tsf_captured_handler(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_unregister_tsf_captured_handler);

int cnss_update_time_sync_period(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_update_time_sync_period);

int cnss_utils_fmd_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_fmd_status);

void * cnss_utils_get_cc_source(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_get_cc_source);

void * cnss_utils_get_driver_load_cnt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_get_driver_load_cnt);

void * cnss_utils_get_wlan_derived_mac_address(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_get_wlan_derived_mac_address);

void * cnss_utils_get_wlan_mac_address(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_get_wlan_mac_address);

void * cnss_utils_get_wlan_unsafe_channel(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_get_wlan_unsafe_channel);

int cnss_utils_increment_driver_load_cnt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_increment_driver_load_cnt);

int cnss_utils_register_status_notifier(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_register_status_notifier);

int cnss_utils_set_cc_source(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_set_cc_source);

int cnss_utils_set_wlan_derived_mac_address(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_set_wlan_derived_mac_address);

int cnss_utils_set_wlan_mac_address(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_set_wlan_mac_address);

int cnss_utils_set_wlan_unsafe_channel(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_set_wlan_unsafe_channel);

int cnss_utils_smem_mailbox_write(void)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_smem_mailbox_write);

int cnss_utils_update_device_type(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_update_device_type);

void * cnss_utils_wlan_get_dfs_nol(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(cnss_utils_wlan_get_dfs_nol);

int cnss_utils_wlan_set_dfs_nol(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_utils_wlan_set_dfs_nol);

void cnss_wlan_disable(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(cnss_wlan_disable);

int cnss_wlan_enable(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cnss_wlan_enable);

int cnss_wlan_hw_enable(void)
{
	return 0;
}
EXPORT_SYMBOL(cnss_wlan_hw_enable);

int cnss_wlan_pm_control(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cnss_wlan_pm_control);

int cnss_wlan_register_driver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_wlan_register_driver);

int cnss_wlan_unregister_driver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cnss_wlan_unregister_driver);

/* ---- connector_* (1) ---- */
bool connector_antiburn_is_triggered(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(connector_antiburn_is_triggered);

/* ---- core_* (2) ---- */
int core_ctl_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(core_ctl_notifier_register);

void core_ctl_notifier_unregister(void)
{
	/* no-op */
}
EXPORT_SYMBOL(core_ctl_notifier_unregister);

/* ---- coredump_* (1) ---- */
int coredump_cleanup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coredump_cleanup);

/* ---- coresight_* (13) ---- */
int coresight_csr_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coresight_csr_get);

int coresight_csr_hwctrl_set(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coresight_csr_hwctrl_set);

int coresight_csr_set_byte_cntr(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(coresight_csr_set_byte_cntr);

int coresight_csr_set_etr_atid(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(coresight_csr_set_etr_atid);

void * coresight_get_device_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(coresight_get_device_name);

void * coresight_get_path(void)
{
	return NULL;
}
EXPORT_SYMBOL(coresight_get_path);

void * coresight_get_sink(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(coresight_get_sink);

int coresight_qmi_assign_atid(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(coresight_qmi_assign_atid);

int coresight_qmi_etr_assign(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(coresight_qmi_etr_assign);

void coresight_qmi_remote_etm_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(coresight_qmi_remote_etm_disable);

int coresight_qmi_remote_etm_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coresight_qmi_remote_etm_enable);

int coresight_trace_id_free_reserved_id(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coresight_trace_id_free_reserved_id);

int coresight_trace_id_reserve_id(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coresight_trace_id_reserve_id);

/* ---- cpu_* (2) ---- */
int cpu_logical_to_phys(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cpu_logical_to_phys);

int cpu_scale(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cpu_scale);

/* ---- crm_* (5) ---- */
int crm_dump_regs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(crm_dump_regs);

void * crm_get_device(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(crm_get_device);

int crm_read_curr_perf_ol(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(crm_read_curr_perf_ol);

int crm_write_perf_ol(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(crm_write_perf_ol);

int crm_write_pwr_states(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(crm_write_pwr_states);

/* ---- cs_* (30) ---- */
int cs_dsp_adsp1_init(void)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_adsp1_init);

void cs_dsp_adsp1_power_down(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cs_dsp_adsp1_power_down);

int cs_dsp_adsp1_power_up(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_adsp1_power_up);

int cs_dsp_adsp2_bus_error(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_adsp2_bus_error);

int cs_dsp_adsp2_init(void)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_adsp2_init);

int cs_dsp_chunk_flush(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_chunk_flush);

int cs_dsp_chunk_read(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_chunk_read);

int cs_dsp_chunk_write(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_chunk_write);

int cs_dsp_cleanup_debugfs(void)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_cleanup_debugfs);

int cs_dsp_coeff_read_ctrl(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_coeff_read_ctrl);

int cs_dsp_coeff_write_acked_control(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_coeff_write_acked_control);

int cs_dsp_coeff_write_ctrl(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_coeff_write_ctrl);

int cs_dsp_find_alg_region(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_find_alg_region);

void * cs_dsp_get_ctl(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(cs_dsp_get_ctl);

int cs_dsp_halo_bus_error(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_halo_bus_error);

int cs_dsp_halo_init(void)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_halo_init);

int cs_dsp_halo_wdt_expire(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_halo_wdt_expire);

int cs_dsp_init_debugfs(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_init_debugfs);

int cs_dsp_load_coeff(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_load_coeff);

int cs_dsp_mem_region_name(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_mem_region_name);

void cs_dsp_power_down(void)
{
	/* no-op */
}
EXPORT_SYMBOL(cs_dsp_power_down);

int cs_dsp_power_up(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_power_up);

int cs_dsp_read_data_word(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_read_data_word);

int cs_dsp_read_raw_data_block(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_read_raw_data_block);

void cs_dsp_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cs_dsp_remove);

int cs_dsp_remove_padding(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_remove_padding);

int cs_dsp_run(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_run);

int cs_dsp_set_dspclk(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_set_dspclk);

void cs_dsp_stop(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cs_dsp_stop);

int cs_dsp_write_data_word(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(cs_dsp_write_data_word);

/* ---- cs35l43_* (2) ---- */
int cs35l43_resume_runtime(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs35l43_resume_runtime);

int cs35l43_suspend_runtime(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs35l43_suspend_runtime);

/* ---- cx_* (1) ---- */
void * cx_stats_get_ss_vote_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cx_stats_get_ss_vote_info);

/* ---- ddr_* (5) ---- */
void * ddr_stats_get_change_his(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_change_his);

void * ddr_stats_get_freq_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_freq_count);

void * ddr_stats_get_residency(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_residency);

void * ddr_stats_get_ss_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_ss_count);

void * ddr_stats_get_ss_vote_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_ss_vote_info);

/* ---- debug_* (2) ---- */
int debug_symbol_available(void)
{
	return 0;
}
EXPORT_SYMBOL(debug_symbol_available);

int debug_symbol_lookup_name(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(debug_symbol_lookup_name);

/* ---- deregister_* (1) ---- */
int deregister_cld_cmd_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(deregister_cld_cmd_cb);

/* ---- detach_* (1) ---- */
int detach_mpam_msc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(detach_mpam_msc);

/* ---- dev_* (5) ---- */
int _dev_crit(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(_dev_crit);

int _dev_err(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(_dev_err);

int _dev_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(_dev_info);

int _dev_notice(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(_dev_notice);

int _dev_warn(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(_dev_warn);

/* ---- devm_* (10) ---- */
int __devm_regmap_init_swr(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(__devm_regmap_init_swr);

int devm_clk_register_debug_mux(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(devm_clk_register_debug_mux);

void devm_hwmon_device_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(devm_hwmon_device_unregister);

int devm_regmap_qti_debugfs_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(devm_regmap_qti_debugfs_register);

void devm_regmap_qti_debugfs_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(devm_regmap_qti_debugfs_unregister);

int devm_regulator_debug_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(devm_regulator_debug_register);

int devm_regulator_proxy_consumer_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(devm_regulator_proxy_consumer_register);

void * devm_usb_get_optional_repeater_by_phandle(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(devm_usb_get_optional_repeater_by_phandle);

void * devm_usb_get_repeater_by_node(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(devm_usb_get_repeater_by_node);

void * devm_usb_get_repeater_by_phandle(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(devm_usb_get_repeater_by_phandle);

/* ---- digital_* (3) ---- */
void digital_cdc_rsc_mgr_hw_vote_disable(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_disable);

int digital_cdc_rsc_mgr_hw_vote_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_enable);

void digital_cdc_rsc_mgr_hw_vote_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_reset);

/* ---- disp_* (3) ---- */
int disp_kernel_timer_log_printk(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(disp_kernel_timer_log_printk);

int disp_log_printk(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(disp_log_printk);

int disp_log_printk_utc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(disp_log_printk_utc);

/* ---- dma_* (12) ---- */
int dma_buf_attach(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_attach);

int dma_buf_begin_cpu_access(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_begin_cpu_access);

int dma_buf_detach(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_detach);

int dma_buf_end_cpu_access(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_end_cpu_access);

int dma_buf_export(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_export);

int dma_buf_fd(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_fd);

int dma_buf_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_get);

int dma_buf_map_attachment_unlocked(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_map_attachment_unlocked);

void dma_buf_put(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(dma_buf_put);

int dma_buf_unmap_attachment_unlocked(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_unmap_attachment_unlocked);

int dma_buf_vmap_unlocked(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_vmap_unlocked);

int dma_buf_vunmap_unlocked(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(dma_buf_vunmap_unlocked);

/* ---- driver_* (2) ---- */
void * driver_get_touch_mode(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(driver_get_touch_mode);

int driver_update_touch_mode(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(driver_update_touch_mode);

/* ---- dsi_* (2) ---- */
int dsi_panel_gesture_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dsi_panel_gesture_enable);

int dsi_panel_send_asic_hdr_light_plus_cmd(void)
{
	return 0;
}
EXPORT_SYMBOL(dsi_panel_send_asic_hdr_light_plus_cmd);

/* ---- dss_* (3) ---- */
void dss_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(dss_reg_dump);

int dss_reg_r(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(dss_reg_r);

int dss_reg_w(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(dss_reg_w);

/* ---- dump_* (3) ---- */
int dump_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(dump_enabled);

int dump_trace_and_send_event(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(dump_trace_and_send_event);

int dump_user_backtrace(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dump_user_backtrace);

/* ---- dwc3_* (2) ---- */
int dwc3_msm_release_ss_lane(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dwc3_msm_release_ss_lane);

int dwc3_msm_set_dp_mode(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(dwc3_msm_set_dp_mode);

/* ---- etm_* (1) ---- */
void * etm_event_get_path(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(etm_event_get_path);

/* ---- fsa4480_* (3) ---- */
int fsa4480_reg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_reg_notifier);

int fsa4480_switch_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_switch_event);

int fsa4480_unreg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_unreg_notifier);

/* ---- geni_* (1) ---- */
int geni_gsi_common_request_channel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(geni_gsi_common_request_channel);

/* ---- get_* (26) ---- */
void * get_adc_tm_gen3(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_adc_tm_gen3);

void * get_bootprof_pointer(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_bootprof_pointer);

void * get_dmabuf_debugfs_data(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(get_dmabuf_debugfs_data);

void * get_hw_build_adc(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_build_adc);

void * get_hw_country_version(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_country_version);

void * get_hw_id_value(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_id_value);

void * get_hw_project_adc(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_project_adc);

void * get_hw_version_build(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_version_build);

void * get_hw_version_major(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_version_major);

void * get_hw_version_minor(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_version_minor);

void * get_hw_version_platform(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_hw_version_platform);

void * get_log_count(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_log_count);

void * get_matching_swr_slave_device(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_matching_swr_slave_device);

void * get_qcom_scmi_device(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_qcom_scmi_device);

void * get_qptm_by_powerzone(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_qptm_by_powerzone);

void * get_qts_data_helper(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_qts_data_helper);

void * get_random_u16(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_random_u16);

void * get_random_u32(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_random_u32);

void * get_random_u8(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_random_u8);

void * get_raw_data_base(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_raw_data_base);

void * get_si_object(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_si_object);

void * get_slabinfo(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(get_slabinfo);

void * get_spss_image_size(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_spss_image_size);

void * get_telemetry_counter_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_telemetry_counter_name);

void * get_telemetry_counter_value(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_telemetry_counter_value);

void * get_xiaomi_touch_class(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(get_xiaomi_touch_class);

/* ---- gh_* (47) ---- */
int gh_dbl_read_and_clean(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_dbl_read_and_clean);

int gh_dbl_rx_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_dbl_rx_register);

void gh_dbl_rx_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_dbl_rx_unregister);

int gh_dbl_send(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_dbl_send);

int gh_dbl_tx_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_dbl_tx_register);

void gh_dbl_tx_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_dbl_tx_unregister);

void * gh_get_virt_time_offset(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(gh_get_virt_time_offset);

int gh_irq_accept(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_accept);

int gh_irq_accept_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_accept_notify);

int gh_irq_lend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_lend);

int gh_irq_lend_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_lend_notify);

int gh_irq_lend_v2(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_lend_v2);

int gh_irq_reclaim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_reclaim);

void gh_irq_release(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_irq_release);

int gh_irq_release_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_release_notify);

int gh_irq_wait_for_lend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_wait_for_lend);

int gh_irq_wait_for_lend_v2(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gh_irq_wait_for_lend_v2);

int gh_mem_notifier_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_mem_notifier_register);

void gh_mem_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_mem_notifier_unregister);

int gh_msgq_recv(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(gh_msgq_recv);

int gh_msgq_recv_killable(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(gh_msgq_recv_killable);

int gh_msgq_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_msgq_register);

int gh_msgq_send(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gh_msgq_send);

void gh_msgq_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_msgq_unregister);

int gh_panic_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_panic_notifier_register);

void gh_panic_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_panic_notifier_unregister);

int gh_poll_vcpu_run(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_poll_vcpu_run);

void gh_rm_console_close(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_rm_console_close);

int gh_rm_console_flush(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_console_flush);

int gh_rm_console_open(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_console_open);

int gh_rm_console_write(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_console_write);

void * gh_rm_get_vm_name(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(gh_rm_get_vm_name);

int gh_rm_irq_to_virq(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_irq_to_virq);

int gh_rm_mem_accept(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_mem_accept);

int gh_rm_mem_notify(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_mem_notify);

void gh_rm_mem_release(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_rm_mem_release);

int gh_rm_register_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_register_notifier);

int gh_rm_unregister_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_unregister_notifier);

int gh_rm_virq_to_irq(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_virq_to_irq);

void * gh_rm_vm_get_hyp_res(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(gh_rm_vm_get_hyp_res);

int gh_rm_vm_irq_accept(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_accept);

int gh_rm_vm_irq_accept_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_accept_notify);

int gh_rm_vm_irq_lend(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_lend);

int gh_rm_vm_irq_lend_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_lend_notify);

int gh_rm_vm_irq_reclaim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_reclaim);

void gh_rm_vm_irq_release(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gh_rm_vm_irq_release);

int gh_rm_vm_irq_release_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gh_rm_vm_irq_release_notify);

/* ---- ghd_* (4) ---- */
void * ghd_rm_get_vmid(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(ghd_rm_get_vmid);

int ghd_rm_mem_lend(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_lend);

int ghd_rm_mem_reclaim(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_reclaim);

int ghd_rm_mem_share(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_share);

/* ---- glink_* (1) ---- */
int glink_native_pm_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(glink_native_pm_ops);

/* ---- gpi_* (2) ---- */
int gpi_dump_for_geni(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gpi_dump_for_geni);

int gpi_update_multi_desc_flag(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gpi_update_multi_desc_flag);

/* ---- gpr_* (6) ---- */
int __gpr_driver_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(__gpr_driver_register);

void gpr_driver_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(gpr_driver_unregister);

void * gpr_get_modem_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(gpr_get_modem_state);

void * gpr_get_q6_state(void)
{
	return NULL;
}
EXPORT_SYMBOL(gpr_get_q6_state);

int gpr_set_modem_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gpr_set_modem_state);

int gpr_set_q6_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gpr_set_q6_state);

/* ---- gsi_* (6) ---- */
int gsi_common_fill_tre_buf(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(gsi_common_fill_tre_buf);

int gsi_common_prep_desc_and_submit(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gsi_common_prep_desc_and_submit);

int gsi_common_tre_process(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gsi_common_tre_process);

int gsi_common_tx_tre_optimization(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(gsi_common_tx_tre_optimization);

int gsi_dump_ch_scratch(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gsi_dump_ch_scratch);

int gsi_status_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(gsi_status_enabled);

/* ---- has_* (2) ---- */
bool has_subsystem_slept(void)
{
	return false;
}
EXPORT_SYMBOL(has_subsystem_slept);

bool has_system_slept(void *a0)
{
	return false;
}
EXPORT_SYMBOL(has_system_slept);

/* ---- hfi_* (13) ---- */
int hfi_core_allocate_shared_mem(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_allocate_shared_mem);

int hfi_core_close_session(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_close_session);

int hfi_core_cmds_rx_buf_get(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_cmds_rx_buf_get);

int hfi_core_cmds_tx_buf_get(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_cmds_tx_buf_get);

int hfi_core_cmds_tx_buf_send(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_cmds_tx_buf_send);

int hfi_core_cmds_tx_device_buf_send(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_cmds_tx_device_buf_send);

int hfi_core_deallocate_shared_mem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_deallocate_shared_mem);

int hfi_core_map_sg_table(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_map_sg_table);

int hfi_core_notify_rsp_timeout(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_notify_rsp_timeout);

int hfi_core_open_session(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_open_session);

int hfi_core_release_rx_buffer(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_release_rx_buffer);

int hfi_core_release_tx_buffer(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_release_tx_buffer);

int hfi_core_unmap_iova(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(hfi_core_unmap_iova);

/* ---- hw_* (2) ---- */
int hw_monitor_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hw_monitor_notifier_register);

void hw_monitor_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hw_monitor_notifier_unregister);

/* ---- hwmon_* (1) ---- */
int hwmon_device_register_for_thermal(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hwmon_device_register_for_thermal);

/* ---- hyp_* (1) ---- */
int hyp_assign_table(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(hyp_assign_table);

/* ---- hypsys_* (5) ---- */
int hypsys_event_add_int(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_add_int);

int hypsys_event_add_str(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_add_str);

void * hypsys_event_alloc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(hypsys_event_alloc);

void hypsys_event_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hypsys_event_destroy);

int hypsys_event_report(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_report);

/* ---- ieee802_* (1) ---- */
int ieee802_11_parse_elems_full(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ieee802_11_parse_elems_full);

/* ---- init_* (3) ---- */
int init_si_mem_object_sg(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(init_si_mem_object_sg);

int init_si_mem_object_user(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(init_si_mem_object_user);

int init_si_object_user(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(init_si_object_user);

/* ---- ipa_* (6) ---- */
int ipa_exit_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ipa_exit_callback);

int ipa_ready_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ipa_ready_callback);

int ipa_xr_wdi_opt_dpath_add_filter_req(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(ipa_xr_wdi_opt_dpath_add_filter_req);

int ipa_xr_wdi_opt_dpath_remove_all_filter_req(void)
{
	return 0;
}
EXPORT_SYMBOL(ipa_xr_wdi_opt_dpath_remove_all_filter_req);

int ipa_xr_wdi_opt_dpath_remove_filter_req(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(ipa_xr_wdi_opt_dpath_remove_filter_req);

int ipa_xr_wdi_opt_dpath_rsrv_filter_req(void)
{
	return 0;
}
EXPORT_SYMBOL(ipa_xr_wdi_opt_dpath_rsrv_filter_req);

/* ---- ipc_* (4) ---- */
void * ipc_log_context_create(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(ipc_log_context_create);

void ipc_log_context_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(ipc_log_context_destroy);

int ipc_log_extract(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(ipc_log_extract);

void ipc_log_string(void *ctxt, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(ipc_log_string);

/* ---- is_* (6) ---- */
bool is_dma_buf_file(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_dma_buf_file);

bool is_mem_buf_dma_buf(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_mem_buf_dma_buf);

bool is_mem_object(void)
{
	return false;
}
EXPORT_SYMBOL(is_mem_object);

bool is_mi_dev_support_nova(void)
{
	return false;
}
EXPORT_SYMBOL(is_mi_dev_support_nova);

bool is_nlpid_valid(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_nlpid_valid);

bool is_qos_task(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_qos_task);

/* ---- kern_* (1) ---- */
int kern_qi_set_qos(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(kern_qi_set_qos);

/* ---- kernel_* (1) ---- */
int kernel_cpustat(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kernel_cpustat);

/* ---- kgsl_* (5) ---- */
int kgsl_add_rcu_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_add_rcu_notifier);

int kgsl_del_rcu_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_del_rcu_notifier);

int kgsl_gpu_frame_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_frame_count);

int kgsl_gpu_num_freqs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_num_freqs);

int kgsl_gpu_stat(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_stat);

/* ---- ksoftirq_* (1) ---- */
int ksoftirqd(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ksoftirqd);

/* ---- kstrtoint_* (1) ---- */
int kstrtoint_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtoint_from_user);

/* ---- kstrtos8_* (1) ---- */
int kstrtos8_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtos8_from_user);

/* ---- kstrtou16_* (1) ---- */
int kstrtou16_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtou16_from_user);

/* ---- kstrtou8_* (1) ---- */
int kstrtou8_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtou8_from_user);

/* ---- kstrtouint_* (1) ---- */
int kstrtouint_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtouint_from_user);

/* ---- kstrtoul_* (1) ---- */
int kstrtoul_from_user(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(kstrtoul_from_user);

/* ---- llc_* (1) ---- */
void * llc_stats_get_active_scids(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(llc_stats_get_active_scids);

/* ---- llcc_* (2) ---- */
int llcc_configure_staling_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(llcc_configure_staling_mode);

int llcc_notif_staling_inc_counter(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(llcc_notif_staling_inc_counter);

/* ---- lpass_* (27) ---- */
bool lpass_cdc_check_core_votes(void *a0)
{
	return false;
}
EXPORT_SYMBOL(lpass_cdc_check_core_votes);

int lpass_cdc_clear_amic_tx_hold(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_clear_amic_tx_hold);

int lpass_cdc_clk_rsc_enable_all_clocks(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_clk_rsc_enable_all_clocks);

int lpass_cdc_clk_rsc_fs_gen_request(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_clk_rsc_fs_gen_request);

int lpass_cdc_clk_rsc_request_clock(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_clk_rsc_request_clock);

int lpass_cdc_dmic_clk_enable(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_dmic_clk_enable);

void * lpass_cdc_get_device_ptr(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(lpass_cdc_get_device_ptr);

void * lpass_cdc_get_rsc_clk_device_ptr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(lpass_cdc_get_rsc_clk_device_ptr);

void * lpass_cdc_get_version(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(lpass_cdc_get_version);

int lpass_cdc_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_info_create_codec_entry);

bool lpass_cdc_is_va_macro_registered(void *a0)
{
	return false;
}
EXPORT_SYMBOL(lpass_cdc_is_va_macro_registered);

int lpass_cdc_load_compander_coeff(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_load_compander_coeff);

int lpass_cdc_notify_wcd_rx_clk(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_notify_wcd_rx_clk);

int lpass_cdc_register_event_listener(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_register_event_listener);

int lpass_cdc_register_macro(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_register_macro);

int lpass_cdc_register_res_clk(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_register_res_clk);

int lpass_cdc_register_wake_irq(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_register_wake_irq);

void lpass_cdc_rsc_clk_reset(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(lpass_cdc_rsc_clk_reset);

int lpass_cdc_runtime_resume(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_runtime_resume);

int lpass_cdc_runtime_suspend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_runtime_suspend);

int lpass_cdc_rx_set_fir_capability(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_rx_set_fir_capability);

int lpass_cdc_set_port_map(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_set_port_map);

int lpass_cdc_tx_mclk_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_tx_mclk_enable);

int lpass_cdc_unregister_macro(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_unregister_macro);

int lpass_cdc_unregister_res_clk(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_unregister_res_clk);

int lpass_cdc_update_compander_setting(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_update_compander_setting);

int lpass_cdc_wsa_pa_on(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(lpass_cdc_wsa_pa_on);

/* ---- lpd_* (1) ---- */
bool lpd_is_charging_limit(void)
{
	return false;
}
EXPORT_SYMBOL(lpd_is_charging_limit);

/* ---- map_* (1) ---- */
int map_debug_bases(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(map_debug_bases);

/* ---- matt_* (3) ---- */
int matt_register_ulp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(matt_register_ulp);

int matt_trace_msg(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(matt_trace_msg);

int matt_unregister_ulp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(matt_unregister_ulp);

/* ---- mca_* (94) ---- */
int __mca_log_debug(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_debug);

int __mca_log_err(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_err);

int __mca_log_info(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_info);

int mca_adsp_glink_read_prop(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_read_prop);

int mca_adsp_glink_resister_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_resister_ops);

int mca_adsp_glink_write_prop(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_write_prop);

int mca_bmd_force_detection(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_bmd_force_detection);

bool mca_bmd_is_batt_missing(void)
{
	return false;
}
EXPORT_SYMBOL(mca_bmd_is_batt_missing);

void mca_cancel_delayed_work(void *dwork)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_cancel_delayed_work);

void mca_cancel_work(void *work)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_cancel_work);

int mca_charge_if_ops_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_if_ops_register);

int mca_charge_mievent_report(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_report);

int mca_charge_mievent_set_state(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_set_state);

int mca_create_votable(void *dev, const char *name, int type, int *out, void *cb)
{
	return 0;
}
EXPORT_SYMBOL(mca_create_votable);

int mca_debugfs_create_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_debugfs_create_group);

int mca_destroy_votable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_destroy_votable);

int mca_event_block_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify);

int mca_event_block_notify_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify_register);

void mca_event_block_notify_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_event_block_notify_unregister);

int mca_event_report_multiple_uevent(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_multiple_uevent);

int mca_event_report_uevent(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_uevent);

void * mca_find_votable(const char *name)
{
	return NULL;
}
EXPORT_SYMBOL(mca_find_votable);

void * mca_get_client_vote(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_client_vote);

void * mca_get_client_vote_locked(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_client_vote_locked);

void * mca_get_effective_client(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_client);

void * mca_get_effective_client_locked(void *votable)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_client_locked);

void * mca_get_effective_result(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_result);

int mca_get_effective_result_locked(void *votable)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_result_locked);

void * mca_get_hwid_info(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_hwid_info);

void mca_get_wls_charger_thermal_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_get_wls_charger_thermal_remove);

bool mca_is_client_vote_enabled(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled);

bool mca_is_client_vote_enabled_locked(void *votable, void *client)
{
	return false;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled_locked);

bool mca_is_override_vote_enabled(void *votable)
{
	return false;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled);

bool mca_is_override_vote_enabled_locked(void *votable)
{
	return false;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled_locked);

void mca_lock_votable(void *votable)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_lock_votable);

int mca_log_charge_log_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_log_charge_log_register);

void * mca_log_get_charge_boot_mode(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_log_get_charge_boot_mode);

void * mca_log_get_rtc_time(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_log_get_rtc_time);

int mca_mod_delayed_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_mod_delayed_work);

bool mca_panel_get_hbm_state(void)
{
	return false;
}
EXPORT_SYMBOL(mca_panel_get_hbm_state);

int mca_panel_get_screen_state(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_panel_get_screen_state);

int mca_parse_dts_count_strings(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_count_strings);

int mca_parse_dts_s32(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_s32);

int mca_parse_dts_string(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string);

int mca_parse_dts_string_array(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_array);

int mca_parse_dts_string_index(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_index);

int mca_parse_dts_u32(void *np, const char *name, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32);

int mca_parse_dts_u32_array(void *np, const char *name, int *out, int n)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_array);

int mca_parse_dts_u32_count(void *np, const char *name, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_count);

int mca_parse_dts_u32_index(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_index);

int mca_parse_dts_u8(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8);

int mca_parse_dts_u8_array(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_array);

int mca_parse_dts_u8_count(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_count);

int mca_path_control_enable_gate(void *ctrl, bool en)
{
	return 0;
}
EXPORT_SYMBOL(mca_path_control_enable_gate);

bool mca_qcom_smem_is_zero_speed(void)
{
	return false;
}
EXPORT_SYMBOL(mca_qcom_smem_is_zero_speed);

int mca_queue_delayed_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_delayed_work);

int mca_queue_work(void *wq, void *work)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_work);

int mca_rerun_election(int id)
{
	return 0;
}
EXPORT_SYMBOL(mca_rerun_election);

void mca_set_wls_charger_thermal_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_set_wls_charger_thermal_remove);

int mca_smartchg_get_board_temp(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_board_temp);

void * mca_smartchg_get_limit_soc(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_smartchg_get_limit_soc);

int mca_smartchg_get_scene(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_scene);

int mca_smartchg_if_ops_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_if_ops_register);

bool mca_smartchg_is_extreme_cold_enabled(void)
{
	return false;
}
EXPORT_SYMBOL(mca_smartchg_is_extreme_cold_enabled);

int mca_smartchg_set_batt_emerg_soc_limit(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_batt_emerg_soc_limit);

int mca_smartchg_set_board_temp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_board_temp);

int mca_smartchg_set_scene(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_scene);

void * mca_strategy_func_get_status(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(mca_strategy_func_get_status);

int mca_strategy_func_process(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_process);

int mca_strategy_func_set_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_set_config);

bool mca_strategy_is_support_pps_100w(void)
{
	return false;
}
EXPORT_SYMBOL(mca_strategy_is_support_pps_100w);

int mca_strategy_ops_register(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_ops_register);

void * mca_subpmic_proxy_get_otg_wls_mutex(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_subpmic_proxy_get_otg_wls_mutex);

int mca_sysfs_create_files(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_files);

int mca_sysfs_create_group(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_group);

int mca_sysfs_create_link_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_link_group);

int mca_sysfs_init_attrs(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_init_attrs);

int mca_sysfs_lookup_attr(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_lookup_attr);

int mca_sysfs_remove_group(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_remove_group);

int mca_sysfs_remove_link_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_remove_link_group);

void mca_unlock_votable(void *votable)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_unlock_votable);

int mca_vote(void *votable, void *client, int val, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote);

int mca_vote_override(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote_override);

int mca_wireless_rev_enable_reverse_charge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_enable_reverse_charge);

int mca_wireless_rev_get_firmware_state(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_firmware_state);

void * mca_wireless_rev_get_rev_boost_default(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_rev_boost_default);

void * mca_wireless_rev_get_reverse_chg(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg);

void * mca_wireless_rev_get_reverse_chg_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg_state);

bool mca_wireless_rev_get_user_reverse_chg(void)
{
	return false;
}
EXPORT_SYMBOL(mca_wireless_rev_get_user_reverse_chg);

int mca_wireless_rev_set_firmware_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_firmware_state);

int mca_wireless_rev_set_reverse_chg(bool en)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_reverse_chg);

int mca_wireless_rev_set_user_reverse_chg(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_user_reverse_chg);

int mca_wireless_rev_set_wired_chg_ok(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_wired_chg_ok);

int mca_wireless_rev_update_fw_version(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_update_fw_version);

/* ---- mem_* (8) ---- */
int mem_buf_current_vmid(void)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_current_vmid);

int mem_buf_dma_buf_copy_vmperm(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_dma_buf_copy_vmperm);

int mem_buf_dma_buf_exclusive_owner(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_dma_buf_exclusive_owner);

void * mem_buf_dma_buf_get_memparcel_hdl(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mem_buf_dma_buf_get_memparcel_hdl);

void * mem_buf_dma_buf_get_vmperm(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(mem_buf_dma_buf_get_vmperm);

int mem_buf_dma_buf_set_destructor(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_dma_buf_set_destructor);

int mem_buf_lend(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mem_buf_lend);

int mem_object_to_dma_buf(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mem_object_to_dma_buf);

/* ---- memcheck_* (5) ---- */
int memcheck_ashmem_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_ashmem_info_show);

int memcheck_cma_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_cma_info_show);

int memcheck_dmabuf_info_show(void)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_dmabuf_info_show);

int memcheck_slab_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_slab_info_show);

int memcheck_vmalloc_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_vmalloc_info_show);

/* ---- memdup_* (1) ---- */
int memdup_user_trace(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(memdup_user_trace);

/* ---- memory_* (2) ---- */
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

/* ---- mhi_* (30) ---- */
int mhi_bdf_to_controller(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_bdf_to_controller);

void * mhi_controller_get_base(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_controller_get_base);

void * mhi_controller_get_numeric_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_controller_get_numeric_id);

void * mhi_controller_get_privdata(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_controller_get_privdata);

int mhi_controller_set_base(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_set_base);

int mhi_controller_set_bw_scale_cb(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_set_bw_scale_cb);

int mhi_controller_set_loglevel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_set_loglevel);

int mhi_controller_set_privdata(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_set_privdata);

int mhi_controller_set_sfr_support(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_set_sfr_support);

int mhi_controller_setup_timesync(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_controller_setup_timesync);

void mhi_debug_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mhi_debug_reg_dump);

int mhi_device_configure(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mhi_device_configure);

void * mhi_device_get_sync_atomic(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_device_get_sync_atomic);

int mhi_device_ioctl(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mhi_device_ioctl);

int mhi_dump_sfr(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_dump_sfr);

void mhi_force_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mhi_force_reset);

void * mhi_get_channel_db_base(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_channel_db_base);

void * mhi_get_device_for_channel(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_device_for_channel);

void * mhi_get_event_ring_db_base(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_event_ring_db_base);

void * mhi_get_remote_time(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_remote_time);

void * mhi_get_remote_time_sync(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_remote_time_sync);

void * mhi_get_soc_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mhi_get_soc_info);

int mhi_host_notify_db_disable_trace(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_host_notify_db_disable_trace);

int mhi_pm_fast_resume(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_pm_fast_resume);

int mhi_pm_fast_suspend(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_pm_fast_suspend);

int mhi_report_error(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_report_error);

int mhi_scan_rddm_cookie(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_scan_rddm_cookie);

int mhi_set_m2_timeout_ms(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mhi_set_m2_timeout_ms);

int mhi_start_transfer(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_start_transfer);

int mhi_stop_transfer(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mhi_stop_transfer);

/* ---- mi_* (24) ---- */
int mi_dflt_bwmon_update_cur_freq_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_bwmon_update_cur_freq_hook);

int mi_dflt_calculate_dflt_lantancy_hook(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_dflt_lantancy_hook);

int mi_dflt_calculate_mon_sampling_freq_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_mon_sampling_freq_hook);

void * mi_dflt_get_bwmon_enable(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_enable);

void * mi_dflt_get_bwmon_sample_start(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_sample_start);

void * mi_dflt_get_latency_enable(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable);

void * mi_dflt_get_latency_enable_from_user(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable_from_user);

void * mi_dflt_get_latency_vote_start(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_vote_start);

int mi_dflt_process_raw_ctrs_hook(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_process_raw_ctrs_hook);

int mi_dflt_set_bwmon_sample_start(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_bwmon_sample_start);

int mi_dflt_set_latency_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_enable);

int mi_dflt_set_latency_vote_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_vote_start);

int mi_dflt_update_memlat_fp_vote_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_update_memlat_fp_vote_hook);

int mi_display_gesture_callback_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_gesture_callback_register);

int mi_display_pwrkey_callback_set(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_pwrkey_callback_set);

int mi_dsi_panel_lockdown_info_read(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read);

int mi_dsi_panel_lockdown_info_read_p8(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_p8);

int mi_dsi_panel_lockdown_info_read_q81(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_q81);

int mi_scsi_execute_cmd(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(mi_scsi_execute_cmd);

int mi_smart_refill_dynamic_page_pool_refill(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_dynamic_page_pool_refill);

void mi_smart_refill_exit(void)
{
	/* no-op */
}
EXPORT_SYMBOL(mi_smart_refill_exit);

int mi_smart_refill_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_init);

int mi_smart_refill_pools_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_pools_init);

int mi_smart_refill_update(void)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_update);

/* ---- mist_* (1) ---- */
int mist_ddr_vote_enable(void)
{
	return 0;
}
EXPORT_SYMBOL(mist_ddr_vote_enable);

/* ---- mitee_* (3) ---- */
int mitee_smc_notify_connect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_connect);

int mitee_smc_notify_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_data);

int mitee_smc_notify_signal(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_signal);

/* ---- miui_* (1) ---- */
int miui_cluster_packing_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(miui_cluster_packing_callback);

/* ---- mmrm_* (7) ---- */
bool mmrm_client_check_scaling_supported(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(mmrm_client_check_scaling_supported);

int mmrm_client_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_deregister);

void * mmrm_client_get_clk_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mmrm_client_get_clk_count);

void * mmrm_client_get_value(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mmrm_client_get_value);

int mmrm_client_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_register);

int mmrm_client_set_value(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_set_value);

int mmrm_client_set_value_in_range(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_set_value_in_range);

/* ---- msc_* (12) ---- */
void * msc_system_get_device_capability(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_device_capability);

void * msc_system_get_mpam_version(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_mpam_version);

void * msc_system_get_partition(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_partition);

int msc_system_mon_alloc_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_alloc_info);

int msc_system_mon_be_bw_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_be_bw_info);

int msc_system_mon_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_config);

int msc_system_mon_fe_bw_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_fe_bw_info);

int msc_system_mon_read_all(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_read_all);

int msc_system_mon_read_miss_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_read_miss_info);

int msc_system_mon_stats_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_stats_read);

int msc_system_reset_partition(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_reset_partition);

int msc_system_set_partition(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_set_partition);

/* ---- msm_* (130) ---- */
int msm_adreno_tz_reinit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_adreno_tz_reinit);

int msm_aud_evt_blocking_notifier_call_chain(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_blocking_notifier_call_chain);

int msm_aud_evt_blocking_register_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_blocking_register_client);

int msm_aud_evt_blocking_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_blocking_unregister_client);

int msm_aud_evt_notifier_call_chain(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_notifier_call_chain);

int msm_aud_evt_register_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_register_client);

int msm_aud_evt_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_aud_evt_unregister_client);

void * msm_audio_get_handle_from_phy_addr(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msm_audio_get_handle_from_phy_addr);

void * msm_audio_get_phy_addr(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msm_audio_get_phy_addr);

int msm_audio_ion_crash_handler(void)
{
	return 0;
}
EXPORT_SYMBOL(msm_audio_ion_crash_handler);

bool msm_cdc_check_supply_vote(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return false;
}
EXPORT_SYMBOL(msm_cdc_check_supply_vote);

int msm_cdc_disable_ondemand_supply(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_disable_ondemand_supply);

int msm_cdc_disable_static_supplies(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_disable_static_supplies);

int msm_cdc_enable_ondemand_supply(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_enable_ondemand_supply);

int msm_cdc_enable_static_supplies(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_enable_static_supplies);

int msm_cdc_enable_wcd_supply(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_enable_wcd_supply);

void * msm_cdc_get_gpio_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(msm_cdc_get_gpio_state);

void * msm_cdc_get_power_supplies(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msm_cdc_get_power_supplies);

int msm_cdc_init_supplies(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_init_supplies);

int msm_cdc_init_supplies_v2(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_init_supplies_v2);

int msm_cdc_init_wcd_supply(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_init_wcd_supply);

bool msm_cdc_is_ondemand_supply(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return false;
}
EXPORT_SYMBOL(msm_cdc_is_ondemand_supply);

int msm_cdc_pinctrl_enable_vreg_for_dmic(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_enable_vreg_for_dmic);

void * msm_cdc_pinctrl_get_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_get_state);

int msm_cdc_pinctrl_select_active_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_select_active_state);

int msm_cdc_pinctrl_select_alt_active_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_select_alt_active_state);

int msm_cdc_pinctrl_select_sleep_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_select_sleep_state);

int msm_cdc_pinctrl_set_wakeup_capable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_pinctrl_set_wakeup_capable);

int msm_cdc_release_supplies(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_release_supplies);

int msm_cdc_set_supplies_lpm_mode(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_set_supplies_lpm_mode);

int msm_cdc_set_supply_min_voltage(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_set_supply_min_voltage);

int msm_cdc_supply_supports_retention_mode(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_cdc_supply_supports_retention_mode);

int msm_common_vote_against_sleep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_common_vote_against_sleep);

void msm_cvp_close(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_cvp_close);

int msm_cvp_debug(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_debug);

int msm_cvp_debug_out(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_debug_out);

int msm_cvp_load_u32_table(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_load_u32_table);

int msm_cvp_open(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_open);

int msm_cvp_poll(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_poll);

int msm_cvp_private(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_private);

int msm_cvp_suspend(void)
{
	return 0;
}
EXPORT_SYMBOL(msm_cvp_suspend);

int msm_data_fifo_config(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_data_fifo_config);

int msm_dma_unmap_all_for_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dma_unmap_all_for_dev);

int msm_dss_clean_io_irq(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_clean_io_irq);

int msm_dss_clean_io_mem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_clean_io_mem);

int msm_dss_clk_set_rate(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_clk_set_rate);

int msm_dss_enable_clk(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_enable_clk);

int msm_dss_enable_gpio(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_enable_gpio);

int msm_dss_enable_vreg(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_enable_vreg);

void * msm_dss_get_clk(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_clk);

void * msm_dss_get_gpio_io_mem(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_gpio_io_mem);

void * msm_dss_get_io_irq(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_io_irq);

void * msm_dss_get_io_mem(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_io_mem);

void * msm_dss_get_pmic_io_mem(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_pmic_io_mem);

void * msm_dss_get_vreg(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(msm_dss_get_vreg);

int msm_dss_ioremap_byname(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_ioremap_byname);

int msm_dss_iounmap(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_iounmap);

int msm_dss_mmrm_deregister(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_mmrm_deregister);

int msm_dss_mmrm_register(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_mmrm_register);

int msm_dss_put_clk(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_put_clk);

int msm_dss_single_clk_set_rate(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dss_single_clk_set_rate);

int msm_dump_data_register_nominidump(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_dump_data_register_nominidump);

int msm_dwc3_reset_dbm_ep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_dwc3_reset_dbm_ep);

int msm_ep_clear_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_ep_clear_ops);

int msm_ep_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_ep_config);

int msm_ep_set_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_ep_set_mode);

int msm_ep_unconfig(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_ep_unconfig);

int msm_ep_update_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_ep_update_ops);

int msm_ext_disp_deregister_intf(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_ext_disp_deregister_intf);

int msm_ext_disp_register_audio_codec(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_ext_disp_register_audio_codec);

int msm_ext_disp_register_intf(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_ext_disp_register_intf);

int msm_ext_disp_select_audio_codec(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_ext_disp_select_audio_codec);

void * msm_gpio_get_pin_address(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(msm_gpio_get_pin_address);

int msm_gpio_mpm_wake_set(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_gpio_mpm_wake_set);

int msm_hdcp_cache_repeater_topology(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_hdcp_cache_repeater_topology);

int msm_hdcp_notify_topology(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_hdcp_notify_topology);

int msm_hdcp_register_cb(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_hdcp_register_cb);

void * msm_hw_fence_create(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(msm_hw_fence_create);

int msm_hw_fence_deregister(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_deregister);

int msm_hw_fence_deregister_error_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_deregister_error_cb);

void msm_hw_fence_destroy(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_hw_fence_destroy);

int msm_hw_fence_destroy_with_handle(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_destroy_with_handle);

int msm_hw_fence_driver_doorbell_sim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_driver_doorbell_sim);

int msm_hw_fence_dump_debug_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_dump_debug_data);

int msm_hw_fence_dump_fence(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_dump_fence);

int msm_hw_fence_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_register);

int msm_hw_fence_register_error_cb(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_register_error_cb);

int msm_hw_fence_reset_client(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_reset_client);

int msm_hw_fence_reset_client_by_id(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_reset_client_by_id);

int msm_hw_fence_trigger_signal(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_trigger_signal);

int msm_hw_fence_update_txq(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_update_txq);

int msm_hw_fence_update_txq_error(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_update_txq_error);

int msm_hw_fence_wait_update(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_wait_update);

int msm_hw_fence_wait_update_v2(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(msm_hw_fence_wait_update_v2);

int msm_ioctl_rmfb2(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_ioctl_rmfb2);

int msm_minidump_add_region(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_minidump_add_region);

int msm_minidump_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(msm_minidump_enabled);

int msm_minidump_remove_region(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_minidump_remove_region);

int msm_msi_config(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_msi_config);

int msm_msi_config_access(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_msi_config_access);

int msm_msi_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_msi_init);

int msm_pcie_allow_l1(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_allow_l1);

int msm_pcie_debug_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_debug_info);

int msm_pcie_deregister_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_deregister_event);

int msm_pcie_enumerate(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_enumerate);

int msm_pcie_fmd_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_fmd_enable);

void msm_pcie_l1ss_timeout_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_pcie_l1ss_timeout_disable);

int msm_pcie_l1ss_timeout_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_l1ss_timeout_enable);

int msm_pcie_pm_control(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_pm_control);

int msm_pcie_prevent_l1(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_prevent_l1);

void msm_pcie_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_pcie_reg_dump);

int msm_pcie_register_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_register_event);

int msm_pcie_set_link_bandwidth(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_set_link_bandwidth);

int msm_pcie_set_target_link_speed(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_pcie_set_target_link_speed);

int msm_perf_events_update(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(msm_perf_events_update);

int msm_qdss_csr_disable_bam_to_usb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_disable_bam_to_usb);

int msm_qdss_csr_disable_eth(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_disable_eth);

int msm_qdss_csr_disable_flush(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_disable_flush);

int msm_qdss_csr_enable_bam_to_usb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_enable_bam_to_usb);

int msm_qdss_csr_enable_eth(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_enable_eth);

int msm_qdss_csr_enable_flush(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_qdss_csr_enable_flush);

int msm_qup_write(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_qup_write);

int msm_register_fence_error_event(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msm_register_fence_error_event);

int msm_register_vm_event(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(msm_register_vm_event);

int msm_unregister_fence_error_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_unregister_fence_error_event);

int msm_unregister_vm_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(msm_unregister_vm_event);

int msm_vidc_enable_bugon(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_vidc_enable_bugon);

void msm_vidc_fw_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_vidc_fw_dump);

int msm_vidc_lossless_encode(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msm_vidc_lossless_encode);

void msm_vidc_syscache_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(msm_vidc_syscache_disable);

/* ---- ncm_* (6) ---- */
int ncm_ipa_cleanup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_cleanup);

int ncm_ipa_cleanup_module(void)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_cleanup_module);

int ncm_ipa_init(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_init);

int ncm_ipa_init_module(void)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_init_module);

int ncm_ipa_pipe_connect_notify(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_pipe_connect_notify);

int ncm_ipa_pipe_disconnect_notify(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_pipe_disconnect_notify);

/* ---- netdev_* (2) ---- */
int netdev_err(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(netdev_err);

int netdev_info(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(netdev_info);

/* ---- nfc_* (1) ---- */
int nfc_to_touch_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(nfc_to_touch_event);

/* ---- notify_* (1) ---- */
int notify_raw_data_update(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(notify_raw_data_update);

/* ---- nvt_* (1) ---- */
void * nvt_get_lcm_id_notify(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(nvt_get_lcm_id_notify);

/* ---- oem_* (1) ---- */
int oem_corectl_cpu_busy(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(oem_corectl_cpu_busy);

/* ---- of_* (2) ---- */
void * of_get_coresight_csr_name(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(of_get_coresight_csr_name);

int of_register_swr_devices(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(of_register_swr_devices);

/* ---- override_* (1) ---- */
int override_creds(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(override_creds);

/* ---- panel_* (3) ---- */
int panel_event_notification_trigger(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(panel_event_notification_trigger);

int panel_event_notifier_register(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(panel_event_notifier_register);

void panel_event_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(panel_event_notifier_unregister);

/* ---- param_* (10) ---- */
void * param_get_int(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(param_get_int);

void * param_get_uint(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(param_get_uint);

void * param_get_ullong(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(param_get_ullong);

int param_ops_int(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(param_ops_int);

int param_ops_long(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(param_ops_long);

int param_ops_uint(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(param_ops_uint);

int param_ops_ullong(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(param_ops_ullong);

int param_ops_ulong(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(param_ops_ulong);

int param_set_int(void)
{
	return 0;
}
EXPORT_SYMBOL(param_set_int);

int param_set_uint(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(param_set_uint);

/* ---- pcie_* (1) ---- */
int pcie_pdc_cfg_irq(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(pcie_pdc_cfg_irq);

/* ---- pen_* (2) ---- */
int pen_charge_state_notifier_register_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pen_charge_state_notifier_register_client);

int pen_charge_state_notifier_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pen_charge_state_notifier_unregister_client);

/* ---- phy_* (4) ---- */
void phy_core_exit(void)
{
	/* no-op */
}
EXPORT_SYMBOL(phy_core_exit);

void * phy_get_num_lanes(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(phy_get_num_lanes);

int phy_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(phy_read);

int phy_write(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(phy_write);

/* ---- ping_* (2) ---- */
int ping_subsystem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ping_subsystem);

int ping_subsystem_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(ping_subsystem_init);

/* ---- platform_* (316) ---- */
int platform_bc12_class_ops_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_bc12_class_ops_register);

int platform_class_buckchg_ops_adc_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_adc_enable);

int platform_class_buckchg_ops_enable_hvdcp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_enable_hvdcp);

int platform_class_buckchg_ops_force_dpdm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_force_dpdm);

void * platform_class_buckchg_ops_get_ac_volt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_ac_volt);

void * platform_class_buckchg_ops_get_batt_curr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_batt_curr);

void * platform_class_buckchg_ops_get_batt_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_batt_id);

void * platform_class_buckchg_ops_get_batt_tsns(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_batt_tsns);

void * platform_class_buckchg_ops_get_batt_volt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_batt_volt);

void * platform_class_buckchg_ops_get_batt_volt_sns(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_batt_volt_sns);

void * platform_class_buckchg_ops_get_bus_curr(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_bus_curr);

void * platform_class_buckchg_ops_get_bus_tsns(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_bus_tsns);

void * platform_class_buckchg_ops_get_bus_volt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_bus_volt);

void * platform_class_buckchg_ops_get_chg_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_chg_status);

void * platform_class_buckchg_ops_get_chg_type(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_chg_type);

void * platform_class_buckchg_ops_get_die_temp(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_die_temp);

void * platform_class_buckchg_ops_get_hiz_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_hiz_status);

void * platform_class_buckchg_ops_get_hw_rechg_threshold(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_hw_rechg_threshold);

void * platform_class_buckchg_ops_get_icl_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_icl_status);

void * platform_class_buckchg_ops_get_input_curr_lmt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_input_curr_lmt);

void * platform_class_buckchg_ops_get_input_volt_lmt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_input_volt_lmt);

void * platform_class_buckchg_ops_get_lpd_cc1(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_cc1);

void * platform_class_buckchg_ops_get_lpd_cc2(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_cc2);

void * platform_class_buckchg_ops_get_lpd_control(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_control);

void * platform_class_buckchg_ops_get_lpd_dm(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_dm);

void * platform_class_buckchg_ops_get_lpd_dp(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_dp);

void * platform_class_buckchg_ops_get_lpd_enable(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_enable);

void * platform_class_buckchg_ops_get_lpd_sbu1(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_sbu1);

void * platform_class_buckchg_ops_get_lpd_sbu2(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_sbu2);

void * platform_class_buckchg_ops_get_lpd_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_status);

void * platform_class_buckchg_ops_get_lpd_uart_control(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_lpd_uart_control);

void * platform_class_buckchg_ops_get_online(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_online);

void * platform_class_buckchg_ops_get_otg_boost_enable_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_otg_boost_enable_status);

void * platform_class_buckchg_ops_get_otg_boost_src(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_otg_boost_src);

void * platform_class_buckchg_ops_get_otg_gate_enable_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_otg_gate_enable_status);

void * platform_class_buckchg_ops_get_otg_wls_mutex(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_otg_wls_mutex);

void * platform_class_buckchg_ops_get_ovp_vth(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_ovp_vth);

void * platform_class_buckchg_ops_get_pack_ibat(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_pack_ibat);

void * platform_class_buckchg_ops_get_pack_tbat(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_pack_tbat);

void * platform_class_buckchg_ops_get_pack_vbat(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_pack_vbat);

void * platform_class_buckchg_ops_get_ship_mode(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_ship_mode);

void * platform_class_buckchg_ops_get_sys_volt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_sys_volt);

void * platform_class_buckchg_ops_get_term_curr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_term_curr);

void * platform_class_buckchg_ops_get_term_volt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_term_volt);

void * platform_class_buckchg_ops_get_usb_aicl_cont_thd(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_usb_aicl_cont_thd);

void * platform_class_buckchg_ops_get_usb_input_swap(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_usb_input_swap);

void * platform_class_buckchg_ops_get_usb_sns_volt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_usb_sns_volt);

void * platform_class_buckchg_ops_get_usbin_collapse_rt_sts(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_usbin_collapse_rt_sts);

void * platform_class_buckchg_ops_get_wls_curr(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_wls_curr);

void * platform_class_buckchg_ops_get_wls_input_curr_lmt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_wls_input_curr_lmt);

void * platform_class_buckchg_ops_get_wls_input_swap(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_get_wls_input_swap);

bool platform_class_buckchg_ops_is_charge_done(void *a0)
{
	return false;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_is_charge_done);

bool platform_class_buckchg_ops_is_init_ok(void *a0)
{
	return false;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_is_init_ok);

bool platform_class_buckchg_ops_is_support_cid(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_is_support_cid);

int platform_class_buckchg_ops_kick_wd(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_kick_wd);

int platform_class_buckchg_ops_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_register);

int platform_class_buckchg_ops_request_dpdm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_request_dpdm);

int platform_class_buckchg_ops_set_aicl_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_aicl_enable);

int platform_class_buckchg_ops_set_audio_status(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_audio_status);

int platform_class_buckchg_ops_set_boost_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_boost_enable);

int platform_class_buckchg_ops_set_boost_voltage(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_boost_voltage);

int platform_class_buckchg_ops_set_buck_fsw(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_buck_fsw);

int platform_class_buckchg_ops_set_chg(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_chg);

int platform_class_buckchg_ops_set_en_batt_diffsense(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_en_batt_diffsense);

int platform_class_buckchg_ops_set_eu_model(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_eu_model);

int platform_class_buckchg_ops_set_hiz(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_hiz);

int platform_class_buckchg_ops_set_hw_rechg_threshold(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_hw_rechg_threshold);

int platform_class_buckchg_ops_set_ichg(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_ichg);

int platform_class_buckchg_ops_set_input_curr_lmt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_input_curr_lmt);

int platform_class_buckchg_ops_set_input_volt_lmt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_input_volt_lmt);

int platform_class_buckchg_ops_set_iterm_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_iterm_enable);

int platform_class_buckchg_ops_set_lpd_control(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_lpd_control);

int platform_class_buckchg_ops_set_lpd_sbu1(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_lpd_sbu1);

int platform_class_buckchg_ops_set_lpd_uart_control(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_lpd_uart_control);

int platform_class_buckchg_ops_set_opt_fws(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_opt_fws);

int platform_class_buckchg_ops_set_otg(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_otg);

int platform_class_buckchg_ops_set_otg_curr(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_otg_curr);

int platform_class_buckchg_ops_set_otg_volt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_otg_volt);

int platform_class_buckchg_ops_set_ovp_vth(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_ovp_vth);

int platform_class_buckchg_ops_set_prechg_curr(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_prechg_curr);

int platform_class_buckchg_ops_set_prechg_volt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_prechg_volt);

int platform_class_buckchg_ops_set_qc3_volt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_qc3_volt);

int platform_class_buckchg_ops_set_qc_volt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_qc_volt);

int platform_class_buckchg_ops_set_rerun_aicl(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_rerun_aicl);

int platform_class_buckchg_ops_set_rerun_pmic(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_rerun_pmic);

int platform_class_buckchg_ops_set_restart_aicl(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_restart_aicl);

int platform_class_buckchg_ops_set_screen_status(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_screen_status);

int platform_class_buckchg_ops_set_ship_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_ship_mode);

int platform_class_buckchg_ops_set_term(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_term);

int platform_class_buckchg_ops_set_term_curr(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_term_curr);

int platform_class_buckchg_ops_set_term_volt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_term_volt);

int platform_class_buckchg_ops_set_too_hot_limit(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_too_hot_limit);

int platform_class_buckchg_ops_set_usb_aicl_cont_thd(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_usb_aicl_cont_thd);

int platform_class_buckchg_ops_set_usb_aicl_start_at_max(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_usb_aicl_start_at_max);

int platform_class_buckchg_ops_set_wd_timeout(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_wd_timeout);

int platform_class_buckchg_ops_set_wls_hiz(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_wls_hiz);

int platform_class_buckchg_ops_set_wls_input_curr_lmt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_wls_input_curr_lmt);

int platform_class_buckchg_ops_set_wls_vdd_flag(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_set_wls_vdd_flag);

int platform_class_buckchg_ops_usb_adapter_allow_override(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_buckchg_ops_usb_adapter_allow_override);

int platform_class_cp_device_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_device_init);

int platform_class_cp_dump_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_dump_register);

int platform_class_cp_enable_acdrv_manual(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_acdrv_manual);

int platform_class_cp_enable_adc(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_adc);

int platform_class_cp_enable_busucp(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_busucp);

int platform_class_cp_enable_ovpgate(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_ovpgate);

int platform_class_cp_enable_ovpgate_with_check(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_ovpgate_with_check);

int platform_class_cp_enable_wpcgate(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_enable_wpcgate);

void * platform_class_cp_get_alarm_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_alarm_status);

void * platform_class_cp_get_batovp_th(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_batovp_th);

void * platform_class_cp_get_battery_current(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_battery_current);

void * platform_class_cp_get_battery_present(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_battery_present);

void * platform_class_cp_get_battery_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_battery_temperature);

void * platform_class_cp_get_battery_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_battery_voltage);

void * platform_class_cp_get_bus_current(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_bus_current);

void * platform_class_cp_get_bus_error_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_bus_error_status);

void * platform_class_cp_get_bus_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_bus_temperature);

void * platform_class_cp_get_bus_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_bus_voltage);

void * platform_class_cp_get_bypass_support(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_bypass_support);

void * platform_class_cp_get_charging_enabled(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_charging_enabled);

void * platform_class_cp_get_chip_vendor(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_chip_vendor);

void * platform_class_cp_get_die_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_die_temperature);

void * platform_class_cp_get_errorhl_stat(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_errorhl_stat);

void * platform_class_cp_get_fault_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_fault_status);

void * platform_class_cp_get_fsw(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_fsw);

void * platform_class_cp_get_fsw_step(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_fsw_step);

void * platform_class_cp_get_ibus_delta(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_ibus_delta);

void * platform_class_cp_get_ibus_total(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_ibus_total);

void * platform_class_cp_get_int_stat(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_int_stat);

void * platform_class_cp_get_mode(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_mode);

void * platform_class_cp_get_ovpgate_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_ovpgate_status);

void * platform_class_cp_get_present(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_present);

void * platform_class_cp_get_probe_ok(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_probe_ok);

void * platform_class_cp_get_reg_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_reg_status);

void * platform_class_cp_get_tdie(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_tdie);

void * platform_class_cp_get_usb_voltage(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_usb_voltage);

void * platform_class_cp_get_vbus_present(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_cp_get_vbus_present);

int platform_class_cp_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_register_ops);

int platform_class_cp_set_adjustadble_timeout(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_adjustadble_timeout);

int platform_class_cp_set_batovp_th(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_batovp_th);

int platform_class_cp_set_charging_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_charging_enable);

int platform_class_cp_set_default_fsw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_default_fsw);

int platform_class_cp_set_fsw(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_fsw);

int platform_class_cp_set_manual_revchg_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_manual_revchg_mode);

int platform_class_cp_set_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_mode);

int platform_class_cp_set_pmid2outuvp_th(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_pmid2outuvp_th);

int platform_class_cp_set_present(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_present);

int platform_class_cp_set_qb(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_qb);

int platform_class_cp_set_rcp(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_rcp);

int platform_class_cp_set_revchg(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_revchg);

int platform_class_cp_set_vout2out_uvp(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_cp_set_vout2out_uvp);

void * platform_class_loadsw_get_ibat_limit(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_loadsw_get_ibat_limit);

void * platform_class_loadsw_get_lowpower_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_loadsw_get_lowpower_mode);

void * platform_class_loadsw_get_present(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_loadsw_get_present);

int platform_class_loadsw_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_loadsw_register_ops);

int platform_class_loadsw_set_ibat_limit(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_loadsw_set_ibat_limit);

int platform_class_loadsw_set_lowpower_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_loadsw_set_lowpower_mode);

int platform_class_update_tx_magnetic_case_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_update_tx_magnetic_case_status);

bool platform_class_wireless_check_fw_update(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(platform_class_wireless_check_fw_update);

bool platform_class_wireless_check_i2c_is_ok(void *a0)
{
	return false;
}
EXPORT_SYMBOL(platform_class_wireless_check_i2c_is_ok);

bool platform_class_wireless_check_ic_fw_version(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(platform_class_wireless_check_ic_fw_version);

int platform_class_wireless_do_renego(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_do_renego);

int platform_class_wireless_download_fw_from_bin(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_download_fw_from_bin);

int platform_class_wireless_download_fw_from_image(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_download_fw_from_image);

int platform_class_wireless_enable_rev_fod(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_enable_rev_fod);

int platform_class_wireless_enable_reverse_chg(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_enable_reverse_chg);

int platform_class_wireless_enable_vsys_ctrl(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_enable_vsys_ctrl);

int platform_class_wireless_erase_fw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_erase_fw);

void * platform_class_wireless_get_auth_value(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_auth_value);

void * platform_class_wireless_get_debug_fod_type(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_debug_fod_type);

void * platform_class_wireless_get_detected_freq(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_detected_freq);

void * platform_class_wireless_get_fw_upgrade_fail_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_fw_upgrade_fail_info);

void * platform_class_wireless_get_hall_n_gpio_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_hall_n_gpio_status);

void * platform_class_wireless_get_hall_s_gpio_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_hall_s_gpio_status);

void * platform_class_wireless_get_iout(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_iout);

void * platform_class_wireless_get_magnetic_case_flag(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_magnetic_case_flag);

void * platform_class_wireless_get_pen_down_hall_n(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_down_hall_n);

void * platform_class_wireless_get_pen_down_hall_s(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_down_hall_s);

void * platform_class_wireless_get_pen_full_flag(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_full_flag);

void * platform_class_wireless_get_pen_hall_ppe_n(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_hall_ppe_n);

void * platform_class_wireless_get_pen_hall_ppe_s(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_hall_ppe_s);

void * platform_class_wireless_get_pen_mac(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_mac);

void * platform_class_wireless_get_pen_place_err(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_place_err);

void * platform_class_wireless_get_pen_soc(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_soc);

void * platform_class_wireless_get_pen_up_hall_n(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_up_hall_n);

void * platform_class_wireless_get_pen_up_hall_s(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_pen_up_hall_s);

void * platform_class_wireless_get_phone_case_category(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_phone_case_category);

void * platform_class_wireless_get_poweroff_err_code(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_poweroff_err_code);

void * platform_class_wireless_get_project_vendor(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_project_vendor);

void * platform_class_wireless_get_reverse_chg_en(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_reverse_chg_en);

void * platform_class_wireless_get_rsv_eppmode_fail(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rsv_eppmode_fail);

void * platform_class_wireless_get_rx_brg_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_brg_status);

void * platform_class_wireless_get_rx_err_code(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_err_code);

void * platform_class_wireless_get_rx_fastcharge_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_fastcharge_status);

void * platform_class_wireless_get_rx_int_flag(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_int_flag);

void * platform_class_wireless_get_rx_offset(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_offset);

void * platform_class_wireless_get_rx_power_mode(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_power_mode);

void * platform_class_wireless_get_rx_rtx_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_rx_rtx_mode);

void * platform_class_wireless_get_saved_fw_version(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_saved_fw_version);

void * platform_class_wireless_get_ss_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_ss_voltage);

void * platform_class_wireless_get_temp(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_temp);

void * platform_class_wireless_get_trx_isense(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_trx_isense);

void * platform_class_wireless_get_trx_vrect(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_trx_vrect);

void * platform_class_wireless_get_tx_adapter(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_adapter);

void * platform_class_wireless_get_tx_adapter_by_i2c(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_adapter_by_i2c);

void * platform_class_wireless_get_tx_err_code(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_err_code);

void * platform_class_wireless_get_tx_fan_speed(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_fan_speed);

void * platform_class_wireless_get_tx_iout(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_iout);

void * platform_class_wireless_get_tx_max_power(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_max_power);

void * platform_class_wireless_get_tx_type(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_type);

void * platform_class_wireless_get_tx_uuid(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_uuid);

void * platform_class_wireless_get_tx_vout(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_tx_vout);

void * platform_class_wireless_get_vout(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_vout);

void * platform_class_wireless_get_vout_setted(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_vout_setted);

void * platform_class_wireless_get_vrect(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_class_wireless_get_vrect);

bool platform_class_wireless_is_car_adapter(void *a0)
{
	return false;
}
EXPORT_SYMBOL(platform_class_wireless_is_car_adapter);

bool platform_class_wireless_is_present(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(platform_class_wireless_is_present);

int platform_class_wireless_process_factory_cmd(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_process_factory_cmd);

int platform_class_wireless_receive_test_cmd(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_receive_test_cmd);

int platform_class_wireless_receive_transparent_data(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_receive_transparent_data);

int platform_class_wireless_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_register_ops);

int platform_class_wireless_send_transparent_data(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_send_transparent_data);

int platform_class_wireless_send_tx_q_value(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_send_tx_q_value);

int platform_class_wireless_set_adapter_voltage(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_adapter_voltage);

int platform_class_wireless_set_charge_type(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_charge_type);

int platform_class_wireless_set_confirm_data(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_confirm_data);

int platform_class_wireless_set_cp_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_cp_mode);

int platform_class_wireless_set_debug_fod(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_debug_fod);

int platform_class_wireless_set_debug_fod_params(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_debug_fod_params);

int platform_class_wireless_set_enable_mode(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_enable_mode);

int platform_class_wireless_set_external_boost_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_external_boost_enable);

int platform_class_wireless_set_fod_params(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_fod_params);

int platform_class_wireless_set_fw_bin(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_fw_bin);

int platform_class_wireless_set_hboost_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_hboost_enable);

int platform_class_wireless_set_parallel_charge(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_parallel_charge);

int platform_class_wireless_set_pen_place_err(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_pen_place_err);

int platform_class_wireless_set_phone_case_category(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_phone_case_category);

int platform_class_wireless_set_rx_offset(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_rx_offset);

int platform_class_wireless_set_rx_sleep_mode(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_rx_sleep_mode);

int platform_class_wireless_set_rx_standby_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_rx_standby_mode);

int platform_class_wireless_set_tx_cust_operation(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_tx_cust_operation);

int platform_class_wireless_set_tx_fan_speed(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_tx_fan_speed);

int platform_class_wireless_set_vout(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_set_vout);

int platform_class_wireless_switch_bridge(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(platform_class_wireless_switch_bridge);

int platform_fg_ic_ops_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ic_ops_register);

int platform_fg_ops_fl4p0_enable_check(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_fl4p0_enable_check);

void * platform_fg_ops_get_adapt_power(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_adapt_power);

void * platform_fg_ops_get_aged_flag(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_aged_flag);

void * platform_fg_ops_get_authentic(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_authentic);

void * platform_fg_ops_get_batt_abnormal_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_batt_abnormal_info);

void * platform_fg_ops_get_batt_cell_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_batt_cell_info);

void * platform_fg_ops_get_batt_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_batt_info);

void * platform_fg_ops_get_batt_qmax(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_batt_qmax);

void * platform_fg_ops_get_batt_sn(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_batt_sn);

void * platform_fg_ops_get_calc_rvalue(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_calc_rvalue);

void * platform_fg_ops_get_calibration_charge_energy(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_calibration_charge_energy);

void * platform_fg_ops_get_calibration_ffc_iterm(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_calibration_ffc_iterm);

void * platform_fg_ops_get_cc_coulomb_integral(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_cc_coulomb_integral);

void * platform_fg_ops_get_charge_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_charge_status);

void * platform_fg_ops_get_chg_vol(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_chg_vol);

void * platform_fg_ops_get_chip_ok(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_chip_ok);

void * platform_fg_ops_get_clear_cycle_flag(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_clear_cycle_flag);

void * platform_fg_ops_get_count_level1(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_count_level1);

void * platform_fg_ops_get_count_level2(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_count_level2);

void * platform_fg_ops_get_count_level3(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_count_level3);

void * platform_fg_ops_get_count_lowtemp(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_count_lowtemp);

void * platform_fg_ops_get_csd_flag(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_csd_flag);

void * platform_fg_ops_get_curr(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_curr);

void * platform_fg_ops_get_cutoff_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_cutoff_voltage);

void * platform_fg_ops_get_cyclecount(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_cyclecount);

void * platform_fg_ops_get_device_name(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_device_name);

void * platform_fg_ops_get_dod_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_dod_count);

void * platform_fg_ops_get_error_state(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_error_state);

void * platform_fg_ops_get_fast_mode_times(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fast_mode_times);

void * platform_fg_ops_get_fastcharge(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fastcharge);

void * platform_fg_ops_get_fc(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fc);

void * platform_fg_ops_get_fcc(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fcc);

void * platform_fg_ops_get_fcc_default(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fcc_default);

void * platform_fg_ops_get_fg_vendor(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_fg_vendor);

void * platform_fg_ops_get_full_design(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_full_design);

void * platform_fg_ops_get_iaver(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_iaver);

void * platform_fg_ops_get_isc_alert_level(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_isc_alert_level);

void * platform_fg_ops_get_original_temp(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_original_temp);

void * platform_fg_ops_get_pack_vendor(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_pack_vendor);

void * platform_fg_ops_get_raw_soc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_raw_soc);

void * platform_fg_ops_get_real_supplement_energy(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_real_supplement_energy);

void * platform_fg_ops_get_rm(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_rm);

void * platform_fg_ops_get_rsoc(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_rsoc);

void * platform_fg_ops_get_soa_alert_level(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_soa_alert_level);

void * platform_fg_ops_get_soc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_soc);

void * platform_fg_ops_get_soh(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_soh);

void * platform_fg_ops_get_temp(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_temp);

void * platform_fg_ops_get_temp_max(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_temp_max);

void * platform_fg_ops_get_temp_min(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_temp_min);

void * platform_fg_ops_get_time_ot(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_time_ot);

void * platform_fg_ops_get_tte(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_tte);

void * platform_fg_ops_get_ttf(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_ttf);

void * platform_fg_ops_get_ui_soh(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_ui_soh);

void * platform_fg_ops_get_verify_digest(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_verify_digest);

void * platform_fg_ops_get_volt(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_volt);

void * platform_fg_ops_get_vsiloss(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(platform_fg_ops_get_vsiloss);

int platform_fg_ops_probe_ok(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_probe_ok);

int platform_fg_ops_set_authentic(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_authentic);

int platform_fg_ops_set_clear_count_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_clear_count_data);

int platform_fg_ops_set_clear_cycle(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_clear_cycle);

int platform_fg_ops_set_co(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_co);

int platform_fg_ops_set_cutoff_voltage(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_cutoff_voltage);

int platform_fg_ops_set_fast_mode_times(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_fast_mode_times);

int platform_fg_ops_set_fastcharge(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_fastcharge);

int platform_fg_ops_set_force_report_full(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_force_report_full);

int platform_fg_ops_set_iterm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_iterm);

int platform_fg_ops_set_reboot_vol_thr(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_reboot_vol_thr);

int platform_fg_ops_set_temp(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_temp);

int platform_fg_ops_set_verify_digest(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_set_verify_digest);

int platform_fg_ops_update_fw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(platform_fg_ops_update_fw);

void * platform_get_qcom_scmi_device(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(platform_get_qcom_scmi_device);

void * platform_mpam_get_root_group(void)
{
	return NULL;
}
EXPORT_SYMBOL(platform_mpam_get_root_group);

/* ---- pmic_* (3) ---- */
int pmic_glink_register_client(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_register_client);

int pmic_glink_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_unregister_client);

int pmic_glink_write(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_write);

/* ---- powerinsight_* (10) ---- */
int powerinsight_gpu_close_opp_cost(void)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_close_opp_cost);

void * powerinsight_gpu_get_opp_cnt(void)
{
	return NULL;
}
EXPORT_SYMBOL(powerinsight_gpu_get_opp_cnt);

int powerinsight_gpu_init_opp_cost(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_init_opp_cost);

int powerinsight_gpu_query_opp_cost(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_query_opp_cost);

int powerinsight_gpu_update_opp_cost(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_update_opp_cost);

int powerinsight_register_module_ops(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_register_module_ops);

int powerinsight_unregister_module_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_unregister_module_ops);

int powerinsight_wifi_wake_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_data);

int powerinsight_wifi_wake_interrupt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_interrupt);

int powerinsight_wifi_wake_reason(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_reason);

/* ---- product_* (1) ---- */
int product_name_get(void)
{
	return 0;
}
EXPORT_SYMBOL(product_name_get);

/* ---- protocol_* (73) ---- */
int protocol_class_det_adapter_type(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_det_adapter_type);

void * protocol_class_get_adapter_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_info);

void * protocol_class_get_adapter_max_power(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_max_power);

void * protocol_class_get_adapter_power_cap(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_power_cap);

void * protocol_class_get_adapter_power_curve(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_power_curve);

void * protocol_class_get_adapter_pps_ptf(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_pps_ptf);

void * protocol_class_get_adapter_pwr_max_power(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_pwr_max_power);

void * protocol_class_get_adapter_type(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_type);

void * protocol_class_get_adapter_verified(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_verified);

void * protocol_class_get_adapter_volt_and_curr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_get_adapter_volt_and_curr);

void * protocol_class_pd_get_adapter_id(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_adapter_id);

void * protocol_class_pd_get_adapter_svid(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_adapter_svid);

void * protocol_class_pd_get_cap(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_cap);

void * protocol_class_pd_get_cc_short_vbus(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_cc_short_vbus);

void * protocol_class_pd_get_cc_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_cc_status);

void * protocol_class_pd_get_cc_toggle(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_cc_toggle);

void * protocol_class_pd_get_cid_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_cid_status);

void * protocol_class_pd_get_current_state(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_current_state);

void * protocol_class_pd_get_data_role(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_data_role);

bool protocol_class_pd_get_has_dp(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(protocol_class_pd_get_has_dp);

void * protocol_class_pd_get_otg_plugin_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_otg_plugin_status);

void * protocol_class_pd_get_pd_active(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pd_active);

void protocol_class_pd_get_pd_in_hard_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(protocol_class_pd_get_pd_in_hard_reset);

void * protocol_class_pd_get_pd_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pd_type);

void * protocol_class_pd_get_pd_typec_accessory_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pd_typec_accessory_mode);

void * protocol_class_pd_get_pd_verifed(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pd_verifed);

void * protocol_class_pd_get_pdos(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pdos);

void * protocol_class_pd_get_port_num(void)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_port_num);

void * protocol_class_pd_get_power_role(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_power_role);

void * protocol_class_pd_get_pps_apdo_max(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_apdo_max);

void * protocol_class_pd_get_pps_max_cur(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_max_cur);

void * protocol_class_pd_get_pps_max_power(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_max_power);

void * protocol_class_pd_get_pps_max_volt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_max_volt);

void * protocol_class_pd_get_pps_min_volt(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_min_volt);

void * protocol_class_pd_get_pps_ptf(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_ptf);

void * protocol_class_pd_get_pps_status(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_pps_status);

void * protocol_class_pd_get_product_vdo(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_product_vdo);

void * protocol_class_pd_get_snk_src_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_snk_src_mode);

void * protocol_class_pd_get_support_keep_pdo(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_support_keep_pdo);

void * protocol_class_pd_get_suspend_support_status(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_suspend_support_status);

void * protocol_class_pd_get_typec_cc_orientation(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_typec_cc_orientation);

void * protocol_class_pd_get_typec_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_typec_mode);

void * protocol_class_pd_get_usb_suspend_supported(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_usb_suspend_supported);

void * protocol_class_pd_get_usb_vendor_id(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_usb_vendor_id);

void * protocol_class_pd_get_vdm_cmd(void *a0, void *a1, void *a2, void *a3)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_vdm_cmd);

void * protocol_class_pd_get_verify_process(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_verify_process);

void * protocol_class_pd_get_zimi_cypress_flag(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_pd_get_zimi_cypress_flag);

int protocol_class_pd_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_register_ops);

int protocol_class_pd_request_vdm_cmd(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_request_vdm_cmd);

int protocol_class_pd_set_cc_toggle(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_cc_toggle);

int protocol_class_pd_set_fixed_volt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_fixed_volt);

int protocol_class_pd_set_gear_shift(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_gear_shift);

int protocol_class_pd_set_pd_active(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pd_active);

void protocol_class_pd_set_pd_in_hard_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(protocol_class_pd_set_pd_in_hard_reset);

int protocol_class_pd_set_pd_typec_accessory_mode(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pd_typec_accessory_mode);

int protocol_class_pd_set_pd_verifed(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pd_verifed);

int protocol_class_pd_set_pps_apdo_max(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pps_apdo_max);

int protocol_class_pd_set_pps_max_cur(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pps_max_cur);

int protocol_class_pd_set_pps_max_volt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pps_max_volt);

int protocol_class_pd_set_pps_min_volt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pps_min_volt);

int protocol_class_pd_set_pps_pdo_select(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_pps_pdo_select);

int protocol_class_pd_set_typec_cc_orientation(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_typec_cc_orientation);

int protocol_class_pd_set_typec_mode(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_typec_mode);

int protocol_class_pd_set_usb_suspend_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_usb_suspend_supported);

int protocol_class_pd_set_verify_process(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_pd_set_verify_process);

bool protocol_class_qc3_check_class_type(void *a0)
{
	return false;
}
EXPORT_SYMBOL(protocol_class_qc3_check_class_type);

void * protocol_class_qc_get_qc_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(protocol_class_qc_get_qc_type);

int protocol_class_qc_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_qc_register_ops);

int protocol_class_qc_set_volt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_qc_set_volt);

int protocol_class_qc_set_volt_cmd(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_qc_set_volt_cmd);

int protocol_class_register_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_register_ops);

int protocol_class_set_adapter_verified(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_set_adapter_verified);

int protocol_class_set_adapter_volt_and_curr(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(protocol_class_set_adapter_volt_and_curr);

/* ---- provide_* (1) ---- */
int provide_qseecom_kernel_fun_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(provide_qseecom_kernel_fun_ops);

/* ---- put_* (1) ---- */
int put_si_object(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(put_si_object);

/* ---- qcom_* (105) ---- */
int qcom_alloc_io_pgtable_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_alloc_io_pgtable_ops);

int qcom_arm_lpae_map_sg(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qcom_arm_lpae_map_sg);

int qcom_arm_lpae_unmap_pages(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_arm_lpae_unmap_pages);

int qcom_cc_sync_state(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_cc_sync_state);

int qcom_clk_crm_set_rate(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_crm_set_rate);

int qcom_clk_crmb_set_rate(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_crmb_set_rate);

void qcom_clk_dump(void *a0, void *a1, void *a2)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_clk_dump);

void * qcom_clk_get_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_clk_get_voltage);

int qcom_clk_set_flags(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_set_flags);

int qcom_create_ramdump_device(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_create_ramdump_device);

void * qcom_dcvs_get_ddr_child_node(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_dcvs_get_ddr_child_node);

int qcom_dcvs_hw_minmax_get(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_hw_minmax_get);

int qcom_dcvs_kobject_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_kobject_get);

int qcom_dcvs_register_voter(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_register_voter);

int qcom_dcvs_unregister_voter(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_unregister_voter);

int qcom_dcvs_update_votes(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_update_votes);

int qcom_destroy_ramdump_device(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_destroy_ramdump_device);

void qcom_dump(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_dump);

void qcom_elf_dump(void *a0, void *a1, void *a2)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_elf_dump);

void * qcom_flash_led_get_max_avail_current(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_flash_led_get_max_avail_current);

int qcom_free_io_pgtable_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_free_io_pgtable_ops);

void qcom_fw_elf_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_fw_elf_dump);

void * qcom_get_cpucp_id(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_get_cpucp_id);

int qcom_glink_early_ssr_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_early_ssr_notify);

void * qcom_glink_get_signals(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_glink_get_signals);

bool qcom_glink_is_wakeup(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_glink_is_wakeup);

void qcom_glink_mem_entry_free(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_glink_mem_entry_free);

int qcom_glink_mem_entry_init(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_mem_entry_init);

int qcom_glink_native_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_native_start);

int qcom_glink_prepare_da_for_cpu(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_prepare_da_for_cpu);

int qcom_glink_register_signals_cb(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_register_signals_cb);

int qcom_glink_rx_done(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_rx_done);

int qcom_glink_rx_done_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_rx_done_supported);

int qcom_glink_set_signals(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_set_signals);

int qcom_glink_smem_early_ssr_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_smem_early_ssr_notify);

int qcom_glink_smem_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_smem_start);

int qcom_glink_spss_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_spss_register);

void qcom_glink_spss_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_glink_spss_unregister);

bool qcom_haptics_vi_sense_is_enabled(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_haptics_vi_sense_is_enabled);

int qcom_iommu_enable_s1_translation(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_enable_s1_translation);

void * qcom_iommu_get_asid_nr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_asid_nr);

void * qcom_iommu_get_context_bank_nr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_context_bank_nr);

void * qcom_iommu_get_fault_ids(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_fault_ids);

void * qcom_iommu_get_mappings_configuration(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_mappings_configuration);

int qcom_iommu_set_fault_model(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_set_fault_model);

int qcom_iommu_set_secure_vmid(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_set_secure_vmid);

int qcom_iommu_sid_switch(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_sid_switch);

bool qcom_is_dma_buf_file(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_is_dma_buf_file);

int qcom_mpam_config_monitor(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_config_monitor);

void * qcom_mpam_get_bw_limit(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_bw_limit);

void * qcom_mpam_get_bw_limit_rpmsg(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_bw_limit_rpmsg);

void * qcom_mpam_get_cache_partition(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_cache_partition);

void * qcom_mpam_get_platform_bw_ctrl(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_platform_bw_ctrl);

void * qcom_mpam_get_version(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_version);

int qcom_mpam_set_bw_limit_rpmsg(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_bw_limit_rpmsg);

int qcom_mpam_set_cache_partition(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_cache_partition);

int qcom_mpam_set_platform_bw_ctrl(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_platform_bw_ctrl);

int qcom_mpam_set_platform_bw_monitor(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_platform_bw_monitor);

int qcom_msc_lookup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_msc_lookup);

int qcom_notify_early_ssr_clients(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_notify_early_ssr_clients);

int qcom_notify_ssr_clients(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_notify_ssr_clients);

int qcom_pil_timeouts_disabled(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pil_timeouts_disabled);

int qcom_pmu_event_supported(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_event_supported);

int qcom_pmu_idle_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_idle_register);

int qcom_pmu_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_read);

int qcom_pmu_read_all_local(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_read_all_local);

int qcom_q6v5_register_glink_subdev(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_q6v5_register_glink_subdev);

int qcom_q6v5_register_ssr_subdev(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_q6v5_register_ssr_subdev);

int qcom_register_early_ssr_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_register_early_ssr_notifier);

int qcom_rproc_update_recovery_status(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_rproc_update_recovery_status);

int qcom_scm_dcvs_ca_available(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_ca_available);

int qcom_scm_dcvs_core_available(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_core_available);

int qcom_scm_dcvs_init_ca_v2(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_init_ca_v2);

int qcom_scm_dcvs_init_v2(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_init_v2);

void qcom_scm_dcvs_reset(void)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_scm_dcvs_reset);

int qcom_scm_dcvs_update(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update);

int qcom_scm_dcvs_update_ca_v2(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update_ca_v2);

int qcom_scm_dcvs_update_v2(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update_v2);

void * qcom_scm_get_sec_dump_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_sec_dump_state);

void * qcom_scm_get_tz_feat_id_version(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_tz_feat_id_version);

void * qcom_scm_get_tz_log_feat_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_tz_log_feat_id);

void qcom_scm_io_reset(void)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_scm_io_reset);

int qcom_scm_kgsl_dcvs_tuning(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_dcvs_tuning);

int qcom_scm_kgsl_init_regs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_init_regs);

int qcom_scm_kgsl_set_smmu_aperture(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_aperture);

int qcom_scm_kgsl_set_smmu_lpac_aperture(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_lpac_aperture);

int qcom_scm_mem_protect_region_id(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_mem_protect_region_id);

int qcom_scm_mem_protect_sd_ctrl(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_mem_protect_sd_ctrl);

int qcom_scm_pas_shutdown_retry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_pas_shutdown_retry);

int qcom_scm_query_encrypted_log_feature(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_encrypted_log_feature);

int qcom_scm_query_log_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_log_status);

int qcom_scm_query_tz_time(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_tz_time);

int qcom_scm_register_qsee_log_buf(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_register_qsee_log_buf);

int qcom_scm_request_encrypted_log(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_request_encrypted_log);

int qcom_scm_smmu_notify_secure_lut(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_smmu_notify_secure_lut);

int qcom_skip_tlb_management(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_skip_tlb_management);

int qcom_spss_set_fw_name(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_spss_set_fw_name);

void * qcom_ssr_get_subsys(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_ssr_get_subsys);

int qcom_stats_ddr_freqsync_msg(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_stats_ddr_freqsync_msg);

void * qcom_sysmon_get_txn_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_sysmon_get_txn_id);

int qcom_unregister_early_ssr_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_unregister_early_ssr_notifier);

int qcom_va_md_add_region(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_add_region);

int qcom_va_md_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_enabled);

int qcom_va_md_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_register);

void qcom_va_md_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_va_md_unregister);

/* ---- qlpmm_* (1) ---- */
void * qlpmm_get_subsystem_lpm_data(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qlpmm_get_subsystem_lpm_data);

/* ---- qptm_* (11) ---- */
int qptm_available_node_count(void)
{
	return 0;
}
EXPORT_SYMBOL(qptm_available_node_count);

int qptm_channel_register(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qptm_channel_register);

void qptm_channel_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qptm_channel_unregister);

int qptm_data_update_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qptm_data_update_notifier_register);

void qptm_data_update_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qptm_data_update_notifier_unregister);

int qptm_for_each_node(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qptm_for_each_node);

void * qptm_get_energy_in_uj(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_energy_in_uj);

void * qptm_get_node_id(void)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_node_id);

void * qptm_get_node_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_node_name);

void * qptm_get_power_in_uw(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_power_in_uw);

int qptm_power_data_update(void)
{
	return 0;
}
EXPORT_SYMBOL(qptm_power_data_update);

/* ---- qrtr_* (2) ---- */
int qrtr_peek_pkt_size(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qrtr_peek_pkt_size);

int qrtr_print_wakeup_reason(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qrtr_print_wakeup_reason);

/* ---- qtee_* (5) ---- */
int qtee_shmbridge_allocate_shm(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_allocate_shm);

int qtee_shmbridge_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_deregister);

int qtee_shmbridge_free_shm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_free_shm);

bool qtee_shmbridge_is_enabled(void)
{
	return false;
}
EXPORT_SYMBOL(qtee_shmbridge_is_enabled);

int qtee_shmbridge_register(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_register);

/* ---- qti_* (2) ---- */
void * qti_battery_charger_get_prop(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(qti_battery_charger_get_prop);

int qti_smmu_proxy_register_callbacks(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qti_smmu_proxy_register_callbacks);

/* ---- qts_* (3) ---- */
int qts_client_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qts_client_register);

int qts_ts_resume(void)
{
	return 0;
}
EXPORT_SYMBOL(qts_ts_resume);

int qts_ts_suspend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qts_ts_suspend);

/* ---- qvadj_* (2) ---- */
void * qvadj_get_cur_voltage_overrides(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qvadj_get_cur_voltage_overrides);

int qvadj_set_next_voltage_overrides(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qvadj_set_next_voltage_overrides);

/* ---- register_* (16) ---- */
int register_cam_freq_hook(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_cam_freq_hook);

int register_cld_cmd_cb(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(register_cld_cmd_cb);

int register_dump_segments(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(register_dump_segments);

int register_hboost_event_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_hboost_event_notifier);

int register_hw_component_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_hw_component_info);

int register_hw_monitor_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_hw_monitor_info);

void * register_mi_cx_stats_get_ss_vote_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(register_mi_cx_stats_get_ss_vote_info);

void * register_mi_ddr_stats_get_ss_vote_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(register_mi_ddr_stats_get_ss_vote_info);

int register_mi_dflt_bw_update_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_mi_dflt_bw_update_cb);

int register_mi_dflt_lat_update_cb(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(register_mi_dflt_lat_update_cb);

void * register_mi_llc_stats_get_ss_vote_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(register_mi_llc_stats_get_ss_vote_info);

int register_micam_cpu_cycles_calibration_hook(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_micam_cpu_cycles_calibration_hook);

int register_phy_device(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(register_phy_device);

int register_touch_panel(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(register_touch_panel);

int register_xiaomi_input_dev(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(register_xiaomi_input_dev);

int register_xiaomi_stylus_input_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(register_xiaomi_stylus_input_dev);

/* ---- regmap_* (1) ---- */
int __regmap_init_swr(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(__regmap_init_swr);

/* ---- regulator_* (1) ---- */
int regulator_proxy_consumer_sync_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(regulator_proxy_consumer_sync_state);

/* ---- revert_* (1) ---- */
int revert_creds(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(revert_creds);

/* ---- rmnet_* (35) ---- */
int rmnet_mem_cb(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_cb);

int rmnet_mem_config_query(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_config_query);

void * rmnet_mem_get_pages_entry(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return NULL;
}
EXPORT_SYMBOL(rmnet_mem_get_pages_entry);

void * rmnet_mem_get_pool_size(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(rmnet_mem_get_pool_size);

int rmnet_mem_info_ref_inc_entry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_info_ref_inc_entry);

int rmnet_mem_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_notifier);

int rmnet_mem_pb_ind(void)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_pb_ind);

int rmnet_mem_put_page_entry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_put_page_entry);

int rmnet_mem_register_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_register_notifier);

int rmnet_mem_unregister_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_mem_unregister_notifier);

int rmnet_module_hook_aps_data_active(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_aps_data_active);

int rmnet_module_hook_aps_data_inactive(void)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_aps_data_inactive);

int rmnet_module_hook_aps_data_report(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_aps_data_report);

int rmnet_module_hook_aps_post_queue(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_aps_post_queue);

int rmnet_module_hook_aps_pre_queue(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_aps_pre_queue);

int rmnet_module_hook_offload_chain_end(void)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_offload_chain_end);

int rmnet_module_hook_offload_ingress(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_offload_ingress);

int rmnet_module_hook_perf_cmd_ingress(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_cmd_ingress);

int rmnet_module_hook_perf_coal_common_stat(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_coal_common_stat);

int rmnet_module_hook_perf_coal_stat(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_coal_stat);

int rmnet_module_hook_perf_ecn_ingress(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_ecn_ingress);

int rmnet_module_hook_perf_egress(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_egress);

int rmnet_module_hook_perf_ingress(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_ingress);

int rmnet_module_hook_perf_ingress_rx_handler(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_ingress_rx_handler);

int rmnet_module_hook_perf_non_coal_stat(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_non_coal_stat);

int rmnet_module_hook_perf_seg_stat(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_seg_stat);

int rmnet_module_hook_perf_set_thresh(void)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_set_thresh);

int rmnet_module_hook_perf_tether_cmd(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_tether_cmd);

int rmnet_module_hook_perf_tether_egress(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_tether_egress);

int rmnet_module_hook_perf_tether_ingress(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_perf_tether_ingress);

int rmnet_module_hook_shs_skb_entry(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_shs_skb_entry);

int rmnet_module_hook_shs_skb_ll_entry(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_shs_skb_ll_entry);

int rmnet_module_hook_shs_switch(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_shs_switch);

int rmnet_module_hook_wlan_flow_match(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_wlan_flow_match);

int rmnet_module_hook_wlan_ingress_rx_handler(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(rmnet_module_hook_wlan_ingress_rx_handler);

/* ---- rpmh_* (4) ---- */
int rpmh_drv_start(void)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_drv_start);

void rpmh_drv_stop(void)
{
	/* no-op */
}
EXPORT_SYMBOL(rpmh_drv_stop);

void * rpmh_get_device(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(rpmh_get_device);

int rpmh_write_sleep_and_wake_no_child(void)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_write_sleep_and_wake_no_child);

/* ---- rproc_* (1) ---- */
int rproc_recovery_set_fn(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(rproc_recovery_set_fn);

/* ---- sched_* (4) ---- */
int sched_entity_freq_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sched_entity_freq_enable);

void * sched_entity_freq_get_runq_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sched_entity_freq_get_runq_count);

bool sched_entity_freq_is_power_save_mode(void *a0)
{
	return false;
}
EXPORT_SYMBOL(sched_entity_freq_is_power_save_mode);

int sched_lpm_disallowed_time(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sched_lpm_disallowed_time);

/* ---- schedule_* (1) ---- */
int schedule_resume_suspend_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(schedule_resume_suspend_work);

/* ---- sdca_* (2) ---- */
void * sdca_devices_debugfs_dentry_create(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(sdca_devices_debugfs_dentry_create);

void sdca_devices_debugfs_dentry_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sdca_devices_debugfs_dentry_remove);

/* ---- sde_* (2) ---- */
int sde_i2c_byte_read(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sde_i2c_byte_read);

int sde_i2c_byte_write(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sde_i2c_byte_write);

/* ---- should_* (1) ---- */
int should_boost_bus_dcvs(void)
{
	return 0;
}
EXPORT_SYMBOL(should_boost_bus_dcvs);

/* ---- si_* (3) ---- */
int si_core_client_env_open(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(si_core_client_env_open);

void * si_core_get_client_env(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(si_core_get_client_env);

int si_object_do_invoke(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(si_object_do_invoke);

/* ---- sipa_* (8) ---- */
void * sipa_get_channels(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sipa_get_channels);

int sipa_i2c_probe(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_i2c_probe);

void sipa_i2c_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_i2c_remove);

void sipa_i2c_shutdown(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_i2c_shutdown);

int sipa_multi_channel_load_fw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_multi_channel_load_fw);

void sipa_multi_channel_power_off(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_multi_channel_power_off);

int sipa_multi_channel_power_on_and_set_scene(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_multi_channel_power_on_and_set_scene);

void sipa_multi_channel_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_multi_channel_reg_dump);

/* ---- slim_* (1) ---- */
int slim_stream_unprepare_disconnect_port(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(slim_stream_unprepare_disconnect_port);

/* ---- smem_* (4) ---- */
int smem_mailbox_read(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(smem_mailbox_read);

int smem_mailbox_start(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(smem_mailbox_start);

void smem_mailbox_stop(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(smem_mailbox_stop);

int smem_mailbox_write(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(smem_mailbox_write);

/* ---- snd_* (6) ---- */
int snd_event_client_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_client_deregister);

int snd_event_client_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_client_register);

int snd_event_master_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_master_deregister);

int snd_event_master_register(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_master_register);

int snd_event_mstr_add_client(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_mstr_add_client);

int snd_event_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(snd_event_notify);

/* ---- soc_* (9) ---- */
int soc_aux_deinit_only_sia81xx(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(soc_aux_deinit_only_sia81xx);

int soc_aux_init_only_sia81xx(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(soc_aux_init_only_sia81xx);

int soc_codec_conf_sia91xx(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(soc_codec_conf_sia91xx);

int soc_codec_conf_sipa(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(soc_codec_conf_sipa);

void soc_sia81xx_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(soc_sia81xx_deinit);

void * soc_sia81xx_get_aux_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(soc_sia81xx_get_aux_num);

void * soc_sia81xx_get_codec_conf_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(soc_sia81xx_get_codec_conf_num);

int soc_sia81xx_init(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(soc_sia81xx_init);

int soc_sia91xx_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(soc_sia91xx_init);

/* ---- socinfo_* (9) ---- */
void * socinfo_get_feature_code(void)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_feature_code);

void * socinfo_get_part_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_part_count);

void * socinfo_get_part_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_part_info);

void * socinfo_get_partinfo_chip_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_chip_id);

void * socinfo_get_partinfo_part_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_part_name);

void * socinfo_get_partinfo_vulkan_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_vulkan_id);

void * socinfo_get_pcode(void)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_pcode);

void * socinfo_get_serial_number(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_serial_number);

void * socinfo_get_subpart_info(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_subpart_info);

/* ---- softnet_* (1) ---- */
int softnet_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(softnet_data);

/* ---- spec_* (1) ---- */
int spec_sync_wait_bind_array(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(spec_sync_wait_bind_array);

/* ---- spf_* (2) ---- */
int spf_core_apm_close_all(void)
{
	return 0;
}
EXPORT_SYMBOL(spf_core_apm_close_all);

bool spf_core_is_apm_ready(void *a0)
{
	return false;
}
EXPORT_SYMBOL(spf_core_is_apm_ready);

/* ---- spmi_* (1) ---- */
int spmi_pmic_arb_map_address(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(spmi_pmic_arb_map_address);

/* ---- sps_* (35) ---- */
int sps_alloc_endpoint(void)
{
	return 0;
}
EXPORT_SYMBOL(sps_alloc_endpoint);

int sps_alloc_mem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_alloc_mem);

int sps_bam_disable_irqs(void)
{
	return 0;
}
EXPORT_SYMBOL(sps_bam_disable_irqs);

int sps_bam_enable_irqs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_bam_enable_irqs);

int sps_bam_process_irq(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_bam_process_irq);

int sps_connect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sps_connect);

int sps_ctrl_bam_dma_clk(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_ctrl_bam_dma_clk);

int sps_deregister_bam_device(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_deregister_bam_device);

void sps_device_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sps_device_reset);

int sps_disconnect(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_disconnect);

int sps_flow_off(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_flow_off);

int sps_flow_on(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_flow_on);

int sps_free_endpoint(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_free_endpoint);

int sps_free_mem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_free_mem);

void * sps_get_bam_addr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_bam_addr);

void * sps_get_bam_debug_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_bam_debug_info);

void * sps_get_config(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_config);

void * sps_get_event(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_event);

void * sps_get_free_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_free_count);

void * sps_get_iovec(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_iovec);

void * sps_get_unused_desc_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sps_get_unused_desc_num);

bool sps_is_pipe_empty(void *a0)
{
	return false;
}
EXPORT_SYMBOL(sps_is_pipe_empty);

int sps_phy2h(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_phy2h);

void sps_pipe_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sps_pipe_disable);

int sps_pipe_inject_zlt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_pipe_inject_zlt);

int sps_pipe_pending_desc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_pipe_pending_desc);

void sps_pipe_reset(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(sps_pipe_reset);

int sps_register_bam_device(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sps_register_bam_device);

int sps_register_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sps_register_event);

int sps_set_config(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_set_config);

int sps_set_owner(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_set_owner);

int sps_setup_bam2bam_fifo(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_setup_bam2bam_fifo);

int sps_timer_ctrl(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sps_timer_ctrl);

int sps_transfer(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sps_transfer);

int sps_transfer_one(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(sps_transfer_one);

/* ---- strategy_* (38) ---- */
bool strategy_class_fg_dual_is_chip_ok(void *a0)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_dual_is_chip_ok);

bool strategy_class_fg_get_authentic(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_get_authentic);

void * strategy_class_fg_get_comp_fcc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_comp_fcc);

void * strategy_class_fg_get_comp_rm(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_comp_rm);

void * strategy_class_fg_get_dc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_dc);

void * strategy_class_fg_get_fastcharge(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_fastcharge);

int strategy_class_fg_get_fcc(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_fcc);

void * strategy_class_fg_get_first_termination(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_first_termination);

void * strategy_class_fg_get_health(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_health);

bool strategy_class_fg_get_is_support_fast_mode(void *a0)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_get_is_support_fast_mode);

void * strategy_class_fg_get_model_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_model_name);

int strategy_class_fg_get_pack_vendor_id(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_pack_vendor_id);

int strategy_class_fg_get_rm(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_rm);

void * strategy_class_fg_get_soh(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_soh);

void * strategy_class_fg_get_vacc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_vacc);

int strategy_class_fg_get_voltage_mean(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_voltage_mean);

bool strategy_class_fg_is_chip_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_is_chip_ok);

void * strategy_class_fg_ops_get_charging_done(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_charging_done);

void * strategy_class_fg_ops_get_current(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_current);

void * strategy_class_fg_ops_get_cyclecount(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_cyclecount);

void * strategy_class_fg_ops_get_real_soc_decimal(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_real_soc_decimal);

void * strategy_class_fg_ops_get_rsoc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_rsoc);

void * strategy_class_fg_ops_get_soc(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_soc);

void * strategy_class_fg_ops_get_soc_decimal(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_soc_decimal);

void * strategy_class_fg_ops_get_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_temperature);

void * strategy_class_fg_ops_get_thermal_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_thermal_temperature);

void * strategy_class_fg_ops_get_voltage(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_voltage);

bool strategy_class_fg_ops_is_init_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_init_ok);

bool strategy_class_fg_ops_is_vacc2_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_vacc2_ok);

bool strategy_class_fg_ops_is_vacc_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_vacc_ok);

int strategy_class_fg_ops_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_ops_register);

int strategy_class_fg_ops_set_charging_done(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_ops_set_charging_done);

int strategy_class_fg_set_fastcharge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_set_fastcharge);

void * strategy_class_wireless_op_get_rx_iout_limit(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_op_get_rx_iout_limit);

void * strategy_class_wireless_ops_get_adapter_charger_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_adapter_charger_mode);

void * strategy_class_wireless_ops_get_adapter_power(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_adapter_power);

void * strategy_class_wireless_ops_get_wls_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_wls_type);

int strategy_class_wireless_ops_set_parallel_charge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_set_parallel_charge);

/* ---- stream_* (3) ---- */
int stream_agg_add_channel(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_add_channel);

int stream_agg_prepare_channel(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_prepare_channel);

int stream_agg_remove_channel(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_remove_channel);

/* ---- subsystem_* (3) ---- */
int subsystem_sleep_debug_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(subsystem_sleep_debug_enable);

int subsystem_sleep_stats_dbg_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(subsystem_sleep_stats_dbg_register);

void subsystem_sleep_stats_dbg_unregister(void)
{
	/* no-op */
}
EXPORT_SYMBOL(subsystem_sleep_stats_dbg_unregister);

/* ---- swr_* (25) ---- */
int swr_bulk_write(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(swr_bulk_write);

int swr_connect_port(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(swr_connect_port);

int swr_connect_port_v2(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(swr_connect_port_v2);

int swr_device_down(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_device_down);

int swr_device_handle_interrupt(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(swr_device_handle_interrupt);

int swr_device_up(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_device_up);

int swr_device_wakeup_unvote(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_device_wakeup_unvote);

int swr_device_wakeup_vote(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_device_wakeup_vote);

int swr_disconnect_port(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(swr_disconnect_port);

int swr_driver_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_driver_register);

void swr_driver_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(swr_driver_unregister);

void * swr_get_logical_dev_num(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(swr_get_logical_dev_num);

int swr_init_port_params(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(swr_init_port_params);

int swr_master_add_boarddevices(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_master_add_boarddevices);

int swr_new_device(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(swr_new_device);

int swr_port_response(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(swr_port_response);

int swr_read(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(swr_read);

int swr_register_master(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_register_master);

int swr_remove_device(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_remove_device);

int swr_remove_from_group(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(swr_remove_from_group);

int swr_reset_device(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_reset_device);

int swr_set_device_group(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(swr_set_device_group);

int swr_slvdev_datapath_control(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(swr_slvdev_datapath_control);

int swr_unregister_master(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(swr_unregister_master);

int swr_write(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(swr_write);

/* ---- swrm_* (1) ---- */
int swrm_wcd_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(swrm_wcd_notify);

/* ---- synx_* (6) ---- */
int synx_hwfence_enable_resources(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(synx_hwfence_enable_resources);

int synx_hwfence_init_interops(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(synx_hwfence_init_interops);

int synx_hwfence_init_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(synx_hwfence_init_ops);

int synx_hwfence_initialize(void)
{
	return 0;
}
EXPORT_SYMBOL(synx_hwfence_initialize);

int synx_hwfence_recover(void)
{
	return 0;
}
EXPORT_SYMBOL(synx_hwfence_recover);

int synx_signal_n(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(synx_signal_n);

/* ---- sysmon_* (7) ---- */
int sysmon_stats_query_ddr_residency(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_ddr_residency);

int sysmon_stats_query_hmx_utlization(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_hmx_utlization);

int sysmon_stats_query_hvx_utlization(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_hvx_utlization);

int sysmon_stats_query_power_residency(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_power_residency);

int sysmon_stats_query_q6_load(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_q6_load);

int sysmon_stats_query_q6_votes(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_q6_votes);

int sysmon_stats_query_sleep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_sleep);

/* ---- sysstats_* (4) ---- */
int sysstats_register_iterate_kgsl_process_privates(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_iterate_kgsl_process_privates);

int sysstats_register_kgsl_memstat_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_kgsl_memstat_cb);

int sysstats_register_kgsl_stats_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_kgsl_stats_cb);

int sysstats_unregister_kgsl_stats_cb(void)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_unregister_kgsl_stats_cb);

/* ---- system_* (1) ---- */
int system_heap_allocate_async_read(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(system_heap_allocate_async_read);

/* ---- tas25xx_* (8) ---- */
bool tas25xx_check_if_algo_ctrl_bypassed(void *a0)
{
	return false;
}
EXPORT_SYMBOL(tas25xx_check_if_algo_ctrl_bypassed);

int tas25xx_deregister_misc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_deregister_misc);

void * tas25xx_get_drv_channel_opmode(void)
{
	return NULL;
}
EXPORT_SYMBOL(tas25xx_get_drv_channel_opmode);

void * tas25xx_get_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(tas25xx_get_state);

int tas25xx_prep_dev_for_calib(void)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_prep_dev_for_calib);

int tas25xx_register_amp_error_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_amp_error_callback);

int tas25xx_register_i2c_error_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_i2c_error_callback);

int tas25xx_register_misc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_misc);

/* ---- tmc_* (2) ---- */
int tmc_etr_byte_cntr_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tmc_etr_byte_cntr_start);

void tmc_etr_byte_cntr_stop(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(tmc_etr_byte_cntr_stop);

/* ---- trigger_* (2) ---- */
void trigger_dump_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(trigger_dump_disable);

int trigger_dump_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(trigger_dump_enable);

/* ---- ufs_* (3) ---- */
int ufs_ffu_reboot_reason_reboot(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ufs_ffu_reboot_reason_reboot);

int ufs_scsi_read_partition(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ufs_scsi_read_partition);

int ufs_scsi_write_partition(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ufs_scsi_write_partition);

/* ---- unregister_* (9) ---- */
int unregister_cam_freq_hook(void)
{
	return 0;
}
EXPORT_SYMBOL(unregister_cam_freq_hook);

int unregister_hboost_event_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hboost_event_notifier);

int unregister_hw_component_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hw_component_info);

int unregister_hw_monitor_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hw_monitor_info);

int unregister_micam_cpu_cycles_calibration_hook(void)
{
	return 0;
}
EXPORT_SYMBOL(unregister_micam_cpu_cycles_calibration_hook);

int unregister_phy_device(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(unregister_phy_device);

int unregister_touch_panel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_touch_panel);

int unregister_xiaomi_input_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_xiaomi_input_dev);

int unregister_xiaomi_stylus_input_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_xiaomi_stylus_input_dev);

/* ---- update_* (8) ---- */
int update_abnormal_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_abnormal_event);

int update_ch_per_substream(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(update_ch_per_substream);

int update_fod_press_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_fod_press_status);

int update_hw_monitor_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(update_hw_monitor_info);

int update_palm_sensor_value(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_palm_sensor_value);

int update_palm_sensor_value_second_panel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_palm_sensor_value_second_panel);

int update_phy_device_nr_lanes(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(update_phy_device_nr_lanes);

int update_weak_doubletap_value(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_weak_doubletap_value);

/* ---- usb_* (21) ---- */
int usb_add_redriver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_add_redriver);

int usb_add_repeater_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_add_repeater_dev);

void * usb_get_redriver_by_phandle(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(usb_get_redriver_by_phandle);

void * usb_get_repeater_by_node(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(usb_get_repeater_by_node);

void * usb_get_repeater_by_phandle(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(usb_get_repeater_by_phandle);

int usb_gsi_ep_op(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(usb_gsi_ep_op);

int usb_put_redriver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_put_redriver);

int usb_put_repeater(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_put_repeater);

int usb_qdss_alloc_req(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(usb_qdss_alloc_req);

void usb_qdss_close(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(usb_qdss_close);

int usb_qdss_free_req(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_qdss_free_req);

int usb_qdss_open(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(usb_qdss_open);

int usb_qdss_write(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(usb_qdss_write);

int usb_redriver_gadget_pullup_enter(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(usb_redriver_gadget_pullup_enter);

void usb_redriver_gadget_pullup_exit(void *a0, void *a1, void *a2, void *a3)
{
	/* no-op */
}
EXPORT_SYMBOL(usb_redriver_gadget_pullup_exit);

int usb_redriver_host_powercycle(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_redriver_host_powercycle);

int usb_redriver_notify_connect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(usb_redriver_notify_connect);

int usb_redriver_notify_disconnect(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_redriver_notify_disconnect);

int usb_redriver_release_lanes(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(usb_redriver_release_lanes);

int usb_remove_redriver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_remove_redriver);

int usb_remove_repeater_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(usb_remove_repeater_dev);

/* ---- vis_* (18) ---- */
void * vis_dis_get_fps(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return NULL;
}
EXPORT_SYMBOL(vis_dis_get_fps);

int vis_display_can_send_mipi_cmd(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_can_send_mipi_cmd);

int vis_display_host_driver(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_host_driver);

int vis_display_ops_mipilock_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_ops_mipilock_notify);

int vis_display_ops_send_mipi_cmd_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_ops_send_mipi_cmd_notify);

int vis_display_ops_set_idlemgr_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_ops_set_idlemgr_notify);

int vis_display_ops_set_pq_trigger_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_ops_set_pq_trigger_notify);

int vis_display_ops_update_sde_connector(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_display_ops_update_sde_connector);

int vis_dsi_cmd_recv(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_dsi_cmd_recv);

int vis_dsi_cmd_send(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(vis_dsi_cmd_send);

int vis_dsi_fps_switching_cmd(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(vis_dsi_fps_switching_cmd);

int vis_dsi_rate_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_dsi_rate_notify);

int vis_fps_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_fps_notify);

bool vis_is_analog_bypass(void *a0)
{
	return false;
}
EXPORT_SYMBOL(vis_is_analog_bypass);

int vis_mi_esd_recover_handle_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_mi_esd_recover_handle_notify);

int vis_mi_esd_recover_usecase(void)
{
	return 0;
}
EXPORT_SYMBOL(vis_mi_esd_recover_usecase);

int vis_ops_callback_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_ops_callback_notify);

int vis_ops_wait_handshaking_command(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(vis_ops_wait_handshaking_command);

/* ---- wakeup_* (1) ---- */
int wakeup_xswapds(void)
{
	return 0;
}
EXPORT_SYMBOL(wakeup_xswapds);

/* ---- walt_* (3) ---- */
void * walt_get_cpus_in_state1(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_cpus_in_state1);

void * walt_get_cpus_taken(void)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_cpus_taken);

void * walt_get_halted_cpus(void)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_halted_cpus);

/* ---- waltgov_* (1) ---- */
int waltgov_cam_cpu(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(waltgov_cam_cpu);

/* ---- wcd_* (31) ---- */
int wcd_cal_create_hwdep(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_cal_create_hwdep);

int wcd_cancel_btn_work(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd_cancel_btn_work);

int wcd_cls_h_fsm(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(wcd_cls_h_fsm);

int wcd_cls_h_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd_cls_h_init);

int wcd_disable_irq(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_disable_irq);

int wcd_enable_curr_micbias(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_enable_curr_micbias);

int wcd_enable_irq(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_enable_irq);

int wcd_free_irq(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_free_irq);

void wcd_irq_exit(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd_irq_exit);

int wcd_irq_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_irq_init);

int wcd_mbhc_adc_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_adc_init);

int wcd_mbhc_elec_hs_report_unplug(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_elec_hs_report_unplug);

int wcd_mbhc_find_plug_and_report(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_find_plug_and_report);

void * wcd_mbhc_get_button_mask(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd_mbhc_get_button_mask);

int wcd_mbhc_hs_elec_irq(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_hs_elec_irq);

int wcd_mbhc_jack_report(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_jack_report);

int wcd_mbhc_report_plug(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_mbhc_report_plug);

int wcd_request_irq(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(wcd_request_irq);

void wcd_swch_level_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd_swch_level_remove);

int wcd_usbss_audio_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_audio_config);

int wcd_usbss_dpdm_switch_update(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_dpdm_switch_update);

void * wcd_usbss_get_sbu_switch_orientation(void)
{
	return NULL;
}
EXPORT_SYMBOL(wcd_usbss_get_sbu_switch_orientation);

int wcd_usbss_linearizer_rdac_cal_code_select(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_linearizer_rdac_cal_code_select);

int wcd_usbss_reg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_reg_notifier);

int wcd_usbss_register_update(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_register_update);

int wcd_usbss_regmap_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_regmap_init);

int wcd_usbss_set_linearizer_sw_tap(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_set_linearizer_sw_tap);

int wcd_usbss_set_switch_settings_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_set_switch_settings_enable);

int wcd_usbss_switch_update(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_switch_update);

int wcd_usbss_unreg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_unreg_notifier);

int wcd_usbss_update_default_trim(void)
{
	return 0;
}
EXPORT_SYMBOL(wcd_usbss_update_default_trim);

/* ---- wcd9378_* (16) ---- */
void * wcd9378_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd9378_codec_get_dev_num);

void * wcd9378_get_micb_vout_ctl_val(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd9378_get_micb_vout_ctl_val);

int wcd9378_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_info_create_codec_entry);

void wcd9378_mbhc_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd9378_mbhc_deinit);

void * wcd9378_mbhc_get_impedance(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd9378_mbhc_get_impedance);

int wcd9378_mbhc_hs_detect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_mbhc_hs_detect);

void wcd9378_mbhc_hs_detect_exit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd9378_mbhc_hs_detect_exit);

int wcd9378_mbhc_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_mbhc_init);

int wcd9378_mbhc_micb_adjust_voltage(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_mbhc_micb_adjust_voltage);

int wcd9378_mbhc_post_ssr_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_mbhc_post_ssr_init);

int wcd9378_mbhc_ssr_down(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_mbhc_ssr_down);

int wcd9378_micbias_control(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_micbias_control);

int wcd9378_sdca_readable_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_sdca_readable_register);

int wcd9378_sdca_writeable_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_sdca_writeable_register);

void * wcd9378_soc_get_mbhc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd9378_soc_get_mbhc);

int wcd9378_swr_dmic_register_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd9378_swr_dmic_register_notifier);

/* ---- wcd937x_* (14) ---- */
void * wcd937x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd937x_codec_get_dev_num);

void * wcd937x_get_codec_variant(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd937x_get_codec_variant);

void * wcd937x_get_micb_vout_ctl_val(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd937x_get_micb_vout_ctl_val);

int wcd937x_info_create_codec_entry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_info_create_codec_entry);

void wcd937x_mbhc_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd937x_mbhc_deinit);

void * wcd937x_mbhc_get_impedance(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd937x_mbhc_get_impedance);

int wcd937x_mbhc_hs_detect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_mbhc_hs_detect);

void wcd937x_mbhc_hs_detect_exit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd937x_mbhc_hs_detect_exit);

int wcd937x_mbhc_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_mbhc_init);

int wcd937x_mbhc_micb_adjust_voltage(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_mbhc_micb_adjust_voltage);

int wcd937x_mbhc_post_ssr_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_mbhc_post_ssr_init);

int wcd937x_mbhc_ssr_down(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_mbhc_ssr_down);

int wcd937x_micbias_control(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(wcd937x_micbias_control);

void * wcd937x_soc_get_mbhc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd937x_soc_get_mbhc);

/* ---- wcd938x_* (16) ---- */
int wcd938x_codec_force_enable_micbias_v2(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_codec_force_enable_micbias_v2);

void * wcd938x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd938x_codec_get_dev_num);

void * wcd938x_get_codec_variant(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd938x_get_codec_variant);

void * wcd938x_get_micb_vout_ctl_val(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd938x_get_micb_vout_ctl_val);

int wcd938x_info_create_codec_entry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_info_create_codec_entry);

void wcd938x_mbhc_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd938x_mbhc_deinit);

void * wcd938x_mbhc_get_impedance(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd938x_mbhc_get_impedance);

int wcd938x_mbhc_hs_detect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_mbhc_hs_detect);

void wcd938x_mbhc_hs_detect_exit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd938x_mbhc_hs_detect_exit);

int wcd938x_mbhc_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_mbhc_init);

int wcd938x_mbhc_micb_adjust_voltage(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_mbhc_micb_adjust_voltage);

int wcd938x_mbhc_post_ssr_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_mbhc_post_ssr_init);

int wcd938x_mbhc_ssr_down(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_mbhc_ssr_down);

int wcd938x_micbias_control(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_micbias_control);

void * wcd938x_soc_get_mbhc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd938x_soc_get_mbhc);

int wcd938x_swr_dmic_register_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcd938x_swr_dmic_register_notifier);

/* ---- wcd939x_* (17) ---- */
int wcd939x_codec_force_enable_micbias_v2(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_codec_force_enable_micbias_v2);

void * wcd939x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd939x_codec_get_dev_num);

void * wcd939x_get_codec_variant(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd939x_get_codec_variant);

void * wcd939x_get_micb_vout_ctl_val(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd939x_get_micb_vout_ctl_val);

int wcd939x_info_create_codec_entry(void)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_info_create_codec_entry);

void wcd939x_mbhc_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd939x_mbhc_deinit);

void * wcd939x_mbhc_get_impedance(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd939x_mbhc_get_impedance);

int wcd939x_mbhc_hs_detect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_mbhc_hs_detect);

void wcd939x_mbhc_hs_detect_exit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcd939x_mbhc_hs_detect_exit);

int wcd939x_mbhc_init(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_mbhc_init);

int wcd939x_mbhc_micb_adjust_voltage(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_mbhc_micb_adjust_voltage);

int wcd939x_mbhc_post_ssr_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_mbhc_post_ssr_init);

int wcd939x_mbhc_ssr_down(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_mbhc_ssr_down);

int wcd939x_micbias_control(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_micbias_control);

int wcd939x_slave_register_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_slave_register_notify);

void * wcd939x_soc_get_mbhc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcd939x_soc_get_mbhc);

int wcd939x_swr_dmic_register_notifier(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(wcd939x_swr_dmic_register_notifier);

/* ---- wcdcal_* (1) ---- */
void * wcdcal_get_fw_cal(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wcdcal_get_fw_cal);

/* ---- wcnss_* (5) ---- */
bool wcnss_check_pool_lists(void)
{
	return false;
}
EXPORT_SYMBOL(wcnss_check_pool_lists);

void wcnss_pre_alloc_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcnss_pre_alloc_reset);

bool wcnss_prealloc_check_memory_leak(void *a0)
{
	return false;
}
EXPORT_SYMBOL(wcnss_prealloc_check_memory_leak);

int wcnss_prealloc_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcnss_prealloc_get);

void wcnss_prealloc_put(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcnss_prealloc_put);

/* ---- wled_* (1) ---- */
int wled_flash_led_prepare(void)
{
	return 0;
}
EXPORT_SYMBOL(wled_flash_led_prepare);

/* ---- wlfw_* (119) ---- */
int wlfw_antenna_grant_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_antenna_grant_req_msg_v01_ei);

int wlfw_antenna_grant_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_antenna_grant_resp_msg_v01_ei);

int wlfw_antenna_switch_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_antenna_switch_req_msg_v01_ei);

int wlfw_antenna_switch_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_antenna_switch_resp_msg_v01_ei);

int wlfw_athdiag_read_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_athdiag_read_req_msg_v01_ei);

int wlfw_athdiag_read_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_athdiag_read_resp_msg_v01_ei);

int wlfw_athdiag_write_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_athdiag_write_req_msg_v01_ei);

int wlfw_athdiag_write_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_athdiag_write_resp_msg_v01_ei);

int wlfw_aux_uc_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_aux_uc_info_req_msg_v01_ei);

int wlfw_aux_uc_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_aux_uc_info_resp_msg_v01_ei);

int wlfw_bdf_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_bdf_download_req_msg_v01_ei);

int wlfw_bdf_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_bdf_download_resp_msg_v01_ei);

int wlfw_bmps_ctrl_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_bmps_ctrl_req_msg_v01_ei);

int wlfw_bmps_ctrl_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_bmps_ctrl_resp_msg_v01_ei);

int wlfw_cal_done_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_done_ind_msg_v01_ei);

int wlfw_cal_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_download_req_msg_v01_ei);

int wlfw_cal_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_download_resp_msg_v01_ei);

int wlfw_cal_report_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_report_req_msg_v01_ei);

int wlfw_cal_report_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_report_resp_msg_v01_ei);

int wlfw_cal_update_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_update_req_msg_v01_ei);

int wlfw_cal_update_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cal_update_resp_msg_v01_ei);

int wlfw_cap_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cap_req_msg_v01_ei);

int wlfw_cap_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_cap_resp_msg_v01_ei);

int wlfw_ddr_file_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ddr_file_download_req_msg_v01_ei);

int wlfw_ddr_file_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ddr_file_download_resp_msg_v01_ei);

int wlfw_device_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_device_info_req_msg_v01_ei);

int wlfw_device_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_device_info_resp_msg_v01_ei);

int wlfw_driver_async_data_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_driver_async_data_ind_msg_v01_ei);

int wlfw_dump_ddr_region_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_dump_ddr_region_ind_msg_v01_ei);

int wlfw_dynamic_feature_mask_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_dynamic_feature_mask_req_msg_v01_ei);

int wlfw_dynamic_feature_mask_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_dynamic_feature_mask_resp_msg_v01_ei);

int wlfw_fw_init_done_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_fw_init_done_ind_msg_v01_ei);

int wlfw_fw_mem_ready_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_fw_mem_ready_ind_msg_v01_ei);

int wlfw_fw_ready_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_fw_ready_ind_msg_v01_ei);

int wlfw_fw_ssr_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_fw_ssr_ind_msg_v01_ei);

void * wlfw_get_info_req_msg_v01_ei(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wlfw_get_info_req_msg_v01_ei);

void * wlfw_get_info_resp_msg_v01_ei(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wlfw_get_info_resp_msg_v01_ei);

int wlfw_host_cap_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_host_cap_req_msg_v01_ei);

int wlfw_host_cap_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_host_cap_resp_msg_v01_ei);

int wlfw_ind_register_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ind_register_req_msg_v01_ei);

int wlfw_ind_register_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ind_register_resp_msg_v01_ei);

int wlfw_ini_file_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ini_file_download_req_msg_v01_ei);

int wlfw_ini_file_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ini_file_download_resp_msg_v01_ei);

int wlfw_ini_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ini_req_msg_v01_ei);

int wlfw_ini_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_ini_resp_msg_v01_ei);

int wlfw_initiate_cal_download_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_initiate_cal_download_ind_msg_v01_ei);

int wlfw_initiate_cal_update_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_initiate_cal_update_ind_msg_v01_ei);

int wlfw_lpass_ssr_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_lpass_ssr_req_msg_v01_ei);

int wlfw_lpass_ssr_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_lpass_ssr_resp_msg_v01_ei);

int wlfw_m3_dump_upload_done_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_dump_upload_done_req_msg_v01_ei);

int wlfw_m3_dump_upload_done_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_dump_upload_done_resp_msg_v01_ei);

int wlfw_m3_dump_upload_req_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_dump_upload_req_ind_msg_v01_ei);

int wlfw_m3_dump_upload_segments_req_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_dump_upload_segments_req_ind_msg_v01_ei);

int wlfw_m3_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_info_req_msg_v01_ei);

int wlfw_m3_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_m3_info_resp_msg_v01_ei);

int wlfw_mac_addr_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_mac_addr_req_msg_v01_ei);

int wlfw_mac_addr_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_mac_addr_resp_msg_v01_ei);

int wlfw_misc_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_misc_req_msg_v01_ei);

int wlfw_misc_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_misc_resp_msg_v01_ei);

int wlfw_mlo_reconfig_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_mlo_reconfig_info_req_msg_v01_ei);

int wlfw_mlo_reconfig_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_mlo_reconfig_info_resp_msg_v01_ei);

int wlfw_msa_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_msa_info_req_msg_v01_ei);

int wlfw_msa_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_msa_info_resp_msg_v01_ei);

int wlfw_msa_ready_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_msa_ready_ind_msg_v01_ei);

int wlfw_msa_ready_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_msa_ready_req_msg_v01_ei);

int wlfw_msa_ready_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_msa_ready_resp_msg_v01_ei);

int wlfw_partner_chip_state_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_partner_chip_state_info_req_msg_v01_ei);

int wlfw_partner_chip_state_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_partner_chip_state_info_resp_msg_v01_ei);

int wlfw_pcie_gen_switch_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_pcie_gen_switch_req_msg_v01_ei);

int wlfw_pcie_gen_switch_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_pcie_gen_switch_resp_msg_v01_ei);

int wlfw_pcie_link_ctrl_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_pcie_link_ctrl_req_msg_v01_ei);

int wlfw_pcie_link_ctrl_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_pcie_link_ctrl_resp_msg_v01_ei);

int wlfw_phy_cap_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_phy_cap_req_msg_v01_ei);

int wlfw_phy_cap_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_phy_cap_resp_msg_v01_ei);

int wlfw_pin_connect_result_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_pin_connect_result_ind_msg_v01_ei);

int wlfw_power_save_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_power_save_req_msg_v01_ei);

int wlfw_power_save_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_power_save_resp_msg_v01_ei);

int wlfw_qdss_mem_ready_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_mem_ready_ind_msg_v01_ei);

int wlfw_qdss_trace_config_download_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_config_download_req_msg_v01_ei);

int wlfw_qdss_trace_config_download_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_config_download_resp_msg_v01_ei);

int wlfw_qdss_trace_data_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_data_req_msg_v01_ei);

int wlfw_qdss_trace_data_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_data_resp_msg_v01_ei);

int wlfw_qdss_trace_free_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_free_ind_msg_v01_ei);

int wlfw_qdss_trace_mem_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_mem_info_req_msg_v01_ei);

int wlfw_qdss_trace_mem_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_mem_info_resp_msg_v01_ei);

int wlfw_qdss_trace_mode_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_mode_req_msg_v01_ei);

int wlfw_qdss_trace_mode_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_mode_resp_msg_v01_ei);

int wlfw_qdss_trace_req_mem_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_req_mem_ind_msg_v01_ei);

int wlfw_qdss_trace_save_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_qdss_trace_save_ind_msg_v01_ei);

int wlfw_rejuvenate_ack_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_rejuvenate_ack_req_msg_v01_ei);

int wlfw_rejuvenate_ack_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_rejuvenate_ack_resp_msg_v01_ei);

int wlfw_rejuvenate_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_rejuvenate_ind_msg_v01_ei);

int wlfw_request_mem_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_request_mem_ind_msg_v01_ei);

void * wlfw_respond_get_info_ind_msg_v01_ei(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wlfw_respond_get_info_ind_msg_v01_ei);

int wlfw_respond_mem_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_respond_mem_req_msg_v01_ei);

int wlfw_respond_mem_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_respond_mem_resp_msg_v01_ei);

int wlfw_shutdown_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_shutdown_req_msg_v01_ei);

int wlfw_shutdown_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_shutdown_resp_msg_v01_ei);

int wlfw_soc_wake_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_soc_wake_req_msg_v01_ei);

int wlfw_soc_wake_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_soc_wake_resp_msg_v01_ei);

int wlfw_soft_sku_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_soft_sku_info_req_msg_v01_ei);

int wlfw_soft_sku_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_soft_sku_info_resp_msg_v01_ei);

int wlfw_subsys_restart_level_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_subsys_restart_level_req_msg_v01_ei);

int wlfw_subsys_restart_level_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_subsys_restart_level_resp_msg_v01_ei);

int wlfw_tme_lite_info_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_tme_lite_info_req_msg_v01_ei);

int wlfw_tme_lite_info_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_tme_lite_info_resp_msg_v01_ei);

int wlfw_vbatt_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_vbatt_req_msg_v01_ei);

int wlfw_vbatt_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_vbatt_resp_msg_v01_ei);

int wlfw_wfc_call_status_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wfc_call_status_req_msg_v01_ei);

int wlfw_wfc_call_status_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wfc_call_status_resp_msg_v01_ei);

int wlfw_wfc_call_twt_config_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wfc_call_twt_config_ind_msg_v01_ei);

int wlfw_wlan_cfg_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_cfg_req_msg_v01_ei);

int wlfw_wlan_cfg_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_cfg_resp_msg_v01_ei);

int wlfw_wlan_hw_init_cfg_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_hw_init_cfg_req_msg_v01_ei);

int wlfw_wlan_hw_init_cfg_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_hw_init_cfg_resp_msg_v01_ei);

int wlfw_wlan_mode_req_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_mode_req_msg_v01_ei);

int wlfw_wlan_mode_resp_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_wlan_mode_resp_msg_v01_ei);

int wlfw_xo_cal_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_xo_cal_ind_msg_v01_ei);

int wlfw_xo_trim_ind_msg_v01_ei(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wlfw_xo_trim_ind_msg_v01_ei);

/* ---- wsa883x_* (3) ---- */
void * wsa883x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wsa883x_codec_get_dev_num);

int wsa883x_codec_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wsa883x_codec_info_create_codec_entry);

int wsa883x_set_channel_map(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(wsa883x_set_channel_map);

/* ---- wsa884x_* (3) ---- */
void * wsa884x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wsa884x_codec_get_dev_num);

int wsa884x_codec_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wsa884x_codec_info_create_codec_entry);

int wsa884x_set_channel_map(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(wsa884x_set_channel_map);

/* ---- xiaomi_* (5) ---- */
void * xiaomi_get_gesture_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(xiaomi_get_gesture_type);

int xiaomi_register_panel_notifier(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_register_panel_notifier);

int xiaomi_touch_mievent_report_int(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_int);

int xiaomi_touch_mievent_report_str(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_str);

int xiaomi_unregister_panel_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_unregister_panel_notifier);

/* ---- zs_* (1) ---- */
int zs_map_object_straddle_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(zs_map_object_straddle_info);


/* ==================== 变量定义 ==================== */

int current_log_level;
EXPORT_SYMBOL(current_log_level);

struct qmi_elem_info dhms_mem_alloc_addr_info_type_v01_ei[1];
EXPORT_SYMBOL(dhms_mem_alloc_addr_info_type_v01_ei);

struct qmi_elem_info dms_get_mac_address_req_msg_v01_ei[1];
EXPORT_SYMBOL(dms_get_mac_address_req_msg_v01_ei);

struct qmi_elem_info dms_get_mac_address_resp_msg_v01_ei[1];
EXPORT_SYMBOL(dms_get_mac_address_resp_msg_v01_ei);

void *gprbus;
EXPORT_SYMBOL(gprbus);

struct qmi_elem_info ims_private_service_mt_invite_ind_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_mt_invite_ind_msg_v01_ei);

struct qmi_elem_info ims_private_service_subscribe_ind_req_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_subscribe_ind_req_msg_v01_ei);

struct qmi_elem_info ims_private_service_subscribe_ind_rsp_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_subscribe_ind_rsp_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_status_ind_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_status_ind_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_twt_config_req_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_twt_config_req_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei);

struct kobject low_lat_mem_kobject;
EXPORT_SYMBOL(low_lat_mem_kobject);

struct qmi_elem_info mem_alloc_generic_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_alloc_generic_req_msg_data_v01_ei);

struct qmi_elem_info mem_alloc_generic_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_alloc_generic_resp_msg_data_v01_ei);

struct qmi_elem_info mem_free_generic_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_free_generic_req_msg_data_v01_ei);

struct qmi_elem_info mem_free_generic_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_free_generic_resp_msg_data_v01_ei);

struct qmi_elem_info mem_query_size_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_query_size_req_msg_data_v01_ei);

struct qmi_elem_info mem_query_size_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_query_size_resp_msg_data_v01_ei);

void *memcheck_kgsl_memstat;
EXPORT_SYMBOL(memcheck_kgsl_memstat);

void *memcheck_walk_process_privates;
EXPORT_SYMBOL(memcheck_walk_process_privates);

void *mi_smart_refill_pools;
EXPORT_SYMBOL(mi_smart_refill_pools);

void *micam_amu_data;
EXPORT_SYMBOL(micam_amu_data);

void *miui_power_enhance;
EXPORT_SYMBOL(miui_power_enhance);

unsigned long pwrkey_irq_notifier_list;
EXPORT_SYMBOL(pwrkey_irq_notifier_list);

void *qcom_device_shutdown_in_progress;
EXPORT_SYMBOL(qcom_device_shutdown_in_progress);

struct bus_type soundwire_type;
EXPORT_SYMBOL(soundwire_type);
