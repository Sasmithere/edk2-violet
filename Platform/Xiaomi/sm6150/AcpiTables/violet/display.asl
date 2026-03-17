
//
// This file contains the ACPI Extensions for Display Adapters
//

// IGC method - panel inverse gamma correction table
Method (PIGC, 2, NotSerialized) {
    Name (RBUF, Buffer() {0x0} )
    Return(RBUF)
}

// PCC method - panel color correction matrix
Method (PPCC, 2, NotSerialized) {
    Name (RBUF, Buffer() {0x0} )
    Return(RBUF)
}

// PGC method - panel gamma correction table
Method (PPGC, 2, NotSerialized) {
    Name (RBUF, Buffer() {0x0} )
    Return(RBUF)
}

// PLUT method - panel lookup table
Method (PLUT, 2, NotSerialized) {
    Name (RBUF, Buffer() {0x0} )
    Return(RBUF)
}
