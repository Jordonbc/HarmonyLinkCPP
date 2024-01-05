#pragma once
#include "FBattery.h"
#include <unordered_map>

#include "FOSInfo.h"
#include "FString.h"

class IPlatformUtilities {
public:
    IPlatformUtilities();
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool is_running_under_wine() = 0;

    virtual FBattery get_battery_status() = 0;

    virtual FOSInfo get_os_release() = 0;

protected:
    static FOSInfo get_os_info(const std::string& file_location);

    // Add more virtual functions for other OS interactions here
};
