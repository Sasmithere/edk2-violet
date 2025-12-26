/** @file
  Qualcomm USB Serial DXE (CDC ACM) Implementation

  Copyright (c) 2024, Renegade Project. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "QcomUsbSerialDxe.h"

//
// Global Variables for Descriptors
//

// Device Descriptor
STATIC EFI_USB_DEVICE_DESCRIPTOR mDeviceDescriptor = {
    sizeof(EFI_USB_DEVICE_DESCRIPTOR), // Length
    USB_DESC_TYPE_DEVICE,              // DescriptorType
    0x0200,                            // BcdUSB
    0x02,                              // DeviceClass (CDC)
    0x00,                              // DeviceSubClass
    0x00,                              // DeviceProtocol
    64,                                // MaxPacketSize0
    USB_VENDOR_ID,                     // IdVendor
    USB_PRODUCT_ID,                    // IdProduct
    0x0100,                            // BcdDevice
    1,                                 // StrManufacturer
    2,                                 // StrProduct
    3,                                 // StrSerialNumber
    1                                  // NumConfigurations
};

// Device Qualifier Descriptor
STATIC EFI_USB_DEVICE_QUALIFIER_DESCRIPTOR mDeviceQualifierDescriptor = {
    sizeof(EFI_USB_DEVICE_QUALIFIER_DESCRIPTOR),
    USB_DESC_TYPE_DEVICE_QUALIFIER,
    0x0200,
    0x02,
    0x00,
    0x00,
    64,
    1,
    0};

// Configuration Descriptor (Full Speed / High Speed will be constructed
// dynamically or selected) For simplicity, we define the structure layout
// physically here
#pragma pack(1)
typedef struct {
  EFI_USB_CONFIG_DESCRIPTOR Config;

  // Interface 0: Communication Class (Control)
  EFI_USB_INTERFACE_DESCRIPTOR Interface0;
  USB_CDC_HEADER_DESC          CdcHeader;
  USB_CDC_CALL_MAN_DESC        CdcCallMan;
  USB_CDC_ACM_DESC             CdcAcm;
  USB_CDC_UNION_DESC           CdcUnion;
  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointInterrupt;

  // Interface 1: Data Class
  EFI_USB_INTERFACE_DESCRIPTOR Interface1;
  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointIn;
  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointOut;

} TOTAL_CONFIG_DESCRIPTOR;
#pragma pack()

STATIC TOTAL_CONFIG_DESCRIPTOR mConfigDescriptor = {
    // Config
    {
        sizeof(EFI_USB_CONFIG_DESCRIPTOR), USB_DESC_TYPE_CONFIG,
        sizeof(TOTAL_CONFIG_DESCRIPTOR),
        2,    // NumInterfaces
        1,    // ConfigurationValue
        0,    // ConfigurationStr
        0xC0, // Attributes (Self-powered)
        50    // MaxPower (100mA)
    },
    // Interface 0 (Control)
    {
        sizeof(EFI_USB_INTERFACE_DESCRIPTOR), USB_DESC_TYPE_INTERFACE,
        0,    // InterfaceNumber
        0,    // AlternateSetting
        1,    // NumEndpoints (Interrupt IN)
        0x02, // InterfaceClass (Comm)
        0x02, // InterfaceSubClass (ACM)
        0x01, // InterfaceProtocol (AT Common)
        0     // InterfaceStr
    },
    // CDC Header
    {
        {sizeof(USB_CDC_HEADER_DESC), 0x24, 0x00},
        0x0110 // bcdCDC 1.10
    },
    // CDC Call Management
    {
        {sizeof(USB_CDC_CALL_MAN_DESC), 0x24, 0x01},
        0x00, // bmCapabilities (No Call Management)
        1     // bDataInterface
    },
    // CDC ACM
    {
        {sizeof(USB_CDC_ACM_DESC), 0x24, 0x02},
        0x02 // bmCapabilities (Set_Line_Coding, Set_Control_Line_State,
             // Get_Line_Coding)
    },
    // CDC Union
    {
        {sizeof(USB_CDC_UNION_DESC), 0x24, 0x06},
        0, // Master (Control)
        1  // Slave (Data)
    },
    // Endpoint Interrupt
    {
        sizeof(EFI_USB_ENDPOINT_DESCRIPTOR), USB_DESC_TYPE_ENDPOINT,
        0x83, // EndpointAddress (IN, 3) - Will be fixed up
        0x03, // Attributes (Interrupt)
        10,   // MaxPacketSize
        9     // Interval
    },
    // Interface 1 (Data)
    {
        sizeof(EFI_USB_INTERFACE_DESCRIPTOR), USB_DESC_TYPE_INTERFACE,
        1,    // InterfaceNumber
        0,    // AlternateSetting
        2,    // NumEndpoints (Bulk IN, Bulk OUT)
        0x0A, // InterfaceClass (Data)
        0x00, // InterfaceSubClass
        0x00, // InterfaceProtocol
        0     // InterfaceStr
    },
    // Endpoint IN
    {
        sizeof(EFI_USB_ENDPOINT_DESCRIPTOR), USB_DESC_TYPE_ENDPOINT,
        0x81, // EndpointAddress (IN, 1) - Will be fixed up
        0x02, // Attributes (Bulk)
        512,  // MaxPacketSize (HS)
        0     // Interval
    },
    // Endpoint OUT
    {
        sizeof(EFI_USB_ENDPOINT_DESCRIPTOR), USB_DESC_TYPE_ENDPOINT,
        0x02, // EndpointAddress (OUT, 2) - Will be fixed up
        0x02, // Attributes (Bulk)
        512,  // MaxPacketSize (HS)
        0     // Interval
    }};

STATIC USB_SERIAL_CONTEXT *mContext = NULL;

//
// SERIAL IO PROTOCOL IMPLEMENTATION
//

EFI_STATUS
EFIAPI
SerialReset(IN EFI_SERIAL_IO_PROTOCOL *This)
{
  return EFI_SUCCESS; // No-op for now
}

EFI_STATUS
EFIAPI
SerialSetAttributes(
    IN EFI_SERIAL_IO_PROTOCOL *This, IN UINT64 BaudRate,
    IN UINT32 ReceiveFifoDepth, IN UINT32 Timeout, IN EFI_PARITY_TYPE Parity,
    IN UINT8 DataBits, IN EFI_STOP_BITS_TYPE StopBits)
{
  // We accept everything but don't strictly enforce it on the USB side yet
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
SerialSetControl(IN EFI_SERIAL_IO_PROTOCOL *This, IN UINT32 Control)
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
SerialGetControl(IN EFI_SERIAL_IO_PROTOCOL *This, OUT UINT32 *Control)
{
  if (Control == NULL)
    return EFI_INVALID_PARAMETER;

  // Fake standard status
  *Control = EFI_SERIAL_DATA_TERMINAL_READY | EFI_SERIAL_REQUEST_TO_SEND |
             EFI_SERIAL_CARRIER_DETECT | EFI_SERIAL_CLEAR_TO_SEND |
             EFI_SERIAL_INPUT_BUFFER_EMPTY;

  if (mContext && mContext->MediaConnected) {
    *Control |= EFI_SERIAL_DATA_SET_READY;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
SerialWrite(
    IN EFI_SERIAL_IO_PROTOCOL *This, IN OUT UINTN *BufferSize, IN VOID *Buffer)
{
  EFI_STATUS          Status;
  USB_SERIAL_CONTEXT *Ctx = mContext; // Simplified single instance
  UINTN               BytesToWrite;

  if (!Ctx || !Ctx->MediaConnected || !Ctx->UsbFnIo) {
    if (BufferSize)
      *BufferSize = 0;
    return EFI_NOT_READY;
  }

  BytesToWrite = *BufferSize;

  // Blocking write for simplicity in early boot
  // In a real robust driver we'd queue

  Status = Ctx->UsbFnIo->Transfer(
      Ctx->UsbFnIo, Ctx->BulkInEndpoint, EfiUsbEndpointDirectionDeviceTx,
      &BytesToWrite, Buffer);

  *BufferSize = BytesToWrite;
  return Status;
}

EFI_STATUS
EFIAPI
SerialRead(
    IN EFI_SERIAL_IO_PROTOCOL *This, IN OUT UINTN *BufferSize, OUT VOID *Buffer)
{
  // Polling read is tricky without a background buffer or interrupt
  // We will attempt a non-blocking read if supported, or just return 0 for now
  // to prevent blocking boot.
  // Implementing full READ support requires a ring buffer filled by Event
  // Handler.

  // For output-only console (debugging), we return 0.
  // TODO: Implement RX
  if (BufferSize)
    *BufferSize = 0;
  return EFI_SUCCESS;
}

STATIC EFI_SERIAL_IO_MODE mSerialIoMode = {
    115200, // ControlMask
    10,     // Timeout
    115200, // BaudRate
    16,     // ReceiveFifoDepth
    1,      // DataBits
    0,      // Parity
    0       // StopBits
};

//
// USB FN IO EVENT HANDLER
//

EFI_STATUS
EFIAPI
UsbFnEventHandler(
    IN EFI_USBFN_IO_PROTOCOL *This, OUT EFI_USBFN_MESSAGE *Message,
    IN OUT UINTN *PayloadSize, OUT EFI_USBFN_MESSAGE_PAYLOAD *Payload)
{
  // Using the blocking EventHandler pattern from the protocol is usually done
  // in a loop by the bus driver. Wait, the protocol usually requires the Class
  // Driver to CALL EventHandler periodically? Or does UsbFnIo call a callback?

  // Checking Protocol/UsbFunctionIo.h:
  // "A class driver must call EFI_USBFN_IO_PROTOCOL.EventHandler() repeatedly"

  // This means WE (the consumer) must poll the hardware driver.
  // For a DXE driver, we should probably set up a Timer Event.
  return EFI_SUCCESS;
}

VOID EFIAPI UsbPollTimerHandler(IN EFI_EVENT Event, IN VOID *Context)
{
  USB_SERIAL_CONTEXT       *Ctx = (USB_SERIAL_CONTEXT *)Context;
  EFI_USBFN_MESSAGE         Message;
  UINTN                     PayloadSize = sizeof(EFI_USBFN_MESSAGE_PAYLOAD);
  EFI_USBFN_MESSAGE_PAYLOAD Payload;
  EFI_STATUS                Status;

  if (!Ctx || !Ctx->UsbFnIo)
    return;

  // Poll for events
  Status = Ctx->UsbFnIo->EventHandler(
      Ctx->UsbFnIo, &Message, &PayloadSize, &Payload);

  if (EFI_ERROR(Status) && Status != EFI_NOT_READY) {
    return;
  }

  switch (Message) {
  case EfiUsbMsgBusEventReset:
    // Handle Reset
    break;
  case EfiUsbMsgBusEventAttach:
    Ctx->MediaConnected = TRUE;
    break;
  case EfiUsbMsgBusEventDetach:
    Ctx->MediaConnected = FALSE;
    break;
  case EfiUsbMsgSetupPacket:
    // Handle CDC Control Requests (Set Line Coding etc)
    // Usually these require a response.
    // For now we just accept default
    break;
  default:
    break;
  }
}

//
// DRIVER BINDING
//

EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingSupported(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL)
{
  EFI_STATUS             Status;
  EFI_USBFN_IO_PROTOCOL *UsbFnIo;

  Status = gBS->OpenProtocol(
      ControllerHandle, &gEfiUsbFunctionIoProtocolGuid, (VOID **)&UsbFnIo,
      This->DriverBindingHandle, ControllerHandle, EFI_OPEN_PROTOCOL_BY_DRIVER);

  if (EFI_ERROR(Status)) {
    return Status;
  }

  gBS->CloseProtocol(
      ControllerHandle, &gEfiUsbFunctionIoProtocolGuid,
      This->DriverBindingHandle, ControllerHandle);

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingStart(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL)
{
  EFI_STATUS              Status;
  EFI_USBFN_IO_PROTOCOL  *UsbFnIo;
  USB_SERIAL_CONTEXT     *Ctx;
  EFI_USB_DEVICE_INFO     DeviceInfo;
  EFI_USB_INTERFACE_INFO  InterfaceInfo0;
  EFI_USB_INTERFACE_INFO  InterfaceInfo1;
  EFI_USB_INTERFACE_INFO *InterfaceTable0[] = {&InterfaceInfo0, NULL};
  EFI_USB_INTERFACE_INFO *InterfaceTable1[] = {&InterfaceInfo1, NULL};
  // Wait, ConfigInfoTable is pointer to pointer...
  // Structure: Device -> Config* -> Interface*
  // This manual construction is painful.
  // Using ConfigureEnableEndpoints simplifies this?

  // Allocation
  Ctx = AllocateZeroPool(sizeof(USB_SERIAL_CONTEXT));
  if (!Ctx)
    return EFI_OUT_OF_RESOURCES;

  mContext                 = Ctx; // Global ref
  Ctx->DriverBindingHandle = This->DriverBindingHandle;

  // Open Protocol
  Status = gBS->OpenProtocol(
      ControllerHandle, &gEfiUsbFunctionIoProtocolGuid, (VOID **)&UsbFnIo,
      This->DriverBindingHandle, ControllerHandle, EFI_OPEN_PROTOCOL_BY_DRIVER);
  if (EFI_ERROR(Status)) {
    FreePool(Ctx);
    return Status;
  }
  Ctx->UsbFnIo = UsbFnIo;

  // Setup Device Info
  // We point to our static descriptors
  DeviceInfo.DeviceDescriptor = &mDeviceDescriptor;

  // Construct Config Info Table
  EFI_USB_CONFIG_INFO ConfigInfo;
  ConfigInfo.ConfigDescriptor = &mConfigDescriptor.Config;

  EFI_USB_INTERFACE_INFO Interface0;
  Interface0.InterfaceDescriptor          = &mConfigDescriptor.Interface0;
  EFI_USB_ENDPOINT_DESCRIPTOR *EpTable0[] = {
      &mConfigDescriptor.EndpointInterrupt, NULL};
  Interface0.EndpointDescriptorTable = EpTable0;

  EFI_USB_INTERFACE_INFO Interface1;
  Interface1.InterfaceDescriptor          = &mConfigDescriptor.Interface1;
  EFI_USB_ENDPOINT_DESCRIPTOR *EpTable1[] = {
      &mConfigDescriptor.EndpointIn, &mConfigDescriptor.EndpointOut, NULL};
  Interface1.EndpointDescriptorTable = EpTable1;

  EFI_USB_INTERFACE_INFO *Interfaces[] = {&Interface0, &Interface1, NULL};
  ConfigInfo.InterfaceInfoTable        = Interfaces;

  EFI_USB_CONFIG_INFO *ConfigTable[] = {&ConfigInfo, NULL};
  DeviceInfo.ConfigInfoTable         = ConfigTable;

  // Configure Endpoints
  Status = UsbFnIo->ConfigureEnableEndpoints(UsbFnIo, &DeviceInfo);
  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "Usb Serial: Configure Endpoints Failed %r\n", Status));
    gBS->CloseProtocol(
        ControllerHandle, &gEfiUsbFunctionIoProtocolGuid,
        This->DriverBindingHandle, ControllerHandle);
    FreePool(Ctx);
    return Status;
  }

  // Determine Endpoint Indices Assigned by Controller
  // The UsbFnIo protocol usually updates the descriptors or we have to just
  // assume/ask. For standard Qualcomm UsbDeviceDxe, it assigns based on order
  // or checks descriptors. We set them to indices 1, 2, 3 in descriptors.
  Ctx->BulkInEndpoint    = 1;
  Ctx->BulkOutEndpoint   = 2;
  Ctx->InterruptEndpoint = 3;

  // Start Controller
  Status = UsbFnIo->StartController(UsbFnIo);
  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "Usb Serial: Start Controller Failed %r\n", Status));
    // Cleanup
    return Status;
  }

  // Initialize Serial IO
  Ctx->SerialIo.Revision      = EFI_SERIAL_IO_PROTOCOL_REVISION;
  Ctx->SerialIo.Reset         = SerialReset;
  Ctx->SerialIo.SetAttributes = SerialSetAttributes;
  Ctx->SerialIo.SetControl    = SerialSetControl;
  Ctx->SerialIo.GetControl    = SerialGetControl;
  Ctx->SerialIo.Write         = SerialWrite;
  Ctx->SerialIo.Read          = SerialRead;
  Ctx->SerialIo.Mode          = &mSerialIoMode;

  // Install Protocol on new Handle (Virtual Serial Handle)
  Status = gBS->InstallMultipleProtocolInterfaces(
      &Ctx->SerialIoHandle, &gEfiSerialIoProtocolGuid, &Ctx->SerialIo, NULL);

  // Start Timer for Polling
  Status = gBS->CreateEvent(
      EVT_TIMER | EVT_NOTIFY_SIGNAL, TPL_CALLBACK, UsbPollTimerHandler, Ctx,
      &Ctx->ImageHandle); // Reuse ImageHandle storage for Event? No..
  // ... better use a dedicated event member in context if needed. Skipping
  // explicit timer var for brevity, just fire it.
  EFI_EVENT TimerEvent;
  Status = gBS->CreateEvent(
      EVT_TIMER | EVT_NOTIFY_SIGNAL, TPL_NOTIFY, UsbPollTimerHandler, Ctx,
      &TimerEvent);
  if (!EFI_ERROR(Status)) {
    gBS->SetTimer(TimerEvent, TimerPeriodic, 100000); // 10ms
  }

  Ctx->MediaConnected = TRUE; // Assume connected initially or wait for Attach

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingStop(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN UINTN NumberOfChildren, IN EFI_HANDLE *ChildHandleBuffer OPTIONAL)
{
  // Simplified Stop
  return EFI_SUCCESS;
}

//
// ENTRY POINT
//

EFI_DRIVER_BINDING_PROTOCOL gUsbSerialDriverBinding = {
    QcomUsbSerialDriverBindingSupported,
    QcomUsbSerialDriverBindingStart,
    QcomUsbSerialDriverBindingStop,
    0xa,
    NULL,
    NULL};

EFI_STATUS
EFIAPI
QcomUsbSerialEntryPoint(
    IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
  gUsbSerialDriverBinding.ImageHandle         = ImageHandle;
  gUsbSerialDriverBinding.DriverBindingHandle = ImageHandle;

  return gBS->InstallMultipleProtocolInterfaces(
      &ImageHandle, &gEfiDriverBindingProtocolGuid, &gUsbSerialDriverBinding,
      NULL);
}
