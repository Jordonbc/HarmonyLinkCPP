#pragma once
#include <cstdint>
#include <iostream>

#include "HarmonyLinkStruct.h"

struct FBattery : HarmonyLinkStruct
{
    bool has_battery;
    bool is_connected_to_ac;
    uint8_t battery_percent;

    void to_string() const {
        std::cout << "Battery present: " << (has_battery ? "'Yes'" : "'No'") << '\n';
        std::cout << "Connected to AC: " << (is_connected_to_ac ? "'Yes'" : "'No'") << '\n';
        std::cout << "Battery percent: '" << static_cast<int>(battery_percent) << "%'" << '\n';
    }
};
