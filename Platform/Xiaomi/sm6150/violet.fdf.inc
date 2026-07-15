// per-device BSP DXEs
INF  Platform/EFI_Binaries/Drivers/sm6150/ButtonsDxe/ButtonsDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/PILDxe/PILDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/GpiDxe/GpiDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/EnvDxe/EnvDxe.inf
INF  Platform/EFI_Binaries/Drivers/sm6150/VerifiedBootDxe/VerifiedBootDxe.inf


// ACPI Tables
 FILE FREEFORM = 7E374E25-8E01-4FEE-87F2-390C23C606CD {
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/DBG2.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/SPCR.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/GTDT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/MADT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/FADT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/DSDT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/IORT.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/MCFG.aml
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/PPTT.aml
  SECTION UI = "AcpiTables"
 }


FILE FREEFORM = 25462CDA-221F-47DF-AC1D-259CFAA4E326 {
  SECTION RAW = Platform/Xiaomi/sm6150/FdtBlob/sm6150-idp.dtb
}


# qcadc8150+0x127bc , qcspi8150+0x9828s 