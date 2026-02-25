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
#include <sys/types.h>

#include "PlatformUtils.h"

#define GICD_BASE 0x17A00000
#define GICR_BASE 0x17A60000
#define GICR_WAKER_OFFSET 0x14
#define GICR_SGI_BASE_OFFSET 0x10000
#define GICD_ISENABLER_OFFSET 0x100

#define QTIMER_CTRL_FRAME 0x17C20000
#define QTIMER_FRAME0 0x17C21000
#define CNTFRQ_EXPECTED 19200000

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

VOID SetWatchDogState(BOOLEAN Enable) {
  MmioWrite32(APSS_WDT_BASE + APSS_WDT_ENABLE_OFFSET, Enable);
}

VOID InitializeSharedUartBuffers(VOID) {
  INTN *pFbConPosition =
      (INTN *)(FixedPcdGet32(PcdMipiFrameBufferAddress) +
               (FixedPcdGet32(PcdMipiFrameBufferWidth) *
                FixedPcdGet32(PcdMipiFrameBufferHeight) *
                FixedPcdGet32(PcdMipiFrameBufferPixelBpp) / 8));

  *(pFbConPosition + 0) = 0;
  *(pFbConPosition + 1) = 0;
}

VOID UartInit(VOID) {
  SerialPortInitialize();

  InitializeSharedUartBuffers();

  // Avoid notch area
  DEBUG((EFI_D_ERROR, "\n\n\n\nRenegade Project edk2-msm (AArch64)\n"));
  DEBUG((EFI_D_ERROR, "Firmware version %s built %a %a\n\n",
         (CHAR16 *)PcdGetPtr(PcdFirmwareVersionString), __TIME__, __DATE__));
}

// VOID DumpUartState(VOID)
// {
//   DEBUG((EFI_D_ERROR, "--- XBL UART State Dump (0x%x) ---\n", UART_BASE));

//   UINT32 Fr   = MmioRead32(UART_BASE + UART_FR_OFFSET);
//   UINT32 Ibrd = MmioRead32(UART_BASE + UART_IBRD_OFFSET);
//   UINT32 Fbrd = MmioRead32(UART_BASE + UART_FBRD_OFFSET);
//   UINT32 LcrH = MmioRead32(UART_BASE + UART_LCRH_OFFSET);
//   UINT32 Cr   = MmioRead32(UART_BASE + UART_CR_OFFSET);
//   UINT32 Imsc = MmioRead32(UART_BASE + UART_IMSC_OFFSET);
//   UINT32 Ris  = MmioRead32(UART_BASE + UART_RIS_OFFSET);
//   UINT32 Mis  = MmioRead32(UART_BASE + UART_MIS_OFFSET);

//   DEBUG(
//       (EFI_D_ERROR, "UART_CR: 0x%x (TXE:%d, RXE:%d, UARTEN:%d)\n", Cr,
//        (Cr >> 8) & 1, (Cr >> 9) & 1, (Cr & 1)));
//   DEBUG(
//       (EFI_D_ERROR, "UART_FR: 0x%x (TXFE:%d, RXFF:%d)\n", Fr, (Fr >> 7) & 1,
//        (Fr >> 6) & 1));
//   DEBUG(
//       (EFI_D_ERROR, "UART_IMSC (Mask): 0x%x (RXIM:%d, TXIM:%d)\n", Imsc,
//        (Imsc >> 4) & 1, (Imsc >> 5) & 1));
//   DEBUG((EFI_D_ERROR, "UART_RIS (Raw): 0x%x\n", Ris));
//   DEBUG((EFI_D_ERROR, "UART_MIS (Masked): 0x%x\n", Mis));
//   DEBUG((EFI_D_ERROR, "UART_BAUD: IBRD=%d, FBRD=%d\n", Ibrd, Fbrd));
//   DEBUG((EFI_D_ERROR, "UART_LCR: 0x%x (FIFOEn:%d)\n", LcrH, (LcrH >> 4) &
//   1));
// }

