#include "WindowsUtilities.h"

#ifdef BUILD_WINDOWS
#include <Windows.h>
#endif

bool WindowsUtilities::is_running_under_wine()
{
#if BUILD_WINDOWS
    bool HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "wine_get_version") != NULL;

    if (!HasFound)
        HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "proton_get_version") != NULL;
        
    return HasFound;
#else
    return false;
#endif
}
