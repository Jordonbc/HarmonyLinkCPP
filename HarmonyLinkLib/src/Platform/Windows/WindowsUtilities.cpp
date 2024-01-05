#include "WindowsUtilities.h"

#include <sstream>
#include <Windows.h>

WindowsUtilities::WindowsUtilities()
{
    is_wine_ = detect_wine_presence();
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

FOSInfo WindowsUtilities::get_os_release()
{
    if (is_wine_)
    {
        return get_os_info("Z:/etc/os-release");
    }

    FOSInfo os_info;
    OSVERSIONINFOEX OSVersionInfo;
    ZeroMemory(&OSVersionInfo, sizeof(OSVERSIONINFOEX));
    OSVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!GetVersionEx((OSVERSIONINFO *)&OSVersionInfo)) {
        // Handle error if needed
        return os_info;
    }

    HKEY h_key;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"), 0, KEY_READ, &h_key) == ERROR_SUCCESS)
    {
        DWORD dwSize;
        DWORD dwType;
        char szProductName[256];
        dwSize = sizeof(szProductName);
        if (RegQueryValueEx(h_key, TEXT("ProductName"), nullptr, &dwType, reinterpret_cast<LPBYTE>(szProductName), &dwSize) == ERROR_SUCCESS)
        {
            os_info.pretty_name = szProductName;
        }
        RegCloseKey(h_key);
    }

    std::stringstream version;
    version << OSVersionInfo.dwMajorVersion << "." << OSVersionInfo.dwMinorVersion;
    os_info.version_id = version.str();

    os_info.name = "Windows";
    os_info.version = OSVersionInfo.dwBuildNumber; // Build number as the version

    return os_info;
}

bool WindowsUtilities::detect_wine_presence()
{
    std::cout << "Detecting wine...\n";
    bool HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "wine_get_version") != NULL;

    if (!HasFound)
        HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "proton_get_version") != NULL;
        
    return HasFound;
}
