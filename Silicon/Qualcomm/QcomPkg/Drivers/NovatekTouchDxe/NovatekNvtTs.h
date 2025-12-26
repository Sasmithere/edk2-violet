#ifndef _NOVATEK_NVT_TS_H_
#define _NOVATEK_NVT_TS_H_

#include <Uefi.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

#include <Protocol/AbsolutePointer.h>
#include <Protocol/EFII2C.h>
#include <Protocol/EFITlmm.h>

#define NVT_TS_TOUCH_START 0x00
#define NVT_TS_TOUCH_SIZE 6

// I2C Addresses
#define I2C_HW_Address 0x62
#define I2C_FW_Address 0x01

// Registers and Commands
#define NVT_TS_PARAMETERS_START 0x78
#define EVENT_MAP_FWINFO 0x78
#define EVENT_MAP_PROJECTID 0x9A

/* These are offsets from NVT_TS_PARAMETERS_START */
#define NVT_TS_PARAMS_WIDTH 0x04
#define NVT_TS_PARAMS_HEIGHT 0x06
#define NVT_TS_PARAMS_MAX_TOUCH 0x09
#define NVT_TS_PARAMS_MAX_BUTTONS 0x0a
#define NVT_TS_PARAMS_IRQ_TYPE 0x0b
#define NVT_TS_PARAMS_WAKE_TYPE 0x0c
#define NVT_TS_PARAMS_CHIP_ID 0x0e
#define NVT_TS_PARAMS_SIZE 0x0f

#define NVT_TS_MAX_TOUCHES 10
#define NVT_TS_MAX_SIZE 4096

#define NVT_TS_TOUCH_INVALID 0xff
#define NVT_TS_TOUCH_SLOT_SHIFT 3
#define NVT_TS_TOUCH_TYPE_MASK 0x07 // GENMASK(2, 0)
#define NVT_TS_TOUCH_NEW 1
#define NVT_TS_TOUCH_UPDATE 2
#define NVT_TS_TOUCH_RELEASE 3

#define TOUCH_DELAY_TO_COMMUNICATE 200000
#define TOUCH_POWER_RAIL_STABLE_TIME 2000

#define TIMER_INTERVAL_TOUCH_POLL 100000

typedef struct _TOUCH_DATA {
  UINT16 TouchX;
  UINT16 TouchY;
  UINT8  TouchStatus;
} TOUCH_DATA, *PTOUCH_DATA;

// Full Touch Data Structure from Linux driver
#define POINT_DATA_LEN 65
typedef struct _NVT_TOUCH_DATA {
  UINT8 PointData[POINT_DATA_LEN + 1];
} NVT_TOUCH_DATA;

// FW Info Structure
typedef struct _NVT_ID_INFO {
  UINT8  FwVer;
  UINT8  XNum;
  UINT8  YNum;
  UINT16 AbsXMax;
  UINT16 AbsYMax;
  UINT8  MaxButtonNum;
} NVT_ID_INFO;

// Novatek device

extern EFI_GUID gNovatekTouchDeviceProtocolGuid;

typedef struct _NOVATEK_I2C_DEVICE {
  UINT32                  Signature;
  UINT32                  XMax;
  UINT32                  YMax;
  UINT32                  XMin;
  UINT32                  YMin;
  BOOLEAN                 XInverted;
  BOOLEAN                 YInverted;
  UINT32                  ControllerResetPin;
  UINT32                  ControllerInterruptPin;
  UINT32                  ControllerVddPin;
  UINT32                  ControllerVddIoPin;
  BOOLEAN                 ControllerVddCtlActiveLow;
  UINT32                  ControllerI2cDevice;
  EFI_QCOM_TLMM_PROTOCOL *GpioTlmmProtocol;
  EFI_QCOM_I2C_PROTOCOL  *I2cQupProtocol;
  I2C_SLAVE_CONFIG        SlaveCfg;
} NOVATEK_I2C_DEVICE;

#define NVT_DEV_INSTANCE_SIGNATURE SIGNATURE_32('n', 'v', 't', 'd')

