DefinitionBlock ("", "DSDT", 2, "QCOMM ", "SM6150 ", 0x00000003)
{
    Scope (_SB)
    {
        Name (PSUB, "MTP06150")  // Updated from MTP06150 to violet-specific
        Name (SOID, 0xFFFFFFFF)
        Name (STOR, 0xABCABCAB)
        Name (SIDS, "899800000000000")
        Name (SIDV, 0xFFFFFFFF)
        Name (SVMJ, 0xFFFF)
        Name (SVMI, 0xFFFF)
        Name (SDFE, 0xFFFF)
        Name (SFES, "899800000000000")
        Name (SIDM, 0x0000000FFFFFFFFF)
        Name (SUFS, 0xFFFFFFFF)
        Name (PUS3, 0xFFFFFFFF)
        Name (SUS3, 0xFFFFFFFF)
        Name (SIDT, 0xFFFFFFFF)
        Name (SOSN, 0xAAAAAAAABBBBBBBB)
        Name (PLST, 0xFFFFFFFF)
        Name (EMUL, 0xFFFFFFFF)
        Name (SJTG, 0xFFFFFFFF)
        Name (RMTB, 0xAAAAAAAA)
        Name (RMTX, 0xBBBBBBBB)
        Name (RFMB, 0xCCCCCCCC)
        Name (RFMS, 0xDDDDDDDD)
        Name (RFAB, 0xEEEEEEEE)
        Name (RFAS, 0x77777777)
        Name (TCMA, 0xDEADBEEF)
        Name (TCML, 0xBEEFDEAD)
        Name (SOSI, 0xDEADBEEFFFFFFFFF)
        Name (PRP0, 0xFFFFFFFF)
        Name (PRP1, 0xFFFFFFFF)
        Name (PRP2, 0xFFFFFFFF)
        Name (PRP3, 0xFFFFFFFF)
        Name (PRP4, 0xFFFFFFFF)
        Name (PRP5, 0xFFFFFFFF)
        Name (PRP6, 0xFFFFFFFF)

        // Define deps early (GIO0, PMIC) via includes? No, include later; reference with full paths
        Device (UFS0)
        {
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (0x0F)
            }

            Name (_HID, "QCOM24A5")  // _HID: Hardware ID
            Alias (\_SB.PSUB, EMUL)  // Fixed: Full path for Alias
            Name (_UID, Zero)  // _UID: Unique ID
            Name (_CCA, Zero)  // _CCA: Cache Coherency Attribute
            Method (_CRS, 0, Serialized)  // Fixed: Serialized for Name
            {
                Name (RBUF, ResourceTemplate ()
                {
                    Memory32Fixed (ReadWrite,
                        0x04804000,         // Address Base
                        0x00014000,         // Address Length
                        )
                    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, )
                    {
                        0x00000184,
                    }
                })
                Return (RBUF) /* \_SB_.UFS0._CRS.RBUF */
            }

            Device (DEV0)
            {
                Method (_ADR, 0, NotSerialized)  // _ADR: Address
                {
                    Return (0x08)
                }

                Method (_RMV, 0, NotSerialized)  // _RMV: Removal Status
                {
                    Return (Zero)
                }
            }
        }

        Device (SDC2)
        {
            Name (_HID, "QCOM8051")  // Qualcomm SDHCI for SD card
            Name (_UID, 2)  // Unique ID
            Name (_CCA, 0)  // Non-cache coherent
            Name (_DEP, Package (0x02)  // Dependencies
            {
                \_SB.GIO0,  // Full path; defined later via include
                \_SB.PMIC   // Full path
            })

            Method (_CRS, 0, Serialized)  // Fixed: Serialized
            {
                Name (RBUF, ResourceTemplate ()
                {
                    Memory32Fixed (ReadWrite,
                        0x08804000,         // SDC2 HC register base
                        0x00001000,         // Length
                        )
                    Memory32Fixed (ReadWrite,
                        0x08800000,         // SDC2 core mem
                        0x00001000,         // Length
                        )
                    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, )
                    {
                        0x0000007D,  // IRQ 125
                        0x000000DD   // IRQ 221
                    }
                    GpioInt (Edge, ActiveLow, Exclusive, PullUp, 0x0000,
                        "\\_SB.GIO0", 0x00, ResourceConsumer, ,
                        )
                        {   // Pin list for card detect
                            0x0000007E  // GPIO 126
                        }
                })
                Return (RBUF)
            }

            Name (_DSD, Package (0x02)  // _DSD: Device-Specific Data
            {
                ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
                Package () {
                    Package (2) {"reg", 2},
                    Package (2) {"bus-width", 4},
                    Package (2) {"cd-gpios", Package (4) {"\\_SB.SDC2", 0, 0, 1}},  // Fixed: String path for ref
                    Package (2) {"max-frequency", 200000000},
                    Package (2) {"status", "okay"}
                }
            })

            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (0x0F)  // Enabled and visible
            }
        }

        // Includes now (after early refs). Place includes directly inside \_SB so referenced devices are defined.
        Include("abd.dsl")  // Early for ROP1 ref
        Include("qcgpio.dsl")  // GIO0 next
        Include("pmic_core.dsl")  // Now safe
        Include("scm.dsl")
        Include("spmi.dsl")
        Include("btns.dsl")
        Include("pep_lpi.dsl")
        Include("usb.dsl")
        //Include("touch.dsl")
    }  // Close Scope (_SB)
}  // Close DefinitionBlock
