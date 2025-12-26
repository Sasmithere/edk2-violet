Device (BTNS)
{
    Name (_HID, "ACPI0011" /* Generic Buttons Device */)
    Alias (\_SB.PSUB, _SUB)  // Fixed
    Name (_UID, Zero)
    Method (_CRS, 0, Serialized)
    {
        Name (RBUF, ResourceTemplate ()
        {
            GpioInt (Edge, ActiveBoth, ExclusiveAndWake, PullDown, 0x0000,
                "\\_SB.GIO0", 0x00, ResourceConsumer, ,
                )
                {   // Power (TLMM stub; violet power is PMIC, but for consistency)
                    0x0000
                }
            GpioInt (Edge, ActiveBoth, Exclusive, PullUp, 0x0000,
                "\\_SB.GIO0", 0x00, ResourceConsumer, ,
                )
                {   // Vol Up
                    0x0085
                }
            GpioInt (Edge, ActiveBoth, Exclusive, PullDown, 0x0000,
                "\\_SB.GIO0", 0x00, ResourceConsumer, ,
                )
                {   // Vol Down
                    0x0000
                }
        })
        Return (RBUF)
    }

    Name (_DSD, Package (0x02)
    {
        ToUUID ("fa6bd625-9ce8-470d-a2c7-b3ca36c4282e"),
        Package (0x04)
        {
            Package (0x05) {Zero, One, Zero, One, 0x0D},
            Package (0x05) {One, Zero, One, One, 0x81},
            Package (0x05) {One, One, One, 0x0C, 0xE9},
            Package (0x05) {One, 0x02, One, 0x0C, 0xEA}
        }
    })
}
