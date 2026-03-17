#include <Library/ArmLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/MemoryMapHelperLib.h>
#include <Library/PcdLib.h>
#include <Library/PlatformPrePiLib.h>
#include <Library/PrintLib.h>
#include <Library/SerialPortLib.h>
#include <Library/TimerLib.h>
#include <sys/types.h>

#include "PlatformUtils.h"

#define GICD_BASE 0x17A00000
#define GICR_BASE 0x17A60000
#define GICR_WAKER_OFFSET 0x14
#define GICR_SGI_BASE_OFFSET 0x10000
#define GICD_ISENABLER_OFFSET 0x100

#define SDC1_BASE 0x07C4000

#define QTIMER_CTRL_FRAME 0x17C20000
#define QTIMER_FRAME0 0x17C21000
#define CNTFRQ_EXPECTED 19200000

#define DISP_CC_BASE 0x0AF00000
#define DISP_CC_MDSS_AHB_CLK_OFFSET 0x2048
#define DISP_CC_MDSS_MDP_CLK_OFFSET 0x2008
#define DISP_CC_MDSS_PCLK0_CLK_OFFSET 0x2004
#define DISP_CC_MDSS_VSYNC_CLK_OFFSET 0x2020

#define UART_BASE 0x880000
#define UART_DR_OFFSET 0x00
#define UART_FR_OFFSET 0x18
#define UART_IBRD_OFFSET 0x24
#define UART_FBRD_OFFSET 0x28
#define UART_LCRH_OFFSET 0x2C
#define UART_CR_OFFSET 0x30
#define UART_IMSC_OFFSET 0x38
#define UART_RIS_OFFSET 0x3C
#define UART_MIS_OFFSET 0x40

VOID SetWatchDogState(BOOLEAN Enable)
{
  MmioWrite32(APSS_WDT_BASE + APSS_WDT_ENABLE_OFFSET, Enable);
}

VOID InitializeSharedUartBuffers(VOID)
{
  INTN *pFbConPosition =
      (INTN *)(FixedPcdGet32(PcdMipiFrameBufferAddress) +
               (FixedPcdGet32(PcdMipiFrameBufferWidth) *
                FixedPcdGet32(PcdMipiFrameBufferHeight) *
                FixedPcdGet32(PcdMipiFrameBufferPixelBpp) / 8));

  *(pFbConPosition + 0) = 0;
  *(pFbConPosition + 1) = 0;
}

VOID EFIAPI DumpXblSdccState(VOID) {
  DEBUG((EFI_D_ERROR, "\n--- [XBL HANDOFF DIAGNOSTIC DUMP] ---\n"));

  // 1. Standard SDHC Registers (0x00 - 0x3F)
  DEBUG((EFI_D_ERROR, "[SDHC STANDARD REGS]\n"));
  DEBUG((EFI_D_ERROR, "SDMA_ADDR (0x00): 0x%08x\n", MmioRead32(SDC1_BASE + 0x00)));
  DEBUG((EFI_D_ERROR, "BLK_SIZE  (0x04): 0x%08x\n", MmioRead32(SDC1_BASE + 0x04)));
  DEBUG((EFI_D_ERROR, "ARGUMENT  (0x08): 0x%08x\n", MmioRead32(SDC1_BASE + 0x08)));
  DEBUG((EFI_D_ERROR, "XFER_MODE (0x0C): 0x%08x\n", MmioRead32(SDC1_BASE + 0x0C)));
  DEBUG((EFI_D_ERROR, "CMD_REG   (0x0E): 0x%04x\n", MmioRead16(SDC1_BASE + 0x0E)));
  DEBUG((EFI_D_ERROR, "HOST_CTL1 (0x28): 0x%02x\n", MmioRead8(SDC1_BASE + 0x28)));
  DEBUG((EFI_D_ERROR, "PWR_CTL   (0x29): 0x%02x\n", MmioRead8(SDC1_BASE + 0x29)));
  DEBUG((EFI_D_ERROR, "CLK_CTL   (0x2C): 0x%04x\n", MmioRead16(SDC1_BASE + 0x2C)));
  DEBUG((EFI_D_ERROR, "INT_STAT  (0x30): 0x%08x\n", MmioRead32(SDC1_BASE + 0x30)));
  DEBUG((EFI_D_ERROR, "INT_EN    (0x34): 0x%08x\n", MmioRead32(SDC1_BASE + 0x34)));
  DEBUG((EFI_D_ERROR, "CAPS_ALL  (0x40): 0x%08x %08x\n", MmioRead32(SDC1_BASE + 0x40), MmioRead32(SDC1_BASE + 0x44)));

  // 2. Qualcomm Vendor Specific Block (0x500+)
  DEBUG((EFI_D_ERROR, "\n[QCOM VENDOR REGS]\n"));
  DEBUG((EFI_D_ERROR, "VENDOR_FUNC (0x50C): 0x%08x\n", MmioRead32(SDC1_BASE + 0x50C)));
  DEBUG((EFI_D_ERROR, "DLL_CONFIG  (0x100): 0x%08x\n", MmioRead32(SDC1_BASE + 0x100)));
  DEBUG((EFI_D_ERROR, "DLL_STATUS  (0x108): 0x%08x\n", MmioRead32(SDC1_BASE + 0x108)));
  DEBUG((EFI_D_ERROR, "HC_MODE     (0x78) : 0x%08x\n", MmioRead32(SDC1_BASE + 0x78)));
  DEBUG((EFI_D_ERROR, "VEND_CAP_LOK(0x21C): 0x%08x\n", MmioRead32(SDC1_BASE + 0x21C)));

  // 3. CMDQ (Command Queue) Block (0x1000+)
  DEBUG((EFI_D_ERROR, "\n[CQE/CMDQ REGS]\n"));
  DEBUG((EFI_D_ERROR, "CQCAP       (0x1000): 0x%08x\n", MmioRead32(SDC1_BASE + 0x1000)));
  DEBUG((EFI_D_ERROR, "CQCTL       (0x1008): 0x%08x\n", MmioRead32(SDC1_BASE + 0x1008)));
  DEBUG((EFI_D_ERROR, "CQIS        (0x1010): 0x%08x\n", MmioRead32(SDC1_BASE + 0x1010)));

  DEBUG((EFI_D_ERROR, "--- [END DIAGNOSTIC DUMP] ---\n\n"));
}

