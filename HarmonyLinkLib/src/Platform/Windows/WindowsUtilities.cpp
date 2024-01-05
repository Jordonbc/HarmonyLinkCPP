#include "WindowsUtilities.h"

#include <sstream>
#include <Windows.h>

#include "Platform/WineUtilities.h"

WindowsUtilities::WindowsUtilities()
{
    is_wine_ = WineUtilities::detect_wine_presence();
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

FOSVerInfo WindowsUtilities::get_os_version()
{
    if (is_wine_)
    {
        return WineUtilities::get_linux_info();
    }

    FOSVerInfo os_version;
    OSVERSIONINFOEX os_version_info;
    ZeroMemory(&os_version_info, sizeof(OSVERSIONINFOEX));
    os_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!GetVersionEx((OSVERSIONINFO *)&os_version_info)) {
        // Handle error if needed
        return os_version;
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
            os_version.pretty_name = szProductName;
        }
        RegCloseKey(h_key);
    }

    std::stringstream version;
    version << os_version_info.dwMajorVersion << "." << os_version_info.dwMinorVersion;
    os_version.version_id = version.str();

    os_version.name = "Windows";
    os_version.version = os_version_info.dwBuildNumber; // Build number as the version

    return os_version;
}
