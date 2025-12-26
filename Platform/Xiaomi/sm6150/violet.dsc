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
  USE_UART                       = 1

!include Platform/Qualcomm/sm6150/sm6150.dsc

  
[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = -DENABLE_SIMPLE_INIT -DENABLE_LINUX_SIMPLE_MASS_STORAGE


[PcdsFixedAtBuild.common]
  
  gQcomTokenSpaceGuid.PcdMipiFrameBufferWidth|1080
  gQcomTokenSpaceGuid.PcdMipiFrameBufferHeight|2340
  
  # Simple Init
  gSimpleInitTokenSpaceGuid.PcdGuiDefaultDPI|400

  gRenegadePkgTokenSpaceGuid.PcdDeviceVendor|"Xiaomi"
  gRenegadePkgTokenSpaceGuid.PcdDeviceProduct|"Redmi Note 7 Pro"
  gRenegadePkgTokenSpaceGuid.PcdDeviceCodeName|"violet" 
 

  gQcomTokenSpaceGuid.PcdTouchCtlrAddress|0x62
  gQcomTokenSpaceGuid.PcdTouchCtlrResetPin|88
  gQcomTokenSpaceGuid.PcdTouchCtlrIntPin|89
  gQcomTokenSpaceGuid.PcdTouchCtlrI2cDevice|2
  gQcomTokenSpaceGuid.PcdTouchMinX|0
  gQcomTokenSpaceGuid.PcdTouchMaxX|1079
  gQcomTokenSpaceGuid.PcdTouchInvertedX|0
  gQcomTokenSpaceGuid.PcdTouchMinY|0
  gQcomTokenSpaceGuid.PcdTouchMaxY|2339
  gQcomTokenSpaceGuid.PcdTouchInvertedY|0
  gQcomTokenSpaceGuid.PcdTouchCtlrVddPin|0
  gQcomTokenSpaceGuid.PcdTouchCtlrVddIoPin|0
  gQcomTokenSpaceGuid.PcdTouchCtlrVddPinActiveLow|0
  
  gQcomTokenSpaceGuid.PcdDebugUartPortBase|0x880000 #0xa88000

  gQcomTokenSpaceGuid.PcdUsbSerialEnable|TRUE

  #gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0xFFFFFFFF
  #gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x2F
  
  gEfiMdeModulePkgTokenSpaceGuid.PcdSdMmcPciHostControllerMmioBase|0x007C0000
  
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbVendorId|0x18D1
  gEmbeddedTokenSpaceGuid.PcdAndroidFastbootUsbProductId|0xD00D
  



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
  Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTsDevice.inf
  Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTs.inf
  
  MdeModulePkg/Bus/I2c/I2cDxe/I2cDxe.inf
  
  EmbeddedPkg/Universal/MmcDxe/MmcDxe.inf
  Platform/EFI_Binaries/Drivers/sm6150/MsmSdMmcDxe/MsmSdMmcDxe.inf
  MdeModulePkg/Bus/Pci/SdMmcPciHcDxe/SdMmcPciHcDxe.inf
  MdeModulePkg/Bus/Sd/SdDxe/SdDxe.inf
  MdeModulePkg/Bus/Sd/EmmcDxe/EmmcDxe.inf
  
  #uart through usb tried
  extras/QcomUsbSerialDxe/QcomUsbSerialDxe.inf
  
  MdeModulePkg/Bus/Pci/XhciDxe/XhciDxe.inf
  MdeModulePkg/Universal/DebugPortDxe/DebugPortDxe.inf
  MdeModulePkg/Universal/SerialDxe/SerialDxe.inf
  #
  # USB Peripheral Support
  #
  EmbeddedPkg/Drivers/AndroidFastbootTransportUsbDxe/FastbootTransportUsbDxe.inf

  #
  # Fastboot
  #
  EmbeddedPkg/Application/AndroidFastboot/AndroidFastbootApp.inf
  


  
