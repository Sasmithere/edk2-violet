Device (I2C5)
{
    Name (_HID, "QCOM0400")
    Name (_UID, 5)
    Name (_CCA, Zero)

    Method (_CRS, 0, Serialized)
    {
        Return (ResourceTemplate ()
        {
            Memory32Fixed (ReadWrite, 0x088A0000, 0x00000600)
            Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, )
            {
                0x0000010C
            }
        })
    }

    Name (_DSD, Package (0x02)
    {
        ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package ()
        {
            Package (2) { "clock-frequency", 400000 },
            Package (2) { "status", "okay" }
        }
    })

    Device (TOUCH)
    {
        Name (_HID, "GOOD0001")
        Name (_UID, Zero)
        Name (_ADR, 0x5D)

        Method (_CRS, 0, Serialized)
        {
            Return (ResourceTemplate ()
            {
                I2cSerialBusV2 (0x5D, ControllerInitiated, 0x00061A80,
                    AddressingMode7Bit, "\\_SB.I2C5", 0x00,
                    ResourceConsumer, , Exclusive)
                GpioInt (Edge, ActiveHigh, ExclusiveAndWake, PullUp, 0x0000,
                    "\\_SB.GIO0", 0x00, ResourceConsumer, , )
                {
                    0x0000000C
                }
            })
        }

        Name (_DSD, Package (0x02)
        {
            ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
            Package ()
            {
                Package (2) { "compatible", "goodix,gt9896" },
                Package (2) { "touchscreen-size-x", 2340 },
                Package (2) { "touchscreen-size-y", 1080 },
                Package (2) { "touchscreen-swapped-x-y", 0x01 },
                Package (2) { "status", "okay" }
            }
        })

        Method (_STA, 0, NotSerialized)
        {
            Return (0x0F)
        }
    }
}
