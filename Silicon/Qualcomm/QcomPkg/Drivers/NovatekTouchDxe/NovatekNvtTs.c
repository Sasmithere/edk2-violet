#include <Uefi.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

#include <Protocol/AbsolutePointer.h>
#include <Protocol/EFIClock.h>
#include <Protocol/EFII2C.h>
#include <Protocol/EFITlmm.h>

#include "NovatekNvtTs.h"

// Instance Template
NVT_INTERNAL_DATA mNvtInstanceTemplate =
                      {NVT_TCH_INSTANCE_SIGNATURE,
                       0,
                       0,
                       {
                           AbsPReset,
                           AbsPGetState,
                           NULL,
                           NULL,
                       },
                       {0},
                       NULL,
                       NULL,
                       FALSE,
                       0,
                       NULL,
                       FALSE,
                       NULL,
                       NULL,
                       NULL,
                       0,
                       {0}},
                  *gNvtI2CInstance;

// Binding
EFI_DRIVER_BINDING_PROTOCOL gNvtDriverBinding = {
    NvtAbsolutePointerDriverBindingSupported,
    NvtAbsolutePointerDriverBindingStart,
    NvtAbsolutePointerDriverBindingStop,
    0x1,
    NULL,
    NULL,
};

static NOVATEK_I2C_DEVICE *gNvtDeviceIo = NULL;

VOID EFIAPI SyncPollCallback(IN EFI_EVENT Event, IN VOID *Context);
VOID EFIAPI TouchWorkerCallback(IN EFI_EVENT Event, IN VOID *Context);

EFI_STATUS
EFIAPI
NvtInitialize(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_STATUS Status;

  Status = EfiLibInstallDriverBindingComponentName2(
      ImageHandle, SystemTable, &gNvtDriverBinding, ImageHandle,
      &gNvtDriverComponentName, &gNvtDriverComponentName2);
  ASSERT_EFI_ERROR(Status);

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingSupported(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath)
{
  EFI_STATUS          Status;
  NOVATEK_I2C_DEVICE *NvtDeviceIo;

  Status = gBS->OpenProtocol(
      Controller, &gNovatekTouchDeviceProtocolGuid, (VOID **)&NvtDeviceIo,
      This->DriverBindingHandle, Controller, EFI_OPEN_PROTOCOL_BY_DRIVER);

  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = EFI_SUCCESS;
  gBS->CloseProtocol(
      Controller, &gNovatekTouchDeviceProtocolGuid, This->DriverBindingHandle,
      Controller);

  return Status;
}

EFI_STATUS
EFIAPI
NvtSetSlaveAddress(NVT_INTERNAL_DATA *Instance, UINT32 Address)
{
  if (Instance->CurrentSlaveAddress == Address) {
    return EFI_SUCCESS;
  }

  Instance->NvtDevice->SlaveCfg.SlaveAddress = Address;
  Instance->CurrentSlaveAddress              = Address;
  return EFI_SUCCESS;
}

// Standard Read (Write Reg -> Read Data)
// Standard Read (Write Reg -> Read Data)
EFI_STATUS
EFIAPI
NvtI2cRead(
    NVT_INTERNAL_DATA *Instance, UINT8 Reg, IN UINT8 *Data, IN UINT16 ReadBytes)
{
  EFI_STATUS Status;
  UINT32     BytesRead = 0;

  DEBUG(
      (EFI_D_ERROR, "[I2C] RD Reg: 0x%02X (Addr: 0x%02X) Req: %d\n", Reg,
       Instance->NvtDevice->SlaveCfg.SlaveAddress, ReadBytes));

  // Clear Buffer to detect empty reads
  SetMem(Data, ReadBytes, 0xCC); // Fill with 0xCC

  // OffsetLen = 1 (Reg)
  Status = Instance->NvtDevice->I2cQupProtocol->Read(
      Instance->I2cController, &Instance->NvtDevice->SlaveCfg, Reg, 1, Data,
      ReadBytes, &BytesRead, 200000);

  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "[I2C] RD Failed: %r\n", Status));
  }
  else {
    DEBUG(
        (EFI_D_ERROR, "[I2C] RD Success. BytesRead: %d. Data: %02X %02X...\n",
         BytesRead, Data[0], Data[1]));
  }

  return Status;
}

