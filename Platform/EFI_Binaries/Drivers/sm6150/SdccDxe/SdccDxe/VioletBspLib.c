#include "SdccBsp.h"
#include <Uefi.h>

/* Violet (SM6150) Base Addresses from DTS */
/* sdhci@7c4000: reg = <0x7c4000 ...> */
#define VIOLET_SDC1_HC_ADDR 0x07C4000
/* SDC2 assumed at standard offset if not explicitly in user snippet, using
 * standard map */
#define VIOLET_SDC2_HC_ADDR 0x8804000
#define VIOLET_SDC4_HC_ADDR 0x8844000

/* Max number of slots supported by the Board */
#define SDCC_BSP_NUM_SLOTS 4
#define SDCC_BSP_INVALID_SLOT SDCC_BSP_NUM_SLOTS

/* Slot configuration information for Violet */
/*
 * from DTS:
 * qcom,bus-width = <0x08>; -> SDCC_BSP_8BIT_SLOT
 * qcom,nonremovable; -> SDCC_BSP_EMBEDDED_MEM_SLOT
 */
static sdcc_bsp_slot_type sdcc_bsp_slot_config[SDCC_BSP_NUM_SLOTS] = {
    (SDCC_BSP_EMBEDDED_MEM_SLOT | SDCC_BSP_8BIT_SLOT), /* SDC1 (eMMC) */
    SDCC_BSP_SD_SLOT,                                  /* SDC2 (SD Card) */
    SDCC_BSP_NO_SLOT, SDCC_BSP_NO_SLOT};

static sdcc_bsp_slot_access_type
    sdcc_bsp_slot_access_config[SDCC_BSP_NUM_SLOTS] = {
        SDCC_BSP_SLOT_INTERNAL, SDCC_BSP_SLOT_EXTERNAL, SDCC_BSP_SLOT_INVALID,
        SDCC_BSP_SLOT_INVALID};

VOID sdcc_bsp_target_cap_overrides(UINT32 slot_num) { return; }

sdcc_bsp_err_type sdcc_bsp_get_base_addr(sdcc_base_addr_type *sdcc_base_addr) {
  sdcc_base_addr->sdc1_base_hc = VIOLET_SDC1_HC_ADDR;
  sdcc_base_addr->sdc2_base_hc = VIOLET_SDC2_HC_ADDR;
  sdcc_base_addr->sdc3_base_hc = 0;
  sdcc_base_addr->sdc4_base_hc = VIOLET_SDC4_HC_ADDR;

  return SDCC_BSP_NO_ERROR;
}

sdcc_bsp_slot_type sdcc_bsp_get_slot_type(UINT32 slot_num) {
  if (slot_num >= SDCC_BSP_NUM_SLOTS)
    return SDCC_BSP_NO_SLOT;
  return sdcc_bsp_slot_config[slot_num];
}

sdcc_bsp_slot_access_type sdcc_bsp_get_slot_access_type(UINT32 slot_num) {
  if (slot_num >= SDCC_BSP_NUM_SLOTS)
    return SDCC_BSP_SLOT_INVALID;
  return sdcc_bsp_slot_access_config[slot_num];
}

sdcc_bsp_err_type sdcc_bsp_gpio_control(UINT32 slot_num, UINT32 state) {
  return SDCC_BSP_NO_ERROR;
}

sdcc_bsp_clk_type sdcc_bsp_get_max_supported_clk(UINT32 driveno) {
  /*
   * DTS qcom,clk-rates for SDC1:
   * 0x16e36000 (384 MHz), 0xb71b000 (192 MHz) ...
   */
  switch (driveno) {
  case SDCC_BSP_SLOT_0:
    return SDCC_BSP_CLK_384_MHZ; // eMMC
  case SDCC_BSP_SLOT_1:
    return SDCC_BSP_CLK_201_MHZ; // SD
  default:
    return SDCC_BSP_CLK_INVALID;
  }
}

sdcc_bsp_clk_type sdcc_bsp_get_hs200_supported_freq(UINT32 driveno) {
  /* Matching DTS 192MHz point */
  return SDCC_BSP_CLK_192_MHZ;
}

sdcc_bsp_clk_type sdcc_bsp_get_hs400_supported_freq(UINT32 driveno) {
  /* Matching DTS 384MHz point */
  return SDCC_BSP_CLK_384_MHZ;
}

void sdcc_bsp_cache_operation(sdcc_bsp_cache_op_type op, void *addr,
                              UINT32 length) {}

void sdcc_bsp_memory_barrier(void) {}

UINT32 sdcc_bsp_get_slot_count(VOID) { return SDCC_BSP_NUM_SLOTS; }

UINT8
sdcc_bsp_get_platform_speed_config(UINT8 speed_mode) {
  /* from DTS: qcom,bus-speed-mode = "HS400_1p8v\0HS200_1p8v\0DDR_1p8v" */
  return speed_mode;
}
