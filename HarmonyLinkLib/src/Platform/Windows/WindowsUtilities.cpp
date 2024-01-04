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

FDistroInfo WindowsUtilities::get_os_release()
{
    std::ifstream file("Z:/etc/os-release");
    FDistroInfo distroInfo;
    std::string line;


    std::unordered_map<std::string, std::string> keyToValueMap;

    if (file) {
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string key, value;
            if (std::getline(lineStream, key, '=')) {
                if (std::getline(lineStream, value)) {
                    // Remove leading and trailing whitespace
                    size_t firstNonSpace = value.find_first_not_of(" \t");
                    size_t lastNonSpace = value.find_last_not_of(" \t");
                    if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
                        value = value.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
                    } else {
                        value.clear(); // If value is all whitespace, make it empty
                    }

                    // Check for double quotes and remove them
                    if (!value.empty() && value.front() == '"' && value.back() == '"') {
                        value = value.substr(1, value.length() - 2);
                    }

                    keyToValueMap[key] = value;
                }
            }
        }
        file.close();
    }

    // Now you can access the values using the keys:
    distroInfo.name = keyToValueMap["NAME"];
    distroInfo.version = keyToValueMap["VERSION"];
    distroInfo.id = keyToValueMap["ID"];
    distroInfo.version_id = keyToValueMap["VERSION_ID"];
    distroInfo.version_codename = keyToValueMap["VERSION_CODENAME"];
    distroInfo.pretty_name = keyToValueMap["PRETTY_NAME"];

    return distroInfo;
}
