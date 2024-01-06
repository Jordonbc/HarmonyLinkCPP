#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    void Init() override;
    bool is_running_under_wine() override
    {
        return cached_is_wine_;
    }
    
    std::shared_ptr<FBattery> fetch_battery_status() override;
    
    std::shared_ptr<FOSVerInfo> fetch_os_version() override;
};
