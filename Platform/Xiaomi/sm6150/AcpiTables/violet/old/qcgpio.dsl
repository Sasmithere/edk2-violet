Device (GIO0)
{
    Name (_HID, "QCOM0217")  // Keep for SM6150 TLMM
    Alias(\_SB.PSUB, _SUB)
    Name (_UID, 0)

    Method (_CRS, 0x0, NotSerialized) {
        Name (RBUF, ResourceTemplate ()
        {
            // TLMM register address space (matches DTS reg=0x3400000? Wait, DSL has 0x00400000; adjusted base for violet)
            Memory32Fixed (ReadWrite, 0x03400000, 0x00C00000)  // Updated base from 0x00400000 to match SM6150 TLMM 0x3400000-0x3ffffff

            // Summary Interrupt shared by all banks (matches DTS)
            Interrupt(ResourceConsumer, Level, ActiveHigh, Shared, , , ) {240}
            Interrupt(ResourceConsumer, Level, ActiveHigh, Shared, , , ) {240}
            Interrupt(ResourceConsumer, Level, ActiveHigh, Shared, , , ) {240}
            Interrupt(ResourceConsumer, Edge, ActiveBoth, Shared, , , ) {648} // For PDC Wake up ::TLMM GPIO 126 SD Card Detection (matches DTS)
            Interrupt(ResourceConsumer, Edge, ActiveBoth, Shared, , , ) {568} // For PDC Wake up ::TLMM GPIO 54 
            Interrupt(ResourceConsumer, Edge, ActiveBoth, Shared, , , ) {646} // For PDC Wake up ::TLMM GPIO 124, Hall sensor (keep, violet may not have hall)
        })
        Return (RBUF)
    }
	// ACPI method to return Num pins
	Method(OFNI, 0x0, NotSerialized) {
		Name(RBUF, Buffer()
		{
			0x96,  // 0: TOTAL_GPIO_PINS
			0x00   // 1: TOTAL_GPIO_PINS
		})
		Return (RBUF)
	}
	
	Name(GABL, Zero)
	Method(_REG, 0x2, NotSerialized)
	{
		If(LEqual(Arg0, 0x8))
		{
			Store(Arg1, GABL)
		}
	} 
}
