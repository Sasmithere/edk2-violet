
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PrintLib.h>
#include <Uefi.h>

// Stub implementation

VOID EFIAPI DebugPrint(IN UINTN ErrorLevel, IN CONST CHAR8 *Format, ...) {}

VOID EFIAPI DebugAssert(IN CONST CHAR8 *FileName, IN UINTN LineNumber,
                        IN CONST CHAR8 *Description) {
  CpuDeadLoop();
}

VOID *EFIAPI DebugClearMemory(OUT VOID *Buffer, IN UINTN Length) {
  return SetMem(Buffer, Length, 0xAF);
}

BOOLEAN
EFIAPI
DebugAssertEnabled(VOID) { return FALSE; }

BOOLEAN
EFIAPI
DebugPrintEnabled(VOID) { return FALSE; }

BOOLEAN
EFIAPI
DebugCodeEnabled(VOID) { return FALSE; }

BOOLEAN
EFIAPI
DebugClearMemoryEnabled(VOID) { return FALSE; }

BOOLEAN
EFIAPI
DebugPrintLevelEnabled(IN CONST UINTN ErrorLevel) { return FALSE; }
