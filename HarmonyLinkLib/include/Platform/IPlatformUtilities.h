#pragma once
#include "Battery.h"

class IPlatformUtilities {
public:
    IPlatformUtilities() = default;
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool isRunningUnderWine() = 0;

    virtual battery get_battery_status() = 0;

    // Add more virtual functions for other OS interactions here
};
