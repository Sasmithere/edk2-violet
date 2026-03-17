[Defines]
  VENDOR_NAME                    = Xiaomi
  PLATFORM_NAME                  = violet
  PLATFORM_GUID                  = 28f1a3bf-193a-47e3-a7b9-5a435eaab2ee
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Platform/Qualcomm/sm6150/sm6150.fdf
  DEVICE_DXE_FV_COMPONENTS       = Platform/Xiaomi/sm6150/violet.fdf.inc

  # Enable A/B Slot Environment
  AB_SLOTS_SUPPORT               = TRUE
  USE_UART                       = 0

!include Platform/Qualcomm/sm6150/sm6150.dsc

[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = -DENABLE_SIMPLE_INIT
  

#[LibraryClasses.common.SEC]
#  DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf

#[LibraryClasses.common.DXE_CORE, LibraryClasses.common.DXE_DRIVER, LibraryClasses.common.UEFI_DRIVER, LibraryClasses.common.UEFI_APPLICATION, LibraryClasses.common.DXE_RUNTIME_DRIVER]
 # DebugLib|MdeModulePkg/Library/PeiDxeDebugLibReportStatusCode/PeiDxeDebugLibReportStatusCode.inf


  
[PcdsFixedAtBuild.common]

  gQcomTokenSpaceGuid.PcdMipiFrameBufferWidth|1080
  gQcomTokenSpaceGuid.PcdMipiFrameBufferHeight|2340
  
  # Simple Init
  gSimpleInitTokenSpaceGuid.PcdGuiDefaultDPI|400

  gRenegadePkgTokenSpaceGuid.PcdDeviceVendor|"Xiaomi"
  gRenegadePkgTokenSpaceGuid.PcdDeviceProduct|"Redmi Note 7 Pro"
  gRenegadePkgTokenSpaceGuid.PcdDeviceCodeName|"violet" 

  
  #gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x2F
  #gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x8000004F # DEBUG_INFO|WARN|LOAD|FS|INIT|BM
  
  #gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x00
  #gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x00000000 # DEBUG_INFO|WARN|LOAD|FS|INIT|BM
  
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbVendorId|0x18d1
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbProductId|0xd00d

# Produce the highest video mode in Shell and UiApp
[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|0 # /8 = column
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|0 #/19 = row
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|0

[Components.common]
# Silence DxeCore and CpuDxe noise (AllocatePool / UpdateRegionMapping)
  MdeModulePkg/Core/Dxe/DxeMain.inf {
    <PcdsFixedAtBuild>
      # gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x80000002 # DEBUG_ERROR | DEBUG_WARN
  }
  ArmPkg/Drivers/CpuDxe/CpuDxe.inf {
    <PcdsFixedAtBuild>
      # gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x80000002 # DEBUG_ERROR | DEBUG_WARN
  }

  Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTsDevice.inf
  Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTs.inf
  extras/QcomUsbSerialDxe.inf {
    <LibraryClasses>
      DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
  }
  MdeModulePkg/Bus/Pci/XhciDxe/XhciDxe.inf
  MdeModulePkg/Universal/DebugPortDxe/DebugPortDxe.inf
  MdeModulePkg/Universal/SerialDxe/SerialDxe.inf
  EmbeddedPkg/Drivers/AndroidFastbootTransportUsbDxe/FastbootTransportUsbDxe.inf
  EmbeddedPkg/Application/AndroidFastboot/AndroidFastbootApp.inf
  EmbeddedPkg/Drivers/FdtClientDxe/FdtClientDxe.inf
  #LogDumperDxe/LogDumperDxe.inf
  #LogDumperApp/LogDumperApp.inf
  #extras/QcomUsbSerialDxe.inf
  extras/UsbInitDxe/UsbInitDxe.inf

  


  
