#!/bin/bash
set -e

# Toolchain setup (LLVM)
CC="clang --target=aarch64-linux-gnu"
LD=ld.lld
OBJCOPY=aarch64-linux-gnu-objcopy

# Workspace roots
WORKSPACE=$(pwd)/boot_images
QCOM_PKG=$WORKSPACE/QcomPkg
MDE_PKG=$WORKSPACE/MdePkg
ARM_PKG=$WORKSPACE/ArmPkg

# Output dir
mkdir -p Build_Manual

# Include paths
INCLUDES="-I. \
    -I$QCOM_PKG \
    -I$QCOM_PKG/Include \
    -I$QCOM_PKG/Include/Library \
    -I$QCOM_PKG/Include/api/dal \
    -I$QCOM_PKG/Include/api/systemdrivers \
    -I$QCOM_PKG/Include/api/storage \
    -I$QCOM_PKG/Library/MuslLib/musl/arch/aarch64 \
    -I$QCOM_PKG/Library/MuslLib/musl/include \
    -I$QCOM_PKG/SDM670Pkg/Include \
    -I$MDE_PKG/Include \
    -I$MDE_PKG/Include/AArch64 \
    -I$ARM_PKG/Include \
    -I$MDE_PKG/Library/BaseLib \
    -I$WORKSPACE/EmbeddedPkg/Include"

# Compilation Flags (UEFI Standard + Aarch64)
# Removed -mcmodel=large to fix "code model 'large' with '-fPIC'" error
# Added -fPIC explicitly although it's often default on aarch64
COMMON_FLAGS="-g -O2 -Wall -Wextra -Wno-unused-parameter -Wno-missing-braces \
    -fshort-wchar -fno-strict-aliasing -fno-stack-protector \
    -fno-builtin -ffreestanding -fno-common \
    -mstrict-align -fPIC \
    -D__STDC_USE_IEC_60559_BFP_ER__ -D__STDC_USE_IEC_60559_FUNCS_ER__ -D__STDC_USE_IEC_60559_TYPES_ER__ \
    -DDE_CPU_AARCH64 -DAARCH64 -DGNU_EFI_USE_MS_ABI \
    -DgEfiCallerBaseName="\"SdccDxe\"" \
    $INCLUDES"

CFLAGS="$COMMON_FLAGS -include $MDE_PKG/Include/Uefi.h -include ManualPcd.h -Wno-unused-function"
ASMFLAGS="$COMMON_FLAGS -include AsmMacros.h -include ManualPcd.h"



echo "Compiling SdccDxe..."
$CC $CFLAGS -c SdccDxe.c -o Build_Manual/SdccDxe.o
$CC $CFLAGS -c SdccBlockIO2.c -o Build_Manual/SdccBlockIO2.o

echo "Compiling SdccHalLib..."
# Source: QcomPkg/Library/SdccCommonLib/SdccHalLib/HALsdcc_sdcc5.c
$CC $CFLAGS -c $QCOM_PKG/Library/SdccCommonLib/SdccHalLib/HALsdcc_sdcc5.c -o Build_Manual/HALsdcc_sdcc5.o

echo "Compiling SdccCommonLib..."
# Sources from SdccCommonLib.inf
COMMON_SRC="$QCOM_PKG/Library/SdccCommonLib"
$CC $CFLAGS -c $COMMON_SRC/sdcc_pal_tool.c -o Build_Manual/sdcc_pal_tool.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_util.c -o Build_Manual/sdcc_util.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_mini_api.c -o Build_Manual/sdcc_mini_api.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_sd_util.c -o Build_Manual/sdcc_sd_util.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_mmc_util.c -o Build_Manual/sdcc_mmc_util.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_handle_util.c -o Build_Manual/sdcc_handle_util.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_hc.c -o Build_Manual/sdcc_hc.o
$CC $CFLAGS -c $COMMON_SRC/sdcc_rpmb_util.c -o Build_Manual/sdcc_rpmb_util.o

echo "Compiling DALFwkLib..."
# Sources from DALFwkLib.inf
DAL_SRC="$QCOM_PKG/Library/DALFwkLib"
$CC $CFLAGS -c $DAL_SRC/DALQueue.c -o Build_Manual/DALQueue.o
$CC $CFLAGS -c $DAL_SRC/dal_asm_wrap.c -o Build_Manual/dal_asm_wrap.o
$CC $CFLAGS -c $DAL_SRC/dalfwkbase.c -o Build_Manual/dalfwkbase.o

