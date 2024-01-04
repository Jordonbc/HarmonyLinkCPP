#pragma once
#include <cstdint>
#include <iostream>

struct battery
{
    bool has_battery;
    bool is_connected_to_power;
    uint8_t battery_percent;

    void to_string() const {
        std::cout << "Battery present: " << (has_battery ? "Yes" : "No") << std::endl;
        std::cout << "Connected to power: " << (is_connected_to_power ? "Yes" : "No") << std::endl;
        std::cout << "Battery percent: " << static_cast<int>(battery_percent) << "%" << std::endl;
    }
};