// VOID DumpGicState(VOID)
// {
//   DEBUG((EFI_D_ERROR, "--- XBL GIC State Dump ---\n"));

//   // 1. GICD (Distributor)
//   UINT32 GicdCtlr = MmioRead32(GICD_BASE + 0x0);
//   DEBUG((EFI_D_ERROR, "GICD_CTLR: 0x%08x\n", GicdCtlr));

//   // UART SPI 356 -> index 11 (SPIs 352-383), bit 4
//   UINT32 UartSpiReg = MmioRead32(GICD_BASE + GICD_ISENABLER_OFFSET + (11 *
//   4)); DEBUG(
//       (EFI_D_ERROR, "GICD_ISENABLER[11]: 0x%08x (UART SPI 356 Enable: %d)\n",
//        UartSpiReg, (UartSpiReg >> 4) & 1));

//   // 2. GICR (Redistributor)
//   UINT32 WakerAddr = GICR_BASE + GICR_WAKER_OFFSET;
//   UINT32 Waker     = MmioRead32(WakerAddr);
//   DEBUG(
//       (EFI_D_ERROR,
//        "GICR_WAKER: 0x%08x (ProcessorSleep: %d, ChildrenAsleep: %d)\n",
//        Waker, (Waker >> 1) & 1, (Waker >> 2) & 1));

//   // Check GICR PPIs (ISENABLER0)
//   UINT32 GicrIsEn = MmioRead32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100);
//   DEBUG((EFI_D_ERROR, "GICR_ISENABLER0: 0x%08x\n", GicrIsEn));
//   DEBUG((EFI_D_ERROR, "  PPI 27 (Virtual Timer): %d\n", (GicrIsEn >> 27) &
//   1)); DEBUG((EFI_D_ERROR, "  PPI 30 (Physical Timer): %d\n", (GicrIsEn >>
//   30) & 1));
// }

// VOID DumpTimerState(VOID)
// {
//   DEBUG((EFI_D_ERROR, "--- XBL Timer State Dump ---\n"));
//   UINT64 Cntfrq = ArmReadCntFrq();
//   DEBUG((EFI_D_ERROR, "CNTFRQ_EL0: %llu Hz\n", Cntfrq));

//   // Read CNTPCT_EL0 by MRS -> ArmReadCntPct returns UINT64
//   UINT64 Cntpct = ArmReadCntPct();
//   DEBUG((EFI_D_ERROR, "CNTPCT_EL0: 0x%llx\n", Cntpct));

//   UINT32 CntvCtl  = ArmReadCntvCtl();
//   UINT64 CntvCval = ArmReadCntvCval();
//   DEBUG(
//       (EFI_D_ERROR, "CNTV_CTL_EL0: 0x%x (En:%d, Mask:%d, Stat:%d)\n",
//       CntvCtl,
//        CntvCtl & 1, (CntvCtl >> 1) & 1, (CntvCtl >> 2) & 1));
//   DEBUG((EFI_D_ERROR, "CNTV_CVAL_EL0: 0x%llx\n", CntvCval));

//   // MMIO frame reads (optional / informative)
//   UINT32 CntcrMmio  = MmioRead32(QTIMER_FRAME0 + 0x00);
//   UINT32 CntfrqMmio = MmioRead32(QTIMER_FRAME0 + 0x10);
//   DEBUG((EFI_D_ERROR, "MMIO Frame 0 (0x%x):\n", QTIMER_FRAME0));
//   DEBUG((EFI_D_ERROR, "  CNTCR (0x00): 0x%x\n", CntcrMmio));
//   DEBUG((EFI_D_ERROR, "  CNTFRQ (0x10): %u\n", CntfrqMmio));
// }

