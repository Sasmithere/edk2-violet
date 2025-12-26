Device (PMIC)
{
    Name (_DEP, Package (0x01)
    {
        \_SB.SPMI  // Full path
    })
    Name (_HID, "QCOM05CE")  // Updated for PM6150
    Name (_CID, "PNP0CA3")
    Alias (\_SB.PSUB, _SUB)  // Fixed: Full path
    Method (PMCF, 0, Serialized)  // Serialized
    {
        Name (CFG0, Package (0x03)  // Fixed: Match actual length (removed extra)
        {
            0x02, 
            Package (0x02)
            {
                Zero, 
                One
            }, 
            Package (0x02)
            {
                0x02, 
                0x03
            }
        })
        Return (CFG0)
    }
}

Device (PM01)
{
    Name (_HID, "QCOM05CE")
    Alias (\_SB.PSUB, _SUB)  // Fixed
    Name (_UID, Zero)
    Name (_DEP, Package (0x01)
    {
        \_SB.PMIC  // Full path
    })

    Method (_CRS, 0, Serialized)
    {
        Name (RBUF, ResourceTemplate ()
        {
            Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
            {
                0x000000D7,
            }
        })
        Return (RBUF)
    }

    Method (_DSM, 4, Serialized)  // Serialized; added Return in all paths
    {
        // ... (keep original body, but add Return (Buffer (One){0x00}) at end of While)
        While (One)
        {
            // Original code...
            Break
        }
        Return (Buffer (One){0x00})  // Ensure return
    }
}

Device (PMAP)
{
    Name (_HID, "QCOM052F")
    Alias (\_SB.PSUB, _SUB)  // Fixed
    Name (_DEP, Package (0x03)
    {
        \_SB.PMIC, 
        \_SB.ABD,  // Full path
        \_SB.SCM0  // Full path
    })
    Method (GEPT, 0, Serialized)
    {
        Name (BUFF, Buffer (0x04){})
        CreateByteField (BUFF, Zero, STAT)
        CreateWordField (BUFF, 0x02, DATA)
        DATA = 0x02
        Return (DATA)
    }

    Method (_CRS, 0, Serialized)
    {
        Name (RBUF, Buffer (0x02)
        {
                0x79, 0x00
        })
        Return (RBUF)
    }
}

Device (PRTC)
{
    Name (_HID, "ACPI000E" /* Time and Alarm Device */)
    Name (_DEP, Package (0x01)
    {
        \_SB.PMAP
    })
    Method (_STA, 0, NotSerialized)
    {
        Return (0x0F)
    }

    Method (_GCP, 0, NotSerialized)
    {
        Return (0x04)
    }

    // Fixed: Ensure ABD exists before Field; assume include order
    Field (\_SB.ABD.ROP1, BufferAcc, NoLock, Preserve)
    {
        Connection (
            I2cSerialBusV2 (0x0002, ControllerInitiated, 0x00000000,
                AddressingMode7Bit, "\\_SB.ABD",
                0x00, ResourceConsumer, , Exclusive,
                )
        ), 
        AccessAs (BufferAcc, AttribRawBytes (0x18)), 
        FLD0,   192
    }

Method (_GRT, 0, Serialized)
    {
        Name (BUFF, Buffer (0x1A){})
        CreateField (BUFF, 0x10, 0x80, TME1)
        CreateField (BUFF, 0x90, 0x20, ACT1)
        CreateField (BUFF, 0xB0, 0x20, ACW1)
        ACT1 = Zero  // Use to suppress remark
        ACW1 = Zero
        BUFF = FLD0
        Return (TME1)
    }

    Method (_SRT, 1, Serialized)
    {
        Name (BUFF, Buffer (0x32){})
        CreateByteField (BUFF, Zero, STAT)
        CreateField (BUFF, 0x10, 0x80, TME1)
        CreateField (BUFF, 0x90, 0x20, ACT1)
        CreateField (BUFF, 0xB0, 0x20, ACW1)
        ACT1 = Zero
        TME1 = Arg0
        ACW1 = Zero
        BUFF = FLD0 = BUFF
        If ((STAT != Zero))
        {
            Return (One)
        }
        Return (Zero)
    }
}

Device (PEXT)
{
    Name (_DEP, Package (0x02)
    {
        \_SB.SPMI, 
        \_SB.PMIC
    })
    Name (_HID, "QCOM05CE")
    Alias (\_SB.PSUB, _SUB)
}