// Novatek driver internals

typedef struct _NVT_INTERNAL_DATA {
  UINT32                        Signature;
  UINT16                        LastX;
  UINT16                        LastY;
  EFI_ABSOLUTE_POINTER_PROTOCOL AbsPointerProtocol;
  EFI_ABSOLUTE_POINTER_MODE     AbsPointerMode;
  EFI_EVENT                     PollingTimerEvent;
  EFI_EVENT                     TouchWorkerEvent;
  BOOLEAN                       Initialized;
  UINT32                        TouchDataAddress;
  VOID                         *I2cController;
  BOOLEAN                       StateChanged;
  NOVATEK_I2C_DEVICE           *NvtDevice;
  EFI_UNICODE_STRING_TABLE     *ControllerNameTable;
  UINT8                        *Buf;
  UINT32                        CurrentSlaveAddress;
  NVT_ID_INFO                   IdInfo;
} NVT_INTERNAL_DATA;

#define NVT_TCH_INSTANCE_SIGNATURE SIGNATURE_32('n', 'v', 't', 's')
#define NVT_TCH_INSTANCE_FROM_ABSTCH_THIS(a)                                   \
  CR(a, NVT_INTERNAL_DATA, AbsPointerProtocol, NVT_TCH_INSTANCE_SIGNATURE)

// Below is the driver binding section

extern EFI_DRIVER_BINDING_PROTOCOL  gNvtDriverBinding;
extern EFI_COMPONENT_NAME_PROTOCOL  gNvtDriverComponentName;
extern EFI_COMPONENT_NAME2_PROTOCOL gNvtDriverComponentName2;

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingSupported(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath);

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingStart(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath);

EFI_STATUS
EFIAPI
NvtAbsolutePointerDriverBindingStop(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE Controller,
    IN UINTN NumberOfChildren, IN EFI_HANDLE *ChildHandleBuffer);

EFI_STATUS
EFIAPI
NvtDriverComponentNameGetDriverName(
    IN EFI_COMPONENT_NAME_PROTOCOL *This, IN CHAR8 *Language,
    OUT CHAR16 **DriverName);

EFI_STATUS
EFIAPI
NvtDriverComponentNameGetControllerName(
    IN EFI_COMPONENT_NAME_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN EFI_HANDLE ChildHandle OPTIONAL, IN CHAR8 *Language,
    OUT CHAR16 **ControllerName);

// Below is Novatek driver code
EFI_STATUS
EFIAPI
NvtI2cRead(
    NVT_INTERNAL_DATA *Instance, UINT8 Reg, IN UINT8 *Data,
    IN UINT16 ReadBytes);

EFI_STATUS
EFIAPI
NvtI2cWrite(
    NVT_INTERNAL_DATA *Instance, UINT8 Reg, IN UINT8 *Data,
    IN UINT16 WriteBytes);

EFI_STATUS
EFIAPI
NvtSetSlaveAddress(NVT_INTERNAL_DATA *Instance, UINT32 Address);

EFI_STATUS AbsPReset(
    IN EFI_ABSOLUTE_POINTER_PROTOCOL *This, IN BOOLEAN ExtendedVerification);

EFI_STATUS AbsPGetState(
    IN EFI_ABSOLUTE_POINTER_PROTOCOL  *This,
    IN OUT EFI_ABSOLUTE_POINTER_STATE *State);

EFI_STATUS AbsStartPolling(IN NVT_INTERNAL_DATA *Instance);

VOID EFIAPI AbsPWaitForInput(IN EFI_EVENT Event, IN VOID *Context);

VOID EFIAPI SyncPollCallback(IN EFI_EVENT Event, IN VOID *Context);

EFI_STATUS EFIAPI NvtPowerUpController(NVT_INTERNAL_DATA *Instance);

EFI_STATUS
EFIAPI
NvtGetTouchData(NVT_INTERNAL_DATA *Instance, IN PTOUCH_DATA DataBuffer);

#endif