/*
  ValidatePlatformContracts()
  - Implements the checklist checks and safe fixes:
    * CNTFRQ_EL0 correctness
    * Virtual timer enabled and scheduled
    * GICD/GICR enablement for UART SPI & PPI27
    * UART hardware enabled & interrupts unmasked
  Returns: BOOLEAN TRUE=ok, FALSE=fatal
*/
BOOLEAN ValidatePlatformContracts(VOID) {
  BOOLEAN ok = TRUE;

  DEBUG((EFI_D_ERROR, "--- PLATFORM CONTRACT VALIDATION START ---\n"));

  // 1) CNTFRQ check
  UINT64 cntfrq = ArmReadCntFrq();
  DEBUG((EFI_D_ERROR, "Check: CNTFRQ_EL0 = %llu (expected %u)\n", cntfrq,
         CNTFRQ_EXPECTED));
  if (cntfrq == 0) {
    DEBUG((EFI_D_ERROR,
           "CNTFRQ_EL0 is 0 - attempting to write fallback value\n"));
    ArmWriteCntFrq(CNTFRQ_EXPECTED);
    // MicroSecondDelay(10);
    cntfrq = ArmReadCntFrq();
    DEBUG((EFI_D_ERROR, "CNTFRQ_EL0 after write: %llu\n", cntfrq));
  }
  if (cntfrq != CNTFRQ_EXPECTED) {
    DEBUG((EFI_D_ERROR,
           "FATAL: CNTFRQ_EL0 != expected. Windows relies on stable timer.\n"));
    ok = FALSE;
  }

  // 2) Virtual timer (CNTV) enabled and scheduled
  UINT32 cntv_ctl = ArmReadCntvCtl();
  DEBUG((EFI_D_ERROR, "Check: CNTV_CTL_EL0 = 0x%x\n", cntv_ctl));
  if ((cntv_ctl & 1) == 0) {
    DEBUG((EFI_D_ERROR,
           "CNTV disabled - enabling virtual timer and scheduling.\n"));
    ArmWriteCntvCtl(1); // enable, unmasked
    // MicroSecondDelay(10);
    cntv_ctl = ArmReadCntvCtl();
    DEBUG((EFI_D_ERROR, "CNTV_CTL after set: 0x%x\n", cntv_ctl));
  }

  // schedule next tick ~100ms in future if not scheduled
  UINT64 now = ArmReadCntPct();
  UINT64 next = now + (CNTFRQ_EXPECTED / 10); // 100ms
  ArmWriteCntvCval(next);
  DEBUG((EFI_D_ERROR, "Scheduled CNTV_CVAL => +100ms (now=0x%llx)\n", now));

  // re-check CNTV condition: cval must be > now
  UINT64 cval = ArmReadCntvCval();
  if (cval <= now) {
    DEBUG((EFI_D_ERROR,
           "FATAL: CNTV_CVAL <= CNTPCT (timer not scheduled correctly)\n"));
    ok = FALSE;
  }

  // 3) GIC Distributor: ensure UART SPI 356 enabled
  UINT32 gicd_ctlr = MmioRead32(GICD_BASE + 0x0);
  DEBUG((EFI_D_ERROR, "GICD_CTLR (pre): 0x%08x\n", gicd_ctlr));
  UINT32 uartSpiIdxAddr =
      GICD_BASE + GICD_ISENABLER_OFFSET + (11 * 4); // 11 => SPI 352-383
  UINT32 uartSpiReg = MmioRead32(uartSpiIdxAddr);
  if (((uartSpiReg >> 4) & 1) == 0) {
    DEBUG((EFI_D_ERROR, "UART SPI 356 not enabled in GICD -> enabling.\n"));
    MmioWrite32(uartSpiIdxAddr, (1 << 4));
    // MicroSecondDelay(10);
    uartSpiReg = MmioRead32(uartSpiIdxAddr);
    DEBUG(
        (EFI_D_ERROR, "GICD_ISENABLER[11] after write: 0x%08x\n", uartSpiReg));
  }

  // 4) GICR: ensure waker awake & PPI 27 enabled
  UINT32 waker = MmioRead32(GICR_BASE + GICR_WAKER_OFFSET);
  DEBUG((EFI_D_ERROR, "GICR_WAKER pre: 0x%08x\n", waker));
  if (waker & (1 << 1)) {
    DEBUG((EFI_D_ERROR, "ProcessorSleep set - clearing...\n"));
    MmioWrite32(GICR_BASE + GICR_WAKER_OFFSET, waker & ~(1 << 1));
    // wait for children asleep to clear
    while (MmioRead32(GICR_BASE + GICR_WAKER_OFFSET) & (1 << 2)) {
      CpuPause();
    }
    DEBUG((EFI_D_ERROR, "GICR woke - WAKER now: 0x%08x\n",
           MmioRead32(GICR_BASE + GICR_WAKER_OFFSET)));
  }

  // Enable PPI 27 in redistributor ISENABLER0
  UINT32 gicr_isenabler0 = MmioRead32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100);
  DEBUG((EFI_D_ERROR, "GICR_ISENABLER0 pre: 0x%08x\n", gicr_isenabler0));
  if (((gicr_isenabler0 >> 27) & 1) == 0) {
    DEBUG(
        (EFI_D_ERROR, "Enabling PPI 27 (Virtual Timer) in GICR_ISENABLER0\n"));
    MmioWrite32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100, (1 << 27));
    // MicroSecondDelay(10);
    gicr_isenabler0 = MmioRead32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100);
    DEBUG((EFI_D_ERROR, "GICR_ISENABLER0 after write: 0x%08x\n",
           gicr_isenabler0));
  }

  // 5) UART hardware checks & enable
  UINT32 uart_cr = MmioRead32(UART_BASE + UART_CR_OFFSET);
  UINT32 uart_lcrh = MmioRead32(UART_BASE + UART_LCRH_OFFSET);
  UINT32 uart_ibrd = MmioRead32(UART_BASE + UART_IBRD_OFFSET);
  UINT32 uart_fbrd = MmioRead32(UART_BASE + UART_FBRD_OFFSET);

  DEBUG((EFI_D_ERROR, "UART_CR pre: 0x%x, LCRH:0x%x, IBRD:%d FBRD:%d\n",
         uart_cr, uart_lcrh, uart_ibrd, uart_fbrd));

  // Quick heuristic: if CR==0 then enable UART.
  if (uart_cr == 0) {
    DEBUG((EFI_D_ERROR, "UART_CR == 0 -> enabling TX/RX/UARTEN and unmasking "
                        "RX/TX interrupts\n"));
    MmioWrite32(UART_BASE + UART_CR_OFFSET,
                (1 << 0) /*UARTEN*/ | (1 << 8) /*TXE*/ | (1 << 9) /*RXE*/);
    // unmask RX/TX interrupts
    MmioWrite32(UART_BASE + UART_IMSC_OFFSET, (1 << 4) | (1 << 5));
    // MicroSecondDelay(10);
    uart_cr = MmioRead32(UART_BASE + UART_CR_OFFSET);
    DEBUG((EFI_D_ERROR, "UART_CR after write: 0x%x\n", uart_cr));
  }

  // Validate baud registers exist (non-zero)
  if (uart_ibrd == 0 && uart_fbrd == 0) {
    DEBUG((EFI_D_ERROR, "Warning: UART baud dividers appear zero. Ensure UART "
                        "clock is enabled in GCC.\n"));
    // We do not forcibly change baud here; it's platform clock dependent.
  }