// Standard Write (Write Reg + Data)
EFI_STATUS
EFIAPI
NvtI2cWrite(
    NVT_INTERNAL_DATA *Instance, UINT8 Reg, IN UINT8 *Data,
    IN UINT16 WriteBytes)
{
  EFI_STATUS Status;
  UINT32     BytesWritten = 0;

  DEBUG(
      (EFI_D_ERROR,
       "[I2C] WR Reg: 0x%02X (Addr: 0x%02X) Data: %02X... Len: %d\n", Reg,
       Instance->NvtDevice->SlaveCfg.SlaveAddress, Data[0], WriteBytes));

  // OffsetLen = 1 (Reg)
  Status = Instance->NvtDevice->I2cQupProtocol->Write(
      Instance->I2cController, &Instance->NvtDevice->SlaveCfg, Reg, 1, Data,
      WriteBytes, &BytesWritten, 200000);

  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "[I2C] WR Failed: %r\n", Status));
  }
  else {
    DEBUG((EFI_D_ERROR, "[I2C] WR Success. BytesWritten: %d\n", BytesWritten));
  }

  return Status;
}

// Raw Write (Data Only)
EFI_STATUS
EFIAPI
NvtI2cWriteRaw(
    NVT_INTERNAL_DATA *Instance, IN UINT8 *Data, IN UINT16 WriteBytes)
{
  EFI_STATUS Status;
  UINT32     BytesWritten = 0;

  DEBUG(
      (EFI_D_ERROR, "[I2C] WR_RAW (Addr: 0x%02X) Data: %02X... Len: %d\n",
       Instance->NvtDevice->SlaveCfg.SlaveAddress, Data[0], WriteBytes));

  // OffsetLen = 0
  Status = Instance->NvtDevice->I2cQupProtocol->Write(
      Instance->I2cController, &Instance->NvtDevice->SlaveCfg, 0, 0, Data,
      WriteBytes, &BytesWritten, 200000);

  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "[I2C] WR_RAW Failed: %r\n", Status));
  }
  else {
    DEBUG((
        EFI_D_ERROR, "[I2C] WR_RAW Success. BytesWritten: %d\n", BytesWritten));
  }

  return Status;
}

// Raw Read
EFI_STATUS
EFIAPI
NvtI2cReadRaw(NVT_INTERNAL_DATA *Instance, IN UINT8 *Data, IN UINT16 ReadBytes)
{
  EFI_STATUS Status;
  UINT32     BytesRead = 0;

  DEBUG(
      (EFI_D_ERROR, "[I2C] RD_RAW (Addr: 0x%02X) Req: %d\n",
       Instance->NvtDevice->SlaveCfg.SlaveAddress, ReadBytes));

  // Clear Buffer to detect empty reads
  SetMem(Data, ReadBytes, 0xCC); // Fill with 0xCC

  // OffsetLen = 0
  Status = Instance->NvtDevice->I2cQupProtocol->Read(
      Instance->I2cController, &Instance->NvtDevice->SlaveCfg, 0, 0, Data,
      ReadBytes, &BytesRead, 200000);

  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "[I2C] RD_RAW Failed: %r\n", Status));
  }
  else {
    DEBUG(
        (EFI_D_ERROR,
         "[I2C] RD_RAW Success. BytesRead: %d. Data: %02X %02X %02X %02X...\n",
         BytesRead, Data[0], Data[1], Data[2], Data[3]));
  }

  return Status;
}

// --- Linux Port Start ---

EFI_STATUS NvtBootloaderReset(NVT_INTERNAL_DATA *Instance)
{
  UINT8      Buf[1];
  EFI_STATUS Status;

  // 0x62 <- 69 (Raw)
  NvtSetSlaveAddress(Instance, I2C_HW_Address);
  Buf[0] = 0x69;
  Status = NvtI2cWriteRaw(Instance, Buf, 1);
  gBS->Stall(35000); // 35ms

  return Status;
}

EFI_STATUS NvtSwResetIdle(NVT_INTERNAL_DATA *Instance)
{
  UINT8      Buf[1];
  EFI_STATUS Status;

  // 0x62 <- A5 (Raw)
  NvtSetSlaveAddress(Instance, I2C_HW_Address);
  Buf[0] = 0xA5;
  Status = NvtI2cWriteRaw(Instance, Buf, 1);
  gBS->Stall(20000);

  return Status;
}

