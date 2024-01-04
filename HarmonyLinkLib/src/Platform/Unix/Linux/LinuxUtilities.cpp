#include "LinuxUtilities.h"

#include <filesystem>
#include <fstream>
#include <string>

FBattery LinuxUtilities::get_battery_status()
{
    FBattery result = {};
    result.has_battery = std::filesystem::exists("/sys/class/power_supply/BAT0");

    // If a battery is present, read more details
    if (result.has_battery) {
        std::ifstream status_file("/sys/class/power_supply/BAT0/status");
        std::string status;
        if (status_file.is_open() && std::getline(status_file, status)) {
            result.is_connected_to_power = (status == "Charging");
        }

        std::ifstream capacity_file("/sys/class/power_supply/BAT0/capacity");
        if (capacity_file.is_open() && std::getline(capacity_file, status)) {
            result.battery_percent = static_cast<uint8_t>(std::stoi(status));
        }
    }

    return result;
}
