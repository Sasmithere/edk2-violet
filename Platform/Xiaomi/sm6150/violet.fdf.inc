// per-device BSP DXEs
INF  Platform/EFI_Binaries/Drivers/sm6150/ButtonsDxe/ButtonsDxe.inf
//INF  extras/QcomUsbSerialDxe/QcomUsbSerialDxe.inf


// ACPI Tables
FILE FREEFORM = 7E374E25-8E01-4FEE-87F2-390C23C606CD {   
  SECTION RAW = Platform/Xiaomi/sm6150/AcpiTables/violet/DSDT.aml
  SECTION UI = "AcpiTables"
}

 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/old/APIC.aml
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/old/FADT.aml
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/bgrt.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Csrt.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/dbg2.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Facp.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Facs.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Gtdt.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/IORT.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Madt.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Mcfg.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/Pptt.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/spcr.acpi
 // SECTION RAW = Silicon/Qualcomm/sm6150/AcpiTables/TPM2.acpi


FILE FREEFORM = 25462CDA-221F-47DF-AC1D-259CFAA4E326 {
  SECTION RAW = Platform/Xiaomi/sm6150/FdtBlob/violet.dtb
}