VOID NvtStopCrcReboot(NVT_INTERNAL_DATA *Instance)
{
  UINT8 Buf[4];
  UINT8 CheckBuf[2];

  DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: Stopping CRC Reboot Loop...\n"));

  NvtSwResetIdle(Instance);
  NvtSwResetIdle(Instance);

  // 0x01 <- FF 03 F1 (Raw)
  NvtSetSlaveAddress(Instance, I2C_FW_Address);
  Buf[0] = 0xFF;
  Buf[1] = 0x03;
  Buf[2] = 0xF1;
  NvtI2cWriteRaw(Instance, Buf, 3);

  // 0x01 <- 35 A5 (Raw)
  NvtSetSlaveAddress(Instance, I2C_FW_Address);
  Buf[0] = 0x35;
  Buf[1] = 0xA5;
  NvtI2cWriteRaw(Instance, Buf, 2);

  // 0x01 <- FF 03 F1 (Raw)
  NvtSetSlaveAddress(Instance, I2C_FW_Address);
  Buf[0] = 0xFF;
  Buf[1] = 0x03;
  Buf[2] = 0xF1;
  NvtI2cWriteRaw(Instance, Buf, 3);

  // 0x01 <- 35 (Raw) -> Read
  NvtSetSlaveAddress(Instance, I2C_FW_Address);
  Buf[0] = 0x35;
  NvtI2cWriteRaw(Instance, Buf, 1);
  NvtI2cReadRaw(Instance, CheckBuf, 1);
}

// Unlock / Init Flash Block
// Writes 00 00 01 to 0x62 and polls for 0xAA
EFI_STATUS NvtInitBootLoader(NVT_INTERNAL_DATA *Instance)
{
  EFI_STATUS Status;
  UINT8      Buf[3];
  UINT32     Retry;

  DEBUG(
      (EFI_D_ERROR, "NovatekNvtTsDxe: Initializing BootLoader (Unlock)...\n"));

  NvtSwResetIdle(Instance);

  // Write 00 00 01 to 0x62 (Raw)
  NvtSetSlaveAddress(Instance, I2C_HW_Address);
  Buf[0] = 0x00;
  Buf[1] = 0x00; // Offset? No, command payload.
  Buf[2] = 0x01; // FW Addr
  Status = NvtI2cWriteRaw(Instance, Buf, 3);

  if (EFI_ERROR(Status)) {
    DEBUG(
        (EFI_D_ERROR, "NovatekNvtTsDxe: InitBootLoader Write Failed: %r\n",
         Status));
    return Status;
  }

  // Poll for 0xAA
  for (Retry = 0; Retry < 20; Retry++) {
    gBS->Stall(1000); // 1ms

    // Read 2 bytes from 0x62 (Raw)
    // Linux: CTP_I2C_READ(HW, buf, 2)
    Status = NvtI2cReadRaw(Instance, Buf, 2);

    if (!EFI_ERROR(Status)) {
      if (Buf[1] == 0xAA) {
        DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: BootLoader Unlocked (AA).\n"));
        gBS->Stall(20000); // 20ms
        return EFI_SUCCESS;
      }
    }
  }

  DEBUG(
      (EFI_D_ERROR,
       "NovatekNvtTsDxe: BootLoader Unlock Timeout/Fail. Status: %02X\n",
       Buf[1]));
  // Don't fail the driver for this, as we might already be running
  return EFI_SUCCESS;
}
// --- Linux Port End ---