VOID UartInit(VOID)
{
  SerialPortInitialize();

  InitializeSharedUartBuffers();

  // Avoid notch area
  DEBUG((EFI_D_ERROR, "\n\n\n\nRenegade Project edk2-msm (AArch64)\n"));
  DEBUG(
      (EFI_D_ERROR, "Firmware version %s built %a %a\n\n",
       (CHAR16 *)PcdGetPtr(PcdFirmwareVersionString), __TIME__, __DATE__));
}

VOID ConfigureIOMMUContextBankCacheSetting(
    UINT32 ContextBankId, BOOLEAN CacheCoherent)
{
  UINT32 ContextBankAddr =
      SMMU_BASE + SMMU_CTX_BANK_0_OFFSET + ContextBankId * SMMU_CTX_BANK_SIZE;
      
  MmioWrite32(
      ContextBankAddr + SMMU_CTX_BANK_SCTLR_OFFSET,
      CacheCoherent ? SMMU_CCA_SCTLR : SMMU_NON_CCA_SCTLR);
      
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_TTBR0_0_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_TTBR0_1_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_TTBR1_0_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_TTBR1_1_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_MAIR0_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_MAIR1_OFFSET, 0);
  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_TTBCR_OFFSET, 0);

  MmioWrite32(ContextBankAddr + SMMU_CTX_BANK_FSR_OFFSET, 0xFFFFFFFF);
}

VOID ConfigureIOMMUStreamMapping(
    UINT32 MappingIndex, UINT16 StreamId, UINT32 ContextBankId)
{
  /* 1. Program SMR (Stream Matching Register) */
  MmioWrite32(
      SMMU_BASE + SMMU_SMR0_OFFSET + MappingIndex * 4,
      SMMU_SMR_VALID | (StreamId & SMMU_SMR_ID_MASK));

  /* 2. Program S2CR (Stream to Context Register) to BYPASS mode */
  MmioWrite32(
      SMMU_BASE + SMMU_S2CR0_OFFSET + MappingIndex * 4,
      (SMMU_S2CR_TYPE_BYPASS << 16) | (ContextBankId << SMMU_S2CR_CBNDX_SHIFT));

  /* 3. Program CBAR (Context Bank Attribute Register) to BYPASS */
  /* This marks the bank as "In Use" so the Dxe driver won't re-allocate it */
  MmioWrite32(
      SMMU_BASE + SMMU_GLOBAL_REGION1_OFFSET + SMMU_CBAR0_OFFSET + ContextBankId * 4,
      (SMMU_CBAR_TYPE_S1_BYPASS << 16));

  /* 4. Program CBA2R (Context Bank Attribute 2 Register) for 64-bit */
  MmioWrite32(
      SMMU_BASE + SMMU_GLOBAL_REGION1_OFFSET + SMMU_CBA2R0_OFFSET + ContextBankId * 4,
      SMMU_CBA2R_VA64);
}

/* PlatformInitialize: integrates validation and safe handoff actions */
VOID PlatformInitialize()
{
  UartInit();
  SetWatchDogState(FALSE);
  // SMMU Bypass for SDCC1/SDCC2 (stream IDs 0x160 / 0x260).
  // NOTE: When S2CR TYPE=BYPASS, the context bank SCTLR is entirely ignored by
  // the SMMU hardware - there is no active S1 translation stage, so the
  // CacheCoherent argument below does not affect DMA behaviour at all.
  // Keeping TRUE preserves the previously confirmed working state.
    ConfigureIOMMUContextBankCacheSetting(SDHC1_CTX_BANK, TRUE);
    // ConfigureIOMMUStreamMapping(0, SDHC1_SID, SDHC1_CTX_BANK); // found to be very dangerous 
    ConfigureIOMMUContextBankCacheSetting(SDHC2_CTX_BANK, TRUE);
    // ConfigureIOMMUStreamMapping(1, SDHC2_SID, SDHC2_CTX_BANK);
  
}