echo "Compiling BaseLib..."
BASE_SRC="$MDE_PKG/Library/BaseLib"
$CC $CFLAGS -c $BASE_SRC/CheckSum.c -o Build_Manual/CheckSum.o
$CC $CFLAGS -c $BASE_SRC/SwitchStack.c -o Build_Manual/SwitchStack.o
$CC $CFLAGS -c $BASE_SRC/SwapBytes64.c -o Build_Manual/SwapBytes64.o
$CC $CFLAGS -c $BASE_SRC/SwapBytes32.c -o Build_Manual/SwapBytes32.o
$CC $CFLAGS -c $BASE_SRC/SwapBytes16.c -o Build_Manual/SwapBytes16.o
$CC $CFLAGS -c $BASE_SRC/LongJump.c -o Build_Manual/LongJump.o
$CC $CFLAGS -c $BASE_SRC/SetJump.c -o Build_Manual/SetJump.o
$CC $CFLAGS -c $BASE_SRC/RShiftU64.c -o Build_Manual/RShiftU64.o
$CC $CFLAGS -c $BASE_SRC/RRotU64.c -o Build_Manual/RRotU64.o
$CC $CFLAGS -c $BASE_SRC/RRotU32.c -o Build_Manual/RRotU32.o
$CC $CFLAGS -c $BASE_SRC/MultU64x64.c -o Build_Manual/MultU64x64.o
$CC $CFLAGS -c $BASE_SRC/MultU64x32.c -o Build_Manual/MultU64x32.o
$CC $CFLAGS -c $BASE_SRC/MultS64x64.c -o Build_Manual/MultS64x64.o
$CC $CFLAGS -c $BASE_SRC/ModU64x32.c -o Build_Manual/ModU64x32.o
$CC $CFLAGS -c $BASE_SRC/LShiftU64.c -o Build_Manual/LShiftU64.o
$CC $CFLAGS -c $BASE_SRC/LRotU64.c -o Build_Manual/LRotU64.o
$CC $CFLAGS -c $BASE_SRC/LRotU32.c -o Build_Manual/LRotU32.o
$CC $CFLAGS -c $BASE_SRC/LowBitSet64.c -o Build_Manual/LowBitSet64.o
$CC $CFLAGS -c $BASE_SRC/LowBitSet32.c -o Build_Manual/LowBitSet32.o
$CC $CFLAGS -c $BASE_SRC/HighBitSet64.c -o Build_Manual/HighBitSet64.o
$CC $CFLAGS -c $BASE_SRC/HighBitSet32.c -o Build_Manual/HighBitSet32.o
$CC $CFLAGS -c $BASE_SRC/GetPowerOfTwo64.c -o Build_Manual/GetPowerOfTwo64.o
$CC $CFLAGS -c $BASE_SRC/GetPowerOfTwo32.c -o Build_Manual/GetPowerOfTwo32.o
$CC $CFLAGS -c $BASE_SRC/DivU64x64Remainder.c -o Build_Manual/DivU64x64Remainder.o
$CC $CFLAGS -c $BASE_SRC/DivU64x32Remainder.c -o Build_Manual/DivU64x32Remainder.o
$CC $CFLAGS -c $BASE_SRC/DivU64x32.c -o Build_Manual/DivU64x32.o
$CC $CFLAGS -c $BASE_SRC/DivS64x64Remainder.c -o Build_Manual/DivS64x64Remainder.o
$CC $CFLAGS -c $BASE_SRC/ARShiftU64.c -o Build_Manual/ARShiftU64.o
$CC $CFLAGS -c $BASE_SRC/BitField.c -o Build_Manual/BitField.o
$CC $CFLAGS -c $BASE_SRC/CpuDeadLoop.c -o Build_Manual/CpuDeadLoop.o
$CC $CFLAGS -c $BASE_SRC/Cpu.c -o Build_Manual/Cpu.o
$CC $CFLAGS -c $BASE_SRC/LinkedList.c -o Build_Manual/LinkedList.o
$CC $CFLAGS -c $BASE_SRC/SafeString.c -o Build_Manual/SafeString.o
$CC $CFLAGS -c $BASE_SRC/String.c -o Build_Manual/String.o
$CC $CFLAGS -c $BASE_SRC/FilePaths.c -o Build_Manual/FilePaths.o
$CC $CFLAGS -c $BASE_SRC/Math64.c -o Build_Manual/Math64.o
$CC $CFLAGS -c $BASE_SRC/Arm/Unaligned.c -o Build_Manual/Unaligned.o

