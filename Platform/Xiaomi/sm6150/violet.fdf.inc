// per-device BSP DXEs
INF  Platform/EFI_Binaries/Drivers/sm6150/ButtonsDxe/ButtonsDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/UsbInitDxe/UsbInitDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/QcomUsbSerialDxe/QcomUsbSerialDxe.inf

// Panel XMLs
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
