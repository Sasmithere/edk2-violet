// per-device BSP DXEs
INF  Platform/EFI_Binaries/Drivers/sm6150/ButtonsDxe/ButtonsDxe.inf
INF Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTsDevice.inf
INF Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/NovatekNvtTs.inf
  
#INF  extras/UsbInitDxe/UsbInitDxe.inf
#INF  extras/QcomUsbSerialDxe.inf

FILE FREEFORM = 45079628-9EC0-421A-9D33-1A27B3C42A96 {
  SECTION UI = "Panel_truly_hx83112a_fhd_video.xml"
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/Panel_truly_hx83112a_fhd_video.xml
}

FILE FREEFORM = 937D07E9-DA4E-48FD-B6AB-E9748FBF51FB {
  SECTION UI = "Panel_tianma_ft8719_fhd_video.xml"
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/Panel_tianma_ft8719_fhd_video.xml
}

FILE FREEFORM = 1F8414F2-28E7-4622-8DBE-9D8D37962041 {
  SECTION UI = "Panel_shenchao_nt36672a_fhd_video.xml"
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/Panel_shenchao_nt36672a_fhd_video.xml
}

FILE FREEFORM = 1E2C1F8E-903F-42AA-B1CC-ECA4056F7EEF {
  SECTION UI = "Panel_truly_td4328_1080p_cmd.xml"
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/Panel_truly_td4328_1080p_cmd.xml
}

FILE FREEFORM = 6C997290-7B00-4E81-A004-350EF927DAFA {
  SECTION UI = "Panel_truly_td4328_1080p_vid.xml"
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/Panel_truly_td4328_1080p_vid.xml
}

FILE FREEFORM = 3E5584ED-05D4-4267-9048-0D47F76F4248 {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = 4753E815-DDD8-402D-BF69-9B8C4EB7573E {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = 03DED53E-BECD-428F-9F79-5ABA64C58445 {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = 8B86CD38-C772-4FCF-85AA-345B2B3C1AB4 {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = 3FD97907-93F1-4349-AF3C-3B68B0A5E626 {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = E2EA5A4F-98BD-4203-AB49-399505DDFB7D {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = C72FB1A9-5527-4E13-BAC4-F671D0330145 {
    SECTION UI = "battery_miui.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_miui.bmp
}


FILE FREEFORM = B0F8D1BE-5353-4812-B1F6-07E7768204CC {
    SECTION UI = "battery_symbol_DebugBoot.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_symbol_DebugBoot.bmp
}


FILE FREEFORM = F9E8F683-E065-4E09-B4F9-0230D7CECD08 {
    SECTION UI = "battery_symbol_DebugStay.bmp"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/battery_symbol_DebugStay.bmp
}

FILE FREEFORM = 45FE4B7C-150C-45DA-A021-4BEB2048EC6F {
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/QcomChargerCfg.cfg
  SECTION UI = "QcomChargerCfg.cfg"
}

FILE FREEFORM = 21E9BDD9-6C3F-4F10-84A5-BBEC322741F1 {
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/uefipil.cfg
  SECTION UI = "uefipil.cfg"
}  

FILE FREEFORM = DDE58710-41CD-4306-DBFB-3FA90BB1D2DD {
  SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/uefiplat.cfg
  SECTION UI = "uefiplat.cfg"
}

FILE FREEFORM = A1E235DE-E825-4591-9623-C43175811826 {
    SECTION UI = "SecParti.cfg"
    SECTION RAW = Platform/Xiaomi/sm6150/RawFiles/SecParti.cfg
}

// ACPI Tables
 FILE FREEFORM = 7E374E25-8E01-4FEE-87F2-390C23C606CD {
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/DBG2.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/SPCR.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/GTDT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/MADT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/FADT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/DSDT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/IORT.aml
  //SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/MCFG.aml
  //SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/PPTT.aml
  //SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/SSDT.aml
  SECTION UI = "AcpiTables"
 }


FILE FREEFORM = 25462CDA-221F-47DF-AC1D-259CFAA4E326 {
  SECTION RAW = Platform/Xiaomi/sm6150/FdtBlob/sm6150-idp.dtb
}




//FILE FREEFORM = 7E565220-4523-4554-8977-124578564532 {
//    SECTION RAW = Silicon/Qualcomm/QcomPkg/Drivers/NovatekTouchDxe/novatek_fw.bin
 //   SECTION UI = "novatek_fw.bin"
//}