// 6) sanity: priority mask (pmr) should not be zero (basic check)
// If library provides ArmReadIccPmr - use it else skip (wrapped in try)
#if defined(ArmReadIccPmr)
  UINT32 pmr = ArmReadIccPmr();
  DEBUG((EFI_D_ERROR, "ICC_PMR_EL1: 0x%x\n", pmr));
  if (pmr == 0) {
    DEBUG((EFI_D_ERROR, "Warning: ICC_PMR_EL1 == 0 (may mask interrupts). "
                        "Attempting to set to 0x80\n"));
    ArmWriteIccPmr(0x80);
    // MicroSecondDelay(10);
    DEBUG((EFI_D_ERROR, "ICC_PMR_EL1 after write: 0x%x\n", ArmReadIccPmr()));
  }
#endif

  // Final decision
  if (!ok) {
    DEBUG((EFI_D_ERROR, "PLATFORM CONTRACT VALIDATION FAILED - HALT\n"));
    DumpUartState();
    DumpGicState();
    DumpTimerState();
    CpuDeadLoop(); // Stop here - unsafe to handoff to Windows
    return FALSE;
  }

  DEBUG((EFI_D_ERROR, "--- PLATFORM CONTRACT VALIDATION PASSED ---\n"));
  return TRUE;
}

