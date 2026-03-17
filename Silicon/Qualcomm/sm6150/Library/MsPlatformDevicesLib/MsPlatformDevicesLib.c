/** @file
 *MsPlatformDevicesLib  - Device specific library.

Copyright (C) Microsoft Corporation. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>

#include <Protocol/DevicePath.h>

#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/IoLib.h>
#include <Library/MsPlatformDevicesLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
// #include <Library/AslUpdateLib.h>
#include <Library/MemoryMapHelperLib.h>

#include <Configuration/BootDevices.h>
#include <Library/TimerLib.h>
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFISmem.h>
#include <Library/MemProtectLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/scm_sip_interface.h>
#include <Protocol/EFIScm.h>

VOID
EFIAPI
PlatformSetup()
{
    // Under Development
//   EFI_STATUS Status;
//   QCOM_SCM_PROTOCOL *ScmProtocol = NULL;

//   // 1. Broad platform-level unlock for SDCC 
//   DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: Attempting platform-level SDCC unlock...\n"));
//   MemProtectUnprotectRegions();
  

//   // 2. Focused register-level unlock for CQE and ICE via SCM
//   Status = gBS->LocateProtocol(&gQcomScmProtocolGuid, NULL, (VOID **)&ScmProtocol);
//   if (!EFI_ERROR(Status) && ScmProtocol != NULL) {
//     UINT64 Parameters[SCM_MAX_NUM_PARAMETERS] = {0};
//     UINT64 Results[SCM_MAX_NUM_RESULTS] = {0};
    
//     // Corrected SMC64 IDs: SMC64 bit (0x40000000) + Fast Call (0x80000000) = 0xC0000000
//     // SIP Owner (2), Service 12 (0xC)
//     // Primary Commands: 0xC2000C01 (Protect), 0xC2000C1C (Init), 0xC2000C11 (Lock2)
    
//     DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: SCM Protocol found, executing SM6150-specific SDC unlock...\n"));
    
//     /* 
//      * SM6150 SDCC Unlock Sequence:
//      * 1. Cmd 0x1C: SdcInit / Set Host Context (Assign SID to base context)
//      * 2. Cmd 0x1E: Set Enhanced Context (Assign SID to ICE/CQE context)
//      * 3. Cmd 0x1A: SdcCommit (Apply changes)
//      * 
//      * IMPORTANT: x1 = DeviceID (0x10 for SDC1), x2 = StreamID (0x160)
//      */

//     // 1. SdcInit / Set Host Context (Cmd 0x1C)
//     Parameters[0] = 0x10;  // SDC1 Device ID
//     Parameters[1] = 0x160; // SDC1 Stream ID
//     Status = ScmProtocol->ScmSipSysCall(
//       ScmProtocol,
//       0xC2000C1C, //Found in hex in fastboot rom of violet
//       TZ_SYSCALL_CREATE_PARAM_ID_2(TZ_SYSCALL_PARAM_TYPE_VAL, TZ_SYSCALL_PARAM_TYPE_VAL),
//       Parameters,
//       Results
//     );
//     DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: Cmd 0x1C (SdcInit) returned %r\n", Status));

//     MicroSecondDelay(1000);

//     // 2. Set Enhanced Context (Cmd 0x1E)
//     Parameters[0] = 0x10;
//     Parameters[1] = 0x160;
//     Status = ScmProtocol->ScmSipSysCall(
//       ScmProtocol,
//       0xC2000C1E, 
//       TZ_SYSCALL_CREATE_PARAM_ID_2(TZ_SYSCALL_PARAM_TYPE_VAL, TZ_SYSCALL_PARAM_TYPE_VAL),
//       Parameters,
//       Results
//     );
//     DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: Cmd 0x1E (SetEnhanced) returned %r\n", Status));

//     MicroSecondDelay(1000);

//     // 3. SdcCommit (Cmd 0x1A)
//     Parameters[0] = 0x10;
//     Parameters[1] = 1; // Commit = 1
//     Status = ScmProtocol->ScmSipSysCall(
//       ScmProtocol,
//       0xC2000C1A, 
//       TZ_SYSCALL_CREATE_PARAM_ID_2(TZ_SYSCALL_PARAM_TYPE_VAL, TZ_SYSCALL_PARAM_TYPE_VAL),
//       Parameters,
//       Results
//     );
//     DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: Cmd 0x1A (SdcCommit) returned %r\n", Status));

//     if (EFI_ERROR(Status)) {
//       DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: SCM SDCC unlock failed: %r\n", Status));
//     } else {
//       DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: SCM SDCC unlock sequence completed successfully.\n"));
//     }
   
//   } else {
//     DEBUG((EFI_D_ERROR, "MsPlatformDevicesLib: SCM Protocol NOT found!\n"));
   
//   }
}
