#include <Uefi.h>

#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/MemoryMapHelperLib.h>
#include <Library/TimerLib.h>
#include <Library/BaseMemoryLib.h>
#include <Protocol/EFIScm.h>
#include <Protocol/scm_sip_interface.h>

#define MAX_DESTINATION_VMS 1
#define ALIGN(x, a)         (((x) + (a) - 1) & ~((a) - 1))

// SM6150 VMIDs (Verify if these are correct for sm6150, common scheme is TZ=1, HYP=2, HLOS=3)
#define AC_VM_TZ         1
#define AC_VM_HYP        2
#define AC_VM_HLOS       3

EFI_STATUS
EFIAPI
ProtectSharedArea(UINT64 efsBaseAddr, UINT64 efsBaseSize, UINT32 sourceVM)
{
  EFI_STATUS             Status                       = EFI_SUCCESS;
  hyp_memprot_ipa_info_t ipaInfo;
  QCOM_SCM_PROTOCOL     *pQcomScmProtocol             = NULL;
  UINT32                 dataSize                     = 0;
  UINT64                 results[SCM_MAX_NUM_RESULTS] = {0};
  VOID                  *data                         = NULL;

  hyp_memprot_dstVM_perm_info_t dstVM_perm_info[MAX_DESTINATION_VMS] = {
    { AC_VM_HLOS, (VM_PERM_R | VM_PERM_W), 0, 0 }
  };

  UINT64                 parameterArray[SCM_MAX_NUM_PARAMETERS] = {0};
  hyp_memprot_assign_t  *assign = (hyp_memprot_assign_t *)parameterArray;

  Status = gBS->LocateProtocol(&gQcomScmProtocolGuid, NULL, (VOID **)&pQcomScmProtocol);
  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "MemProtectLib: Failed to locate SCM Protocol! %r\n", Status));
    return Status;
  }

  ipaInfo.IPAaddr = efsBaseAddr;
  ipaInfo.IPAsize = efsBaseSize;

  // Aligning buffers to 64 bytes is often required for Secure World access
  UINT32 IpaInfoSzAligned  = ALIGN(sizeof(hyp_memprot_ipa_info_t), 64);
  UINT32 sourceVMSzAligned = ALIGN(sizeof(UINT32), 64);
  UINT32 destVMSzAligned   = ALIGN(MAX_DESTINATION_VMS * sizeof(hyp_memprot_dstVM_perm_info_t), 64);
  dataSize = IpaInfoSzAligned + sourceVMSzAligned + destVMSzAligned;

  data = AllocateZeroPool(dataSize + 64);
  if (data == NULL) return EFI_OUT_OF_RESOURCES;

  UINT64 alignedBase = ALIGN((UINT64)data, 64);
  
  // 1. IPA list
  assign->IPAinfolist = alignedBase;
  CopyMem((VOID *)assign->IPAinfolist, &ipaInfo, sizeof(hyp_memprot_ipa_info_t));
  assign->IPAinfolistsize = sizeof(hyp_memprot_ipa_info_t);

  // 2. Source VM list
  assign->sourceVMlist = alignedBase + IpaInfoSzAligned;
  CopyMem((VOID *)assign->sourceVMlist, &sourceVM, sizeof(sourceVM));
  assign->srcVMlistsize = sizeof(sourceVM);

  // 3. Destination VM list with permissions
  assign->destVMlist = alignedBase + IpaInfoSzAligned + sourceVMSzAligned;
  CopyMem((VOID *)assign->destVMlist, dstVM_perm_info, MAX_DESTINATION_VMS * sizeof(hyp_memprot_dstVM_perm_info_t));
  assign->destVMlistsize = MAX_DESTINATION_VMS * sizeof(hyp_memprot_dstVM_perm_info_t);

  assign->spare = 0;

  Status = pQcomScmProtocol->ScmSipSysCall(
      pQcomScmProtocol, 
      HYP_MEM_PROTECT_ASSIGN, 
      HYP_MEM_PROTECT_ASSIGN_PARAM_ID, 
      parameterArray, 
      results
  );

  if (data != NULL) FreePool(data);
  return Status;
}

EFI_STATUS
EFIAPI
MemProtectUnprotectRegions(VOID)
{
  EFI_STATUS Status = EFI_SUCCESS;
  
 // Under Development;

  return Status;
}
