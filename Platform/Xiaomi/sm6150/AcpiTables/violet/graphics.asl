Device (MDSS)
{
    Name (_HID, "QCOM027E")
    Name (_UID, Zero)
    Name (_HRV, 0x7C)
    
    Device (MON0)
    {
        Method (_ADR, 0, NotSerialized)
        {
            Return (Zero)
        }
    }

    Name (_DEP, Package ()
    {
        \_SB.PEP0,
        \_SB.PMIC, 
        \_SB.TREE, 
        \_SB.SCM0
    })

    // _ROM Method - Used to retrieve proprietary ROM data for primary panel
    Method (_ROM, 2, Serialized) {
        // Include primary panel specific ROM data
        Include("panelcfg.asl")

        Local0 = Arg0        // Offset
        Local1 = Arg1        // Length
        Local2 = PCFG        // Panel Config Buffer

        // Ensure offset does not exceed the buffer size 
        If (LGreaterEqual(Local0, Sizeof(Local2)))
        {
            Return( Buffer(){0x0} )
        }

        // Ensure the size requested is reasonable
        If (LGreater(Local1, 0x1000))
        {
            Store(0x1000, Local1)
        }

        // Ensure the total size does not exceed the size of the buffer
        If (LGreater(Add(Local0, Local1), Sizeof(Local2)))
        {
            Subtract(Sizeof(Local2), Local0, Local1)
        }

        // Multiply offset and size by 8 to convert to bits for CreateField
        CreateField(Local2, Multiply(0x8, Local0), Multiply(0x8, Local1), RBUF)

        Return(RBUF)
    }

    Method (_CRS, 0, NotSerialized)
    {
        Name (RBUF, ResourceTemplate ()
        {
            // MDSS MDP (0x0AE00000 - 0x0AF00000)
            Memory32Fixed (ReadWrite, 0x0AE00000, 0x00100000)
            // DSI PHY (0x0AE94000)
            Memory32Fixed (ReadWrite, 0x0AE94000, 0x00001000)
            // MDSS MDP Interrupt (GIC 115)
            Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, ) { 115 }
            
            // GPU Core (0x05000000)
            Memory32Fixed (ReadWrite, 0x05000000, 0x00090000)
            // GPU QFPROM (0x00780000)
            Memory32Fixed (ReadWrite, 0x00780000, 0x00007000)
            // GPU Interrupt (GIC 332)
            Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, ) { 332 }
            
            // GPU CC (0x05090000)
            Memory32Fixed (ReadWrite, 0x05090000, 0x00002000)
            
            // Video (VIDC) (0x0AA00000)
            Memory32Fixed (ReadWrite, 0x0AA00000, 0x00200000)
            // VIDC Interrupt (GIC 206)
            Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, ) { 206 }
            // VIDC Watchdog Interrupt (GIC 207)
            Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive, ,, ) { 207 }
            
            // Panel Reset GPIO (GPIO 91)
            GpioIo (Exclusive, PullUp, 0x0000, 0x0000, IoRestrictionNone, "\\_SB.GIO0", 0x00, ResourceConsumer, , ) { 91 }
        })
        Return (RBUF)
    }

    Method (RESI, 0, NotSerialized)
    {
        Return (Package () { 0x03, 0x01, 0x01, 0x01, 0x01, 0x06, 0x09, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 })
    }

    Method (ENGS, 1, NotSerialized)
    {
        Return (Package () { 0x00 })
    }
}
