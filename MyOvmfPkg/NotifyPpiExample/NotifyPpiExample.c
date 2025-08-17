#include <PiPei.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Library/PeiServicesLib.h>
#include <Library/PeimEntryPoint.h>

EFI_STATUS
EFIAPI
NotifyPpiExamplePeiEntry(
    IN EFI_PEI_FILE_HANDLE FileHandle,
    IN CONST EFI_PEI_SERVICES **PeiServices)
{
    DEBUG((DEBUG_ERROR,"NotifyPpiExamplePeiEntry Begin\n"));
    return EFI_SUCCESS;
}