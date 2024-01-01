#include "HarmonyLink.h"
#include <iostream>

#if BUILD_WINDOWS
#include <windows.h>
#endif

void HarmonyLink::exampleFunction()
{
    std::cout << "Hello from HarmonyLink!\n";
}

bool HarmonyLink::isRunningUnderWine()
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
