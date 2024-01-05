#pragma once
#include "FBattery.h"

#include "FOSVerInfo.h"

class IPlatformUtilities {
public:
    IPlatformUtilities();
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool is_running_under_wine() = 0;

    virtual FBattery get_battery_status() = 0;

    virtual FOSVerInfo get_os_version() = 0;

    // Add more virtual functions for other OS interactions here
};
