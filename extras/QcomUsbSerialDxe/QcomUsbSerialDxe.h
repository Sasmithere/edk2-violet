/** @file
  Header file for Qualcomm USB Serial DXE (CDC ACM)

  Copyright (c) 2024, Renegade Project. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _QCOM_USB_SERIAL_DXE_H_
#define _QCOM_USB_SERIAL_DXE_H_

#include <IndustryStandard/Usb.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/DriverBinding.h>
#include <Protocol/SerialIo.h>
#include <Protocol/UsbFunctionIo.h>
#include <Uefi.h>

//
// Vendor ID and Product ID
// Using Google/Android typical IDs or Linux Foundation for Gadget
//
#define USB_VENDOR_ID 0x18D1  // Google
#define USB_PRODUCT_ID 0xD00D // Simple bootloader interface / Generic

//
// Buffer sizes
//
#define MAX_PACKET_SIZE_HS 512
#define MAX_PACKET_SIZE_SS 1024
#define TX_BUFFER_SIZE 4096
#define RX_BUFFER_SIZE 4096

//
// Endpoints definitions (will be assigned by UsbFnIo)
//
#define ENDPOINT_COUNT 3

//
// USB Request Types & Request Codes for CDC
//
#define USB_REQ_TYPE_CLASS 0x20
#define USB_REQ_TYPE_INTERFACE 0x01

#define USB_CDC_SEND_ENCAPSULATED_COMMAND 0x00
#define USB_CDC_GET_ENCAPSULATED_RESPONSE 0x01
#define USB_CDC_SET_COMM_FEATURE 0x02
#define USB_CDC_GET_COMM_FEATURE 0x03

#ifndef USB_DESC_TYPE_DEVICE_QUALIFIER
#define USB_DESC_TYPE_DEVICE_QUALIFIER 0x06
#endif

#pragma pack(1)
typedef struct {
  UINT8  Length;
  UINT8  DescriptorType;
  UINT16 BcdUSB;
  UINT8  DeviceClass;
  UINT8  DeviceSubClass;
  UINT8  DeviceProtocol;
  UINT8  MaxPacketSize0;
  UINT8  NumConfigurations;
  UINT8  Reserved;
} EFI_USB_DEVICE_QUALIFIER_DESCRIPTOR;
#pragma pack()

//
// USB Request Types
//
#define USB_CDC_CLEAR_COMM_FEATURE 0x04
#define USB_CDC_SET_LINE_CODING 0x20
#define USB_CDC_GET_LINE_CODING 0x21
#define USB_CDC_SET_CONTROL_LINE_STATE 0x22
#define USB_CDC_SEND_BREAK 0x23

//
// Structures for CDC
//
#pragma pack(1)

typedef struct {
  UINT32 BaudRate;
  UINT8  StopBits;
  UINT8  Parity;
  UINT8  DataBits;
} USB_CDC_LINE_CODING;

typedef struct {
  UINT8 bFunctionLength;
  UINT8 bDescriptorType; // 0x24: CS_INTERFACE
  UINT8 bDescriptorSubtype;
} USB_CDC_FUNC_DESC_HEADER;

// Subtype 0: Header Functional Descriptor
typedef struct {
  USB_CDC_FUNC_DESC_HEADER Header;
  UINT16                   bcdCDC;
} USB_CDC_HEADER_DESC;

// Subtype 1: Call Management Functional Descriptor
typedef struct {
  USB_CDC_FUNC_DESC_HEADER Header;
  UINT8                    bmCapabilities;
  UINT8                    bDataInterface;
} USB_CDC_CALL_MAN_DESC;

// Subtype 2: ACM Functional Descriptor
typedef struct {
  USB_CDC_FUNC_DESC_HEADER Header;
  UINT8                    bmCapabilities;
} USB_CDC_ACM_DESC;

// Subtype 6: Union Functional Descriptor
typedef struct {
  USB_CDC_FUNC_DESC_HEADER Header;
  UINT8 bControlInterface; // The Interface Number of the Communication or Data
                           // Class interface
  UINT8
  bSubordinateInterface0; // Interface Number of first subordinate interface
} USB_CDC_UNION_DESC;

#pragma pack()

//
// Driver Context
//
typedef struct {
  EFI_HANDLE ImageHandle;
  EFI_HANDLE DriverBindingHandle;

  EFI_USBFN_IO_PROTOCOL *UsbFnIo;
  EFI_SERIAL_IO_PROTOCOL SerialIo;
  EFI_HANDLE             SerialIoHandle;

  // Endpoint Resources
  UINT8 BulkInEndpoint;
  UINT8 BulkOutEndpoint;
  UINT8 InterruptEndpoint;

  UINT16 MaxPacketSize;

  // State
  BOOLEAN MediaConnected;
  BOOLEAN TxInProgress;
  BOOLEAN RxInProgress;

  // Ring Buffers (Simplified)
  // For a basic implementation, we might just use blocking or simple flags
  // But standard SerialIo is polled.

  USB_CDC_LINE_CODING LineCoding;

} USB_SERIAL_CONTEXT;

//
// Prototypes
//
EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingSupported(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL);

EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingStart(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL);

EFI_STATUS
EFIAPI
QcomUsbSerialDriverBindingStop(
    IN EFI_DRIVER_BINDING_PROTOCOL *This, IN EFI_HANDLE ControllerHandle,
    IN UINTN NumberOfChildren, IN EFI_HANDLE *ChildHandleBuffer OPTIONAL);

#endif // _QCOM_USB_SERIAL_DXE_H_
