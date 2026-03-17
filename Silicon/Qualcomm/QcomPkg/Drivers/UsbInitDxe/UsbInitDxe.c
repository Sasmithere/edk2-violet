#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/UsbFunctionIo.h>
#include <Uefi.h>

//
// Descriptors (Adapted from Sm6150Initializer/QcomUsbSerialDxe)
// Matches Reference 2: Fastboot/Dummy configuration to just "Start" the
// controller.
//

// Device Descriptor
STATIC EFI_USB_DEVICE_DESCRIPTOR mDeviceDescriptor = {
    sizeof(EFI_USB_DEVICE_DESCRIPTOR), // Length
    USB_DESC_TYPE_DEVICE,              // DescriptorType
    0x0200,                            // BcdUSB
    0x00,                              // DeviceClass (Defined at Interface)
    0x00,                              // DeviceSubClass
    0x00,                              // DeviceProtocol
    64,                                // MaxPacketSize0
    0x18D1, // IdVendor (Google - common for fastboot/init)
    0xD00D, // IdProduct (Fastboot - common for init)
    0x0100, // BcdDevice
    1,      // StrManufacturer
    2,      // StrProduct
    3,      // StrSerialNumber
    1       // NumConfigurations
};

// Configuration Descriptor Structure
#pragma pack(1)
typedef struct {
  EFI_USB_CONFIG_DESCRIPTOR    Config;
  EFI_USB_INTERFACE_DESCRIPTOR Interface0;
  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointIn;
  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointOut;
} TOTAL_CONFIG_DESCRIPTOR;
#pragma pack()

// Configuration Descriptor Instance
STATIC TOTAL_CONFIG_DESCRIPTOR mConfigDescriptor = {
    // Config
    {
        sizeof(EFI_USB_CONFIG_DESCRIPTOR), USB_DESC_TYPE_CONFIG,
        sizeof(TOTAL_CONFIG_DESCRIPTOR),
        1,    // NumInterfaces
        1,    // ConfigurationValue
        0,    // ConfigurationStr
        0xC0, // Attributes (Self-powered)
        100   // MaxPower (200mA)
    },
    // Interface 0
    {
        sizeof(EFI_USB_INTERFACE_DESCRIPTOR), USB_DESC_TYPE_INTERFACE,
        0,    // InterfaceNumber
        0,    // AlternateSetting
        2,    // NumEndpoints (Bulk IN, Bulk OUT)
        0xFF, // InterfaceClass (Vendor)
        0x42, // InterfaceSubClass (ADB/Fastboot subclass)
        0x03, // InterfaceProtocol (Fastboot protocol)
        0     // InterfaceStr
    },
    // Endpoint IN
    {
        sizeof(EFI_USB_ENDPOINT_DESCRIPTOR), USB_DESC_TYPE_ENDPOINT,
        0x81, // EndpointAddress (IN, 1)
        0x02, // Attributes (Bulk)
        512,  // MaxPacketSize (HS)
        0     // Interval
    },
    // Endpoint OUT
    {
        sizeof(EFI_USB_ENDPOINT_DESCRIPTOR), USB_DESC_TYPE_ENDPOINT,
        0x01, // EndpointAddress (OUT, 1)
        0x02, // Attributes (Bulk)
        512,  // MaxPacketSize (HS)
        0     // Interval
    }};

// Global Buffers for DMA
STATIC VOID *mDeviceDescBuffer = NULL;
STATIC VOID *mConfigDescBuffer = NULL;

EFI_STATUS
EFIAPI
UsbInitEntry(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_STATUS             Status;
  EFI_USBFN_IO_PROTOCOL *UsbFnIo;

  //
  // Step 1: Locate Protocol
  //
  Status = gBS->LocateProtocol(
      &gEfiUsbFunctionIoProtocolGuid, NULL, (VOID **)&UsbFnIo);

  if (EFI_ERROR(Status)) {
    DEBUG(
        (EFI_D_ERROR, "UsbInitDxe: Failed to locate UsbFnIo protocol: %r\n",
         Status));
    return Status;
  }

  DEBUG((EFI_D_ERROR, "UsbInitDxe: Located UsbFnIo protocol.\n"));

  //
  // Step 2: Init (Prepare Descriptors & Info)
  //

  // Allocate DMA-capable buffers for descriptors if required by controller
  // (DWC3 usually requires this) Although ConfigureEnableEndpoints takes
  // pointers, it's safer to use AllocateTransferBuffer or standard pool if the
  // lower layer copies them. For UsbFnIo DWC3, usually the structures
  // themselves are copied, but let's stick to standard stack allocations or
  // global/static as used in references. Reference 2 uses global statics for
  // descriptors. Reference 1 uses AllocateTransferBuffer for *transfers*, but
  // ConfigureEnableEndpoints usually takes a structure pointer.

  EFI_USB_DEVICE_INFO          DeviceInfo;
  EFI_USB_CONFIG_INFO          ConfigInfo;
  EFI_USB_INTERFACE_INFO       Interface0;
  EFI_USB_INTERFACE_INFO      *Interfaces[]  = {&Interface0, NULL};
  EFI_USB_CONFIG_INFO         *ConfigTable[] = {&ConfigInfo, NULL};
  EFI_USB_ENDPOINT_DESCRIPTOR *EpTable0[]    = {
      &mConfigDescriptor.EndpointIn, &mConfigDescriptor.EndpointOut, NULL};

  // Setup Device Info
  DeviceInfo.DeviceDescriptor = &mDeviceDescriptor;
  DeviceInfo.ConfigInfoTable  = ConfigTable;

  // Setup Config Info
  ConfigInfo.ConfigDescriptor   = &mConfigDescriptor.Config;
  ConfigInfo.InterfaceInfoTable = Interfaces;

  // Setup Interface Info
  Interface0.InterfaceDescriptor     = &mConfigDescriptor.Interface0;
  Interface0.EndpointDescriptorTable = EpTable0;

  DEBUG((EFI_D_ERROR, "UsbInitDxe: Initialization Data Ready.\n"));

  //
  // Step 3: Configure (ConfigureEnableEndpoints)
  // * Note: User asked for "Start -> Configure", but standard USB stack usually
  // requires
  //   Endpoints configured *before* Start (Pull-up). We follow the working
  //   reference logic here. "UsbInit" implies getting the hardware ready.
  //

  Status = UsbFnIo->ConfigureEnableEndpoints(UsbFnIo, &DeviceInfo);
  if (EFI_ERROR(Status)) {
    DEBUG(
        (EFI_D_ERROR, "UsbInitDxe: ConfigureEnableEndpoints failed: %r\n",
         Status));
    return Status;
  }

  DEBUG((EFI_D_ERROR, "UsbInitDxe: Endpoints Configured.\n"));

  //
  // Step 4: Start Controller
  //
  Status = UsbFnIo->StartController(UsbFnIo);
  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "UsbInitDxe: StartController failed: %r\n", Status));
    return Status;
  }

  DEBUG((
      EFI_D_ERROR, "UsbInitDxe: Start Controller SUCCESS. USB Initialized.\n"));

  return EFI_SUCCESS;
}
