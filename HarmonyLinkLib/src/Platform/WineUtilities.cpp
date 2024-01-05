#include "WineUtilities.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <filesystem>
#include "HarmonyLink.h"

#ifdef BUILD_WINDOWS
#include <windows.h>
#endif

FBattery WineUtilities::get_battery_status()
{
    std::string append;
    if (HarmonyLink::get_is_wine())
    {
        append = "Z:";
    }

    FBattery result = {};
    result.has_battery = std::filesystem::exists(append + "/sys/class/power_supply/BAT0");

    // If a battery is present, read more details
    if (result.has_battery) {
        std::ifstream status_file(append + "/sys/class/power_supply/BAT0/status");
        std::string status;
        if (status_file.is_open() && std::getline(status_file, status)) {
            result.is_connected_to_power = (status == "Charging");
        }

        std::ifstream capacity_file(append + "/sys/class/power_supply/BAT0/capacity");
        if (capacity_file.is_open() && std::getline(capacity_file, status)) {
            result.battery_percent = static_cast<uint8_t>(std::stoi(status));
        }
    }

    return result;
}

FOSVerInfo WineUtilities::get_linux_info()
{
    std::string append;
    if (HarmonyLink::get_is_wine())
    {
        append = "Z:";
    }

    FOSVerInfo os_info;
    
    std::ifstream file(append + "/etc/os-release");
    std::unordered_map<FString, FString> hashmap;

    if (file) {
        std::string line;
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

                    hashmap[key] = value;
                }
            }
        }
        file.close();
    }

    // Now you can access the values using the keys:
    os_info.name = hashmap["NAME"];
    os_info.id = hashmap["ID"];
    os_info.version_id = hashmap["VERSION_ID"];
    os_info.version_codename = hashmap["VERSION_CODENAME"];
    os_info.pretty_name = hashmap["PRETTY_NAME"];

    try {
        os_info.version = std::stoi(hashmap["VERSION"].c_str());
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        // Handle the error, perhaps by setting a default value or leaving the field unchanged
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        // Handle the error, perhaps by setting a default value or leaving the field unchanged
    }

    return os_info;
}

bool WineUtilities::detect_wine_presence()
{
#ifdef BUILD_WINDOWS
    std::cout << "Detecting wine...\n";
    bool HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "wine_get_version") != nullptr;

    if (!HasFound)
        HasFound = GetProcAddress(GetModuleHandle("ntdll.dll"), "proton_get_version") != nullptr;
        
    return HasFound;
#else
    return false;
#endif
}