echo "Compiling BaseLib ASM (AArch64)..."
BASE_ASM="$MDE_PKG/Library/BaseLib/AArch64"
$CC $ASMFLAGS -c $BASE_ASM/CpuBreakpoint.S -o Build_Manual/CpuBreakpoint.o
$CC $ASMFLAGS -c $BASE_ASM/DisableInterrupts.S -o Build_Manual/DisableInterrupts.o
$CC $ASMFLAGS -c $BASE_ASM/EnableInterrupts.S -o Build_Manual/EnableInterrupts.o
$CC $ASMFLAGS -c $BASE_ASM/GetInterruptsState.S -o Build_Manual/GetInterruptsState.o
$CC $ASMFLAGS -c $BASE_ASM/MemoryFence.S -o Build_Manual/MemoryFence.o
$CC $ASMFLAGS -c $BASE_ASM/SetJumpLongJump.S -o Build_Manual/SetJumpLongJump.o
$CC $ASMFLAGS -c $BASE_ASM/SwitchStack.S -o Build_Manual/SwitchStack.o

echo "Compiling PrintLib..."
PRINT_SRC="$MDE_PKG/Library/BasePrintLib"
$CC $CFLAGS -c $PRINT_SRC/PrintLibInternal.c -o Build_Manual/PrintLibInternal.o
$CC $CFLAGS -c $PRINT_SRC/PrintLib.c -o Build_Manual/PrintLib.o

echo "Compiling SerialPortLib (BaseSerialPortLibNull)..."
SP_SRC="$MDE_PKG/Library/BaseSerialPortLibNull"
$CC $CFLAGS -c $SP_SRC/BaseSerialPortLibNull.c -o Build_Manual/BaseSerialPortLibNull.o

echo "Compiling DebugLib (fake_debug_lib)..."
$CC $CFLAGS -c fake_debug_lib.c -o Build_Manual/DebugLib.o

echo "Compiling UefiLib..."
UEFI_SRC="$MDE_PKG/Library/UefiLib"
$CC $CFLAGS -c $UEFI_SRC/UefiLibPrint.c -o Build_Manual/UefiLibPrint.o
$CC $CFLAGS -c $UEFI_SRC/UefiNotTiano.c -o Build_Manual/UefiNotTiano.o
$CC $CFLAGS -c $UEFI_SRC/UefiDriverModel.c -o Build_Manual/UefiDriverModel.o
$CC $CFLAGS -c $UEFI_SRC/Console.c -o Build_Manual/Console.o
$CC $CFLAGS -c $UEFI_SRC/UefiLib.c -o Build_Manual/UefiLib.o

echo "Compiling UefiBootServicesTableLib..."
BS_SRC="$MDE_PKG/Library/UefiBootServicesTableLib"
$CC $CFLAGS -c $BS_SRC/UefiBootServicesTableLib.c -o Build_Manual/UefiBootServicesTableLib.o

echo "Compiling UefiMemoryAllocationLib..."
MEM_SRC="$MDE_PKG/Library/UefiMemoryAllocationLib"
$CC $CFLAGS -c $MEM_SRC/MemoryAllocationLib.c -o Build_Manual/MemoryAllocationLib.o

echo "Compiling UefiDevicePathLib..."
DP_SRC="$MDE_PKG/Library/UefiDevicePathLib"
$CC $CFLAGS -c $DP_SRC/DevicePathUtilities.c -o Build_Manual/DevicePathUtilities.o
$CC $CFLAGS -c $DP_SRC/DevicePathToText.c -o Build_Manual/DevicePathToText.o
$CC $CFLAGS -c $DP_SRC/DevicePathFromText.c -o Build_Manual/DevicePathFromText.o
$CC $CFLAGS -c $DP_SRC/UefiDevicePathLib.c -o Build_Manual/UefiDevicePathLib.o

echo "Compiling BootConfigLib..."
BC_SRC="$QCOM_PKG/SDM670Pkg/Library/BootConfigLib"
$CC $CFLAGS -c $BC_SRC/boot_config_670.c -o Build_Manual/boot_config_670.o

echo "Compiling VioletBspLib..."
$CC $CFLAGS -c VioletBspLib.c -o Build_Manual/VioletBspLib.o

echo "Linking..."
rm -f Build_Manual/SdccDxe_Combined.o
$LD -shared -Bsymbolic -o Build_Manual/SdccDxe.dll.so Build_Manual/*.o

echo "Creating .efi..."
$OBJCOPY -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel \
    -j .rela -j .rel.* -j .rela.* -j .rel* -j .rela* \
    -j .reloc --target efi-app-aarch64 Build_Manual/SdccDxe.dll.so Build_Manual/SdccDxe.efi

echo "Done. efi file created at Build_Manual/SdccDxe.efi"
