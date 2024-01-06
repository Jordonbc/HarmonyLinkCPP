#pragma once

#include "Structs/FBattery.h"
#include "Structs/FDevice.h"
#include "Structs/FOSVerInfo.h"

class IPlatformUtilities {
public:
    static std::shared_ptr<IPlatformUtilities>& GetInstance();

    IPlatformUtilities() = default;
    IPlatformUtilities(const IPlatformUtilities& other) = default;
    IPlatformUtilities(IPlatformUtilities&& other) = default;
    IPlatformUtilities& operator=(const IPlatformUtilities& other) = default;
    IPlatformUtilities& operator=(IPlatformUtilities&& other) = default;

    virtual ~IPlatformUtilities() = default;
    
    // General OS-level functions
    virtual bool is_running_under_wine();
    virtual bool is_linux();
    virtual std::shared_ptr<FDevice> get_device();

    virtual std::shared_ptr<FBattery> get_battery_status() = 0;

    // Modified get_os_version to use caching
    virtual std::shared_ptr<FOSVerInfo> get_os_version() = 0;

    // Add more virtual functions for other OS interactions here
};
