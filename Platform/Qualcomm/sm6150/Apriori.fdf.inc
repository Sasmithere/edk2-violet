APRIORI DXE {

  #
  # PI DXE Drivers producing Architectural Protocols (EFI Services)
  #
  
  INF  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF  MdeModulePkg/Core/Dxe/DxeMain.inf
  INF  MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF  MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF  ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF  ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
  INF  EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF  ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  INF  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  #INF  LogDumperDxe/LogDumperDxe.inf
  
  #INF Platform/EFI_Binaries/Drivers/sm6150/SecRSADxe/SecRSADxe.inf
  #INF Platform/EFI_Binaries/Drivers/sm6150/ASN1X509Dxe/ASN1X509Dxe.inf
  #INF Platform/EFI_Binaries/Drivers/sm6150/VerifiedBootDxe/VerifiedBootDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/SmemDxe/SmemDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/DALSYSDxe/DALSYSDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/HWIODxe/HWIODxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ChipInfoDxe/ChipInfoDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/PlatformInfoDxe/PlatformInfoDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/HALIOMMUDxe/HALIOMMUDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ULogDxe/ULogDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/CmdDbDxe/CmdDbDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/NpaDxe/NpaDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/RpmhDxe/RpmhDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/PdcDxe/PdcDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ClockDxe/ClockDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/TzDxe/ScmDxeLA.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/TzDxe/TzDxeLA.inf
  
  INF  Platform/RenegadePkg/Drivers/SetCPUFreqDxe/SetCPUFreqDxe.inf
  
  INF  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF  MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/UFSDxe/UFSDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/SdccDxe/SdccDxe.inf
  
  INF  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  INF  MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf

  INF  MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
  INF  FatPkg/EnhancedFatDxe/Fat.inf

  INF  Platform/EFI_Binaries/Drivers/sm6150/QcomWDogDxe/QcomWDogDxe.inf
  INF  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF  EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF  MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF  EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF  MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF  MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
 
  INF  Platform/EFI_Binaries/Drivers/sm6150/TLMMDxe/TLMMDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/SPMIDxe/SPMIDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/DDRInfoDxe/DDRInfoDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/PmicDxe/PmicDxeLa.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/QcomBds/QcomBds.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/PILDxe/PILDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/GpiDxe/GpiDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/I2CDxe/I2CDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/AdcDxe/AdcDxe.inf
  
!if $(SECURE_BOOT_ENABLE) == TRUE
  INF  SecurityPkg/VariableAuthenticated/SecureBootConfigDxe/SecureBootConfigDxe.inf
  INF  SecurityPkg/VariableAuthenticated/SecureBootDefaultKeysDxe/SecureBootDefaultKeysDxe.inf
!endif
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ChargerExDxe/ChargerExDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/QcomChargerDxe/QcomChargerDxeLA.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbConfigDxe/UsbConfigDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbDeviceDxe/UsbDeviceDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbMsdDxe/UsbMsdDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/UsbInitDxe/UsbInitDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/QcomUsbSerialDxe/QcomUsbSerialDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/HashDxe/HashDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/RNGDxe/RngDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/TsensDxe/TsensDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/ButtonsDxe/ButtonsDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/FontDxe/FontDxe.inf
  #INF  Silicon/Qualcomm/QcomPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
  INF  Platform/EFI_Binaries/Drivers/sm6150/DisplayDxe/DisplayDxe.inf
  
  INF  Platform/EFI_Binaries/Drivers/sm6150/EnvDxe/EnvDxe.inf
  
  INF  EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF  MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

  INF  MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
  
  INF  MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
 }