/*--- Existing helper dumps reused in handoff ---*/
// VOID DumpAllState(VOID) {
//   DumpUartState();
//   DumpGicState();
//   DumpTimerState();
// }

/* PlatformInitialize: integrates validation and safe handoff actions */
VOID PlatformInitialize() {
  UartInit();

  // Disable WatchDog Timer (safe)
  SetWatchDogState(FALSE);

  DEBUG((EFI_D_ERROR, "--- HARDWARE HANDOFF: PRE-VALIDATION ---\n"));

  // 1) Validate platform contracts and apply minimal safe fixes.
  if (!ValidatePlatformContracts()) {
    // ValidatePlatformContracts will dead-loop on fatal; this is defensive.
    DEBUG(
        (EFI_D_ERROR,
         "Platform validation failed - cannot continue to Windows handoff.\n"));
    return;
  }

  // 2) Final platform handoff actions that mirror your earlier handoff:
  //    - ensure virtual timer remains enabled and scheduled
  ArmWriteCntvCtl(1);
  ArmWriteCntvCval(ArmReadCntPct() + (CNTFRQ_EXPECTED / 10)); // +100ms
  DEBUG((EFI_D_ERROR, "Handoff: Timer Enabled & Scheduled (+100ms) 0x%llx\n",
         ArmReadCntPct()));

  //    - ensure UART SPI and PPI are enabled (idempotent - already performed by
  //    validation)
  // GICD: UART SPI 356 -> index 11, bit 4
  MmioWrite32(GICD_BASE + GICD_ISENABLER_OFFSET + (11 * 4), (1 << 4));
  DEBUG((EFI_D_ERROR, "Handoff: UART SPI 356 Enabled in GICD %x\n",
         MmioRead32(GICD_BASE + GICD_ISENABLER_OFFSET + (11 * 4))));

  // Ensure GIC Redistributor PPI 27 is enabled
  MmioWrite32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100, (1 << 27));
  DEBUG((EFI_D_ERROR, "Handoff: PPI 27 (Virtual Timer) Enabled in GICR %x\n",
         MmioRead32(GICR_BASE + GICR_SGI_BASE_OFFSET + 0x100)));

  // Ensure UART hardware is enabled/unmasked (idempotent)
  MmioWrite32(UART_BASE + UART_CR_OFFSET, (1 << 0) | (1 << 8) | (1 << 9));
  MmioWrite32(UART_BASE + UART_IMSC_OFFSET, (1 << 4) | (1 << 5));
  DEBUG((EFI_D_ERROR, "Handoff: UART Hardware Enabled & Unmasked %x\n",
         MmioRead32(UART_BASE + UART_IMSC_OFFSET)));

  // FINAL: dump everything for post-check
  // DumpAllState();

  MmioWrite32(UART_BASE + UART_CR_OFFSET, 0xFFFFFFFF);
  DEBUG((EFI_D_ERROR, "UART_CR test readback: 0x%x\n",
         MmioRead32(UART_BASE + UART_CR_OFFSET)));

  DEBUG((EFI_D_ERROR, "QUPV3_WRAP0_CORE_CBCR: 0x%x\n", MmioRead32(0x00117004)));
  DEBUG((EFI_D_ERROR, "QUPV3_WRAP0_AHB_CBCR: 0x%x\n", MmioRead32(0x00117008)));

  DEBUG((EFI_D_ERROR, "PlatformInitialize Complete (Ready for Windows).\n"));
}