EFI_STATUS
EFIAPI
NvtCheckChipVerTrim(NVT_INTERNAL_DATA *Instance)
{
  EFI_STATUS Status;
  UINT8      Buf[8];
  UINT32     Freqs[] = {100, 400, 100000, 400000};
  UINT32     Addrs[] = {0x62, 0xC4};
  UINT32     f, a;

  DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: STARTING I2C SHOTGUN PROBE...\n"));

  for (f = 0; f < 4; f++) {
    for (a = 0; a < 2; a++) {
      DEBUG(
          (EFI_D_ERROR, "--- PROBE: Freq=%d, Addr=0x%02X ---\n", Freqs[f],
           Addrs[a]));

      // Apply Config
      Instance->NvtDevice->SlaveCfg.BusFrequency = Freqs[f];
      Instance->NvtDevice->SlaveCfg.SlaveAddress = Addrs[a];

      // Try Reset (Raw 0x69)
      Buf[0] = 0x69;
      NvtI2cWriteRaw(Instance, Buf, 1);
      gBS->Stall(35000);

      // Try Unlock (Raw 00 00 01)
      Buf[0] = 0x00;
      Buf[1] = 0x00;
      Buf[2] = 0x01;
      Status = NvtI2cWriteRaw(Instance, Buf, 3);

      // Try Read (Expect 0xAA)
      SetMem(Buf, 8, 0xCC);
      Status = NvtI2cReadRaw(Instance, Buf, 2);

      if (!EFI_ERROR(Status) && Buf[1] != 0xCC) {
        DEBUG(
            (EFI_D_ERROR,
             "!!! MATCH FOUND !!! Freq=%d, Addr=0x%02X, Data=0x%02X\n",
             Freqs[f], Addrs[a], Buf[1]));
        if (Buf[1] == 0xAA) {
          DEBUG((EFI_D_ERROR, "!!! JACKPOT (0xAA) FOUND !!!\n"));
          // Keep this config!
          return EFI_SUCCESS;
        }
      }
    }
  }

  DEBUG(
      (EFI_D_ERROR, "NovatekNvtTsDxe: PROBE FINISHED. No perfect match. "
                    "Reverting to Defaults (400, 0x62).\n"));

  // Revert to default for Fallback
  Instance->NvtDevice->SlaveCfg.BusFrequency = 400;
  Instance->NvtDevice->SlaveCfg.SlaveAddress = I2C_HW_Address;

  // Force Success
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
NvtGetFwInfo(NVT_INTERNAL_DATA *Instance)
{
  EFI_STATUS Status;
  UINT8      Buf[17];

  // Try to read FW info
  NvtSetSlaveAddress(Instance, I2C_FW_Address);

  // Linux:buf[0] = EVENT_MAP_FWINFO (0x78); READ(client, 0x01, buf, 17)
  // This implies we Write 0x78 then Read 17.
  Buf[0] = EVENT_MAP_FWINFO;
  Status = NvtI2cWriteRaw(Instance, Buf, 1);
  if (!EFI_ERROR(Status)) {
    Status = NvtI2cReadRaw(Instance, Buf, 17);
  }

  // Fallback Logic
  if (EFI_ERROR(Status) || (Buf[1] + Buf[2] != 0xFF)) {
    DEBUG(
        (EFI_D_ERROR,
         "NovatekNvtTsDxe: FW Info Invalid/Failed. Using Defaults.\n"));
    Instance->IdInfo.FwVer        = 0;
    Instance->IdInfo.XNum         = 18;
    Instance->IdInfo.YNum         = 32;
    Instance->IdInfo.AbsXMax      = 1080;
    Instance->IdInfo.AbsYMax      = 2340;
    Instance->IdInfo.MaxButtonNum = 0;
  }
  else {
    // Success
    Instance->IdInfo.FwVer        = Buf[1];
    Instance->IdInfo.XNum         = Buf[3];
    Instance->IdInfo.YNum         = Buf[4];
    Instance->IdInfo.AbsXMax      = (UINT16)((Buf[5] << 8) | Buf[6]);
    Instance->IdInfo.AbsYMax      = (UINT16)((Buf[7] << 8) | Buf[8]);
    Instance->IdInfo.MaxButtonNum = Buf[11];
  }

  DEBUG(
      (EFI_D_ERROR,
       "NovatekNvtTsDxe: FW Ver: 0x%02X, X: %d, Y: %d, MaxX: %d, MaxY: %d\n",
       Instance->IdInfo.FwVer, Instance->IdInfo.XNum, Instance->IdInfo.YNum,
       Instance->IdInfo.AbsXMax, Instance->IdInfo.AbsYMax));

  if (Instance->IdInfo.AbsXMax > 0 && Instance->IdInfo.AbsYMax > 0) {
    Instance->AbsPointerMode.AbsoluteMaxX = Instance->IdInfo.AbsXMax;
    Instance->AbsPointerMode.AbsoluteMaxY = Instance->IdInfo.AbsYMax;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingStart(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath)
{
  EFI_TPL             OldTpl;
  EFI_STATUS          Status;
  I2C_STATUS          I2CStatus;
  NOVATEK_I2C_DEVICE *NvtDeviceIo;
  NVT_INTERNAL_DATA  *Instance;
  BOOLEAN             bI2COpened = FALSE;
  EFI_CLOCK_PROTOCOL *ClockProtocol;

  OldTpl = gBS->RaiseTPL(TPL_CALLBACK);

  // Enable Clocks Manually
  Status = gBS->LocateProtocol(
      &gEfiClockProtocolGuid, NULL, (VOID **)&ClockProtocol);
  if (!EFI_ERROR(Status)) {
    UINTN ClockId;
    Status = ClockProtocol->GetClockID(
        ClockProtocol, "gcc_qupv3_wrap_0_m_ahb_clk", &ClockId);
    if (!EFI_ERROR(Status)) {
      ClockProtocol->EnableClock(ClockProtocol, ClockId);
    }

    Status = ClockProtocol->GetClockID(
        ClockProtocol, "gcc_qupv3_wrap_0_s_ahb_clk", &ClockId);
    if (!EFI_ERROR(Status)) {
      ClockProtocol->EnableClock(ClockProtocol, ClockId);
    }

    Status = ClockProtocol->GetClockID(
        ClockProtocol, "gcc_qupv3_wrap0_s1_clk", &ClockId);
    if (!EFI_ERROR(Status)) {
      UINT32 ResultFreq = 0;
      ClockProtocol->EnableClock(ClockProtocol, ClockId);
      Status = ClockProtocol->SetClockFreqHz(
          ClockProtocol, ClockId, 19200000, EFI_CLOCK_FREQUENCY_HZ_CLOSEST,
          &ResultFreq);
      DEBUG(
          (EFI_D_ERROR, "NovatekNvtTsDxe: Set S1 Freq to 19.2MHz, Result: %d\n",
           ResultFreq));
    }
  }

  Status = gBS->OpenProtocol(
      Controller, &gNovatekTouchDeviceProtocolGuid, (VOID **)&NvtDeviceIo,
      This->DriverBindingHandle, Controller, EFI_OPEN_PROTOCOL_BY_DRIVER);
  if (EFI_ERROR(Status)) {
    goto exit;
  }

  Instance = AllocateCopyPool(sizeof(NVT_INTERNAL_DATA), &mNvtInstanceTemplate);
  ASSERT(Instance != NULL);
  ASSERT(NvtDeviceIo != NULL);

  Instance->NvtDevice                        = NvtDeviceIo;
  Instance->NvtDevice->SlaveCfg.BusFrequency = 400;
  Instance->AbsPointerMode.AbsoluteMaxX      = 1080;
  Instance->AbsPointerMode.AbsoluteMaxY      = 2340;
  Instance->AbsPointerProtocol.Mode          = &Instance->AbsPointerMode;

  Instance->CurrentSlaveAddress = NvtDeviceIo->SlaveCfg.SlaveAddress;

  I2CStatus = NvtDeviceIo->I2cQupProtocol->Open(
      Instance->NvtDevice->ControllerI2cDevice, &Instance->I2cController);

  if (I2C_ERROR(I2CStatus)) {
    DEBUG(
        (EFI_D_ERROR, "NovatekNvtTsDxe: Failed to open I2C%d: %d\n",
         Instance->NvtDevice->ControllerI2cDevice, I2CStatus));
    Status = EFI_DEVICE_ERROR;
    goto exit;
  }

  bI2COpened = TRUE;

  gNvtDeviceIo    = NvtDeviceIo;
  gNvtI2CInstance = Instance;

  // Manual GPIO Configuration for I2C 1 (SE1) -> GPIO 4/5
  EFI_QCOM_TLMM_PROTOCOL *TlmmProtocol;
  Status =
      gBS->LocateProtocol(&gQcomTlmmProtocolGuid, NULL, (VOID **)&TlmmProtocol);
  if (!EFI_ERROR(Status)) {
    UINT32 Config4 = EFI_GPIO_CFG(4, 3, GPIO_INPUT, GPIO_PULL_UP, GPIO_8MA);
    TlmmProtocol->ConfigGpio(Config4, TLMM_GPIO_ENABLE);
    UINT32 Config5 = EFI_GPIO_CFG(5, 3, GPIO_INPUT, GPIO_PULL_UP, GPIO_8MA);
    TlmmProtocol->ConfigGpio(Config5, TLMM_GPIO_ENABLE);
    DEBUG(
        (EFI_D_ERROR,
         "NovatekNvtTsDxe: Forced GPIO 4/5 to I2C Mode (Func 3, PU)\n"));
  }

  // Restore correct address
  Instance->NvtDevice->SlaveCfg.SlaveAddress = Instance->CurrentSlaveAddress;

  Status = NvtPowerUpController(Instance);
  if (EFI_ERROR(Status)) {
    DEBUG(
        (EFI_D_ERROR, "NovatekNvtTsDxe: Failed to power on controller: %r\n",
         Status));
    goto exit;
  }

  Instance->Buf = AllocateZeroPool(POINT_DATA_LEN + 1);
  if (Instance->Buf == NULL) {
    Status = EFI_OUT_OF_RESOURCES;
    goto exit;
  }

  // Check Chip Ver - Ignored Error (Fallback)
  NvtCheckChipVerTrim(Instance);

  // UNLOCK / INIT BOOTLOADER
  // Needed for "Locked" chips
  NvtInitBootLoader(Instance);

  // Get FW Info - Fallback enabled
  NvtGetFwInfo(Instance);

  Instance->Initialized = TRUE;

  Status = gBS->CreateEvent(
      EVT_NOTIFY_WAIT, TPL_NOTIFY, AbsPWaitForInput, Instance,
      &Instance->AbsPointerProtocol.WaitForInput);
  ASSERT_EFI_ERROR(Status);

  Status = AbsStartPolling(Instance);
  ASSERT_EFI_ERROR(Status);

  Status = gBS->InstallProtocolInterface(
      &Controller, &gEfiAbsolutePointerProtocolGuid, EFI_NATIVE_INTERFACE,
      &Instance->AbsPointerProtocol);

  if (EFI_ERROR(Status)) {
    DEBUG((
        EFI_D_ERROR,
        "NovatekNvtTsDxe: Failed to install protocol interface: %r\n", Status));
  }

  Instance->ControllerNameTable = NULL;
  AddUnicodeString2(
      "eng", gNvtDriverComponentName.SupportedLanguages,
      &Instance->ControllerNameTable,
      L"Novatek NVT Touchscreen Absolute Pointer", TRUE);
  AddUnicodeString2(
      "en", gNvtDriverComponentName.SupportedLanguages,
      &Instance->ControllerNameTable,
      L"Novatek NVT Touchscreen Absolute Pointer", FALSE);

exit:
  if (bI2COpened == TRUE && Status == EFI_DEVICE_ERROR) {
    NvtDeviceIo->I2cQupProtocol->Close(Instance->I2cController);
    DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: Error: Closing i2c instance\n"));
  }
  gBS->RestoreTPL(OldTpl);
  return Status;
}

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingStop(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN UINTN NumberOfChildren, IN EFI_HANDLE *ChildHandleBuffer)
{
  EFI_STATUS                     Status;
  EFI_ABSOLUTE_POINTER_PROTOCOL *AbsolutePointerProtocol;
  NVT_INTERNAL_DATA             *Instance;
  NOVATEK_I2C_DEVICE            *NvtDeviceIo;

  Status = gBS->OpenProtocol(
      Controller, &gEfiAbsolutePointerProtocolGuid,
      (VOID **)&AbsolutePointerProtocol, This->DriverBindingHandle, Controller,
      EFI_OPEN_PROTOCOL_GET_PROTOCOL);

  if (EFI_ERROR(Status)) {
    return EFI_UNSUPPORTED;
  }

  Instance = NVT_TCH_INSTANCE_FROM_ABSTCH_THIS(AbsolutePointerProtocol);

  Status = gBS->UninstallProtocolInterface(
      Controller, &gEfiAbsolutePointerProtocolGuid,
      &Instance->AbsPointerProtocol);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = gBS->CloseEvent(Instance->PollingTimerEvent);
  Status = gBS->CloseEvent(Instance->TouchWorkerEvent);
  Status = gBS->CloseEvent(Instance->AbsPointerProtocol.WaitForInput);

  Status = gBS->OpenProtocol(
      Controller, &gNovatekTouchDeviceProtocolGuid, (VOID **)&NvtDeviceIo,
      This->DriverBindingHandle, Controller, EFI_OPEN_PROTOCOL_BY_DRIVER);

  NvtDeviceIo->I2cQupProtocol->Close(Instance->I2cController);

  if (Instance->Buf != NULL) {
    FreePool(Instance->Buf);
  }

  DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: Closing i2c instance\n"));

  return EFI_SUCCESS;
}

EFI_STATUS AbsPReset(
    IN EFI_ABSOLUTE_POINTER_PROTOCOL *This, IN BOOLEAN ExtendedVerification)
{
  NVT_INTERNAL_DATA *Instance;

  Instance               = NVT_TCH_INSTANCE_FROM_ABSTCH_THIS(This);
  Instance->LastX        = 0;
  Instance->LastY        = 0;
  Instance->StateChanged = FALSE;

  return EFI_SUCCESS;
}

EFI_STATUS AbsStartPolling(IN NVT_INTERNAL_DATA *Instance)
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = gBS->CreateEvent(
      EVT_NOTIFY_SIGNAL, TPL_CALLBACK, TouchWorkerCallback, Instance,
      &Instance->TouchWorkerEvent);
  ASSERT_EFI_ERROR(Status);

  Status = gBS->CreateEvent(
      EVT_NOTIFY_SIGNAL | EVT_TIMER, TPL_CALLBACK, SyncPollCallback, Instance,
      &Instance->PollingTimerEvent);
  ASSERT_EFI_ERROR(Status);

  Status = gBS->SetTimer(
      Instance->PollingTimerEvent, TimerPeriodic, TIMER_INTERVAL_TOUCH_POLL);
  ASSERT_EFI_ERROR(Status);

  return Status;
}

EFI_STATUS AbsPGetState(
    IN EFI_ABSOLUTE_POINTER_PROTOCOL  *This,
    IN OUT EFI_ABSOLUTE_POINTER_STATE *State)
{
  EFI_STATUS         Status = EFI_SUCCESS;
  NVT_INTERNAL_DATA *Instance;

  if (This == NULL || State == NULL) {
    Status = EFI_INVALID_PARAMETER;
    goto exit;
  }

  Instance = NVT_TCH_INSTANCE_FROM_ABSTCH_THIS(This);
  if (!Instance->StateChanged) {
    Status = EFI_NOT_READY;
    goto exit;
  }

  State->CurrentX        = Instance->LastX;
  State->CurrentY        = Instance->LastY;
  State->CurrentZ        = 0;
  State->ActiveButtons   = 1;
  Instance->StateChanged = FALSE;

exit:
  return Status;
}

VOID EFIAPI AbsPWaitForInput(IN EFI_EVENT Event, IN VOID *Context)
{
  NVT_INTERNAL_DATA *Instance = (NVT_INTERNAL_DATA *)Context;
  EFI_TPL            OldTpl;

  OldTpl = gBS->RaiseTPL(TPL_NOTIFY);

  SyncPollCallback(NULL, Instance);

  if (Instance->StateChanged) {
    gBS->SignalEvent(Event);
  }

  gBS->RestoreTPL(OldTpl);
}

EFI_STATUS
EFIAPI
NvtPowerUpController(NVT_INTERNAL_DATA *Instance)
{
  UINT32     Config;
  UINT32     ResetLine;
  EFI_STATUS Status;

  if (Instance == NULL || Instance->NvtDevice == NULL ||
      Instance->NvtDevice->GpioTlmmProtocol == NULL) {
    Status = EFI_INVALID_PARAMETER;
    goto exit;
  }

  ResetLine = Instance->NvtDevice->ControllerResetPin;
  if (ResetLine <= 0) {
    DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: Invalid GPIO configuration\n"));
    Status = EFI_INVALID_PARAMETER;
    goto exit;
  }

  Config = EFI_GPIO_CFG(ResetLine, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_8MA);
  Status = Instance->NvtDevice->GpioTlmmProtocol->ConfigGpio(
      Config, TLMM_GPIO_ENABLE);

  Instance->NvtDevice->GpioTlmmProtocol->GpioOut(Config, GPIO_LOW_VALUE);
  gBS->Stall(20000);

  Instance->NvtDevice->GpioTlmmProtocol->GpioOut(Config, GPIO_HIGH_VALUE);
  gBS->Stall(200000);

  DEBUG((EFI_D_ERROR, "NovatekNvtTsDxe: Touch controller powered on \n"));
  Status = EFI_SUCCESS;

exit:
  return Status;
}

EFI_STATUS
EFIAPI
NvtGetTouchData(NVT_INTERNAL_DATA *Instance, IN PTOUCH_DATA DataBuffer)
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINT32     i, position;
  UINT32     input_x, input_y, input_w;
  UINT8      input_id;
  UINT8     *point_data;
  UINT8      buf[1];

  if (Instance == NULL) {
    Status = EFI_INVALID_PARAMETER;
    goto exit;
  }

  // Ensure FW Address 0x01 for Write
  Instance->NvtDevice->SlaveCfg.SlaveAddress = I2C_FW_Address;

  buf[0] = 0x00;
  NvtI2cWriteRaw(Instance, buf, 1);

  // Ensure FW Address 0x01 again for Read (Paranoid)
  Instance->NvtDevice->SlaveCfg.SlaveAddress = I2C_FW_Address;

  Status = NvtI2cReadRaw(Instance, Instance->Buf, POINT_DATA_LEN + 1);

  if (EFI_ERROR(Status)) {
    goto exit;
  }

  point_data = Instance->Buf;

  if (point_data[0] != 0 || point_data[1] != 0) {
    DEBUG(
        (EFI_D_ERROR,
         "NovatekNvtTsDxe: Data: %02X %02X %02X %02X %02X %02X %02X %02X\n",
         point_data[0], point_data[1], point_data[2], point_data[3],
         point_data[4], point_data[5], point_data[6], point_data[7]));
  }

  DataBuffer->TouchStatus = 0;
  DataBuffer->TouchX      = 0;
  DataBuffer->TouchY      = 0;

  for (i = 0; i < NVT_TS_MAX_TOUCHES; i++) {
    position = 1 + 6 * i;

    if (position + 5 > POINT_DATA_LEN)
      break;

    input_id = (UINT8)(point_data[position + 0] >> 3);

    if ((input_id == 0) || (input_id > NVT_TS_MAX_TOUCHES))
      continue;

    if (((point_data[position] & 0x07) == 0x01) ||
        ((point_data[position] & 0x07) == 0x02)) {

      input_x = (UINT32)(point_data[position + 1] << 4) +
                (UINT32)(point_data[position + 3] >> 4);
      input_y = (UINT32)(point_data[position + 2] << 4) +
                (UINT32)(point_data[position + 3] & 0x0F);
      input_w = (UINT32)(point_data[position + 4]);

      // Filter invalid 0 coordinates
      if (input_x == 0 && input_y == 0)
        continue;

      DataBuffer->TouchX      = (UINT16)input_x;
      DataBuffer->TouchY      = (UINT16)input_y;
      DataBuffer->TouchStatus = 1;

      break;
    }
  }

exit:
  return Status;
}

VOID EFIAPI TouchWorkerCallback(IN EFI_EVENT Event, IN VOID *Context)
{
  EFI_STATUS         Status;
  NVT_INTERNAL_DATA *Instance = (NVT_INTERNAL_DATA *)Context;
  TOUCH_DATA         TouchPointerData;

  ASSERT(Instance != NULL);

  UINT32 Val    = 0;
  UINT32 Config = EFI_GPIO_CFG(
      Instance->NvtDevice->ControllerInterruptPin, 0, GPIO_INPUT, GPIO_NO_PULL,
      GPIO_2MA);

  Instance->NvtDevice->GpioTlmmProtocol->ConfigGpio(Config, TLMM_GPIO_ENABLE);
  Instance->NvtDevice->GpioTlmmProtocol->GpioIn(Config, &Val);

  if (Val == 1) {
    // IRQ High / Idle
    return;
  }

  if (Instance->Initialized == FALSE) {
    return;
  }

  Status = NvtGetTouchData(Instance, &TouchPointerData);
  if (!EFI_ERROR(Status)) {
    Instance->LastX        = TouchPointerData.TouchX;
    Instance->LastY        = TouchPointerData.TouchY;
    Instance->StateChanged = TRUE;
  }
}

VOID EFIAPI SyncPollCallback(IN EFI_EVENT Event, IN VOID *Context)
{
  NVT_INTERNAL_DATA *Instance = (NVT_INTERNAL_DATA *)Context;
  gBS->SignalEvent(Instance->TouchWorkerEvent);
}
