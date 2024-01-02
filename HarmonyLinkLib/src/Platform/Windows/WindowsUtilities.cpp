#include "WindowsUtilities.h"

#ifdef BUILD_WINDOWS
#include <Windows.h>
#endif

bool WindowsUtilities::isRunningUnderWine()
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

battery WindowsUtilities::get_battery_status()
{
    SYSTEM_POWER_STATUS status;
    battery result;

    if (GetSystemPowerStatus(&status)) {
        result.has_battery = status.BatteryFlag != 128; // 128 indicates no battery
        result.is_connected_to_power = status.ACLineStatus == 1;
        result.battery_percent = status.BatteryLifePercent;
    } else {
        // In case of any error, you may choose to set default values
        result.has_battery = false;
        result.is_connected_to_power = false;
        result.battery_percent = 0;
    }

    return result;
}
