#pragma once
#include "FBattery.h"

#include "FOSVerInfo.h"
#include "Platforms.h"

class IPlatformUtilities {
public:
    IPlatformUtilities();
    virtual void Init();
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool is_running_under_wine()
    {
        return cached_is_wine_;
    }

    virtual bool is_linux()
    {
        return cached_is_wine_;
    }

    std::shared_ptr<FBattery> get_battery_status()
    {
        return fetch_battery_status();
    }

    std::shared_ptr<FDevice> get_device()
    {
        if (!cached_device_) {
            cached_device_ = fetch_device();
        }
        
        return cached_device_;
    }

    // Modified get_os_version to use caching
    std::shared_ptr<FOSVerInfo> get_os_version()
    {
        if (!cached_os_version_) {
            cached_os_version_ = fetch_os_version();
        }
        
        return cached_os_version_;
    }

    bool is_initialised() const
    {
        return Initialised;
    }

    // Add more virtual functions for other OS interactions here
protected:
    virtual std::shared_ptr<FOSVerInfo> fetch_os_version() = 0;
    virtual std::shared_ptr<FBattery> fetch_battery_status() = 0;
    virtual std::shared_ptr<FDevice> fetch_device();
    
    std::shared_ptr<FOSVerInfo> cached_os_version_;
    std::shared_ptr<FDevice> cached_device_;
    bool cached_is_wine_ = false;

private:
    bool Initialised = false;
};
