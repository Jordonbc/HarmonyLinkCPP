#pragma once
#include "FBattery.h"
#include "FDistroInfo.h"

class IPlatformUtilities {
public:
    IPlatformUtilities() = default;
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool is_running_under_wine() = 0;

    virtual FBattery get_battery_status() = 0;

    virtual FDistroInfo get_os_release() = 0;

    // Add more virtual functions for other OS interactions here
};
