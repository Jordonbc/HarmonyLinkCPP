#pragma once
#include <cstdint>

struct battery
{
    bool has_battery;
    bool is_connected_to_power;
    uint8_t battery_percent;
};
