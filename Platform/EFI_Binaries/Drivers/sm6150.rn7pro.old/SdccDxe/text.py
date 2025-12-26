import lief

# Load the EFI binary
binary = lief.parse("SdccDxe.efi")

# Modify Optional Header
opt = binary.optional_header

# Set 64K alignment
opt.subsystem = 0xC
opt.section_alignment = 0x10000
opt.file_alignment    = 0x10000

# Write back patched file
binary.write("SdccDxe_fixed.efi")

