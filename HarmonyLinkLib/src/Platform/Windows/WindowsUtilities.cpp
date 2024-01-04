#include "WindowsUtilities.h"

#include <fstream>
#include <sstream>
#include <unordered_map>
#include <Windows.h>

bool WindowsUtilities::is_running_under_wine()
{
    std::cout << "WINDOWS\n";
    bool HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "wine_get_version") != NULL;

    if (!HasFound)
        HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "proton_get_version") != NULL;
        
    return HasFound;
}

FBattery WindowsUtilities::get_battery_status()
{
    SYSTEM_POWER_STATUS status;
    FBattery result;

    if (GetSystemPowerStatus(&status)) {
        result.has_battery = status.BatteryFlag != 128; // 128 indicates no battery
        result.is_connected_to_power = status.ACLineStatus == 1;
        result.battery_percent = result.has_battery ? status.BatteryLifePercent : 0;
    } else {
        // In case of any error, you may choose to set default values
        result.has_battery = false;
        result.is_connected_to_power = false;
        result.battery_percent = 0;
    }

    return result;
}
