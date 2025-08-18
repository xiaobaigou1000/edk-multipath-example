#include <PiPei.h>
#include <Ppi/PiPcdInfo.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Library/PeiServicesLib.h>
#include <Library/PeimEntryPoint.h>

extern EFI_GUID gGetPcdInfoPpiGuid;

EFI_STATUS
EFIAPI NotifyPpiExampleCallback(
    IN EFI_PEI_SERVICES **PeiServices,
    IN EFI_PEI_NOTIFY_DESCRIPTOR *NotifyDescriptor,
    IN VOID *Ppi)
{
    EFI_GET_PCD_INFO_PPI *getPcdInfoPpi = Ppi;
    DEBUG((DEBUG_ERROR,"NotifyPpiExampleCallback\n"));
    UINTN skuId = getPcdInfoPpi->GetSku();
    DEBUG((DEBUG_ERROR,"Platform Sku Id: %d\n",skuId));
    return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
NotifyPpiExamplePeiEntry(
    IN EFI_PEI_FILE_HANDLE FileHandle,
    IN CONST EFI_PEI_SERVICES **PeiServices)
{
    DEBUG((DEBUG_ERROR, "NotifyPpiExamplePeiEntry Begin\n"));

    EFI_PEI_NOTIFY_DESCRIPTOR descriptor = {
        (EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
        &gGetPcdInfoPpiGuid,
        NotifyPpiExampleCallback
    };
    (*PeiServices)->NotifyPpi(PeiServices, &descriptor);
    return EFI_SUCCESS;
}