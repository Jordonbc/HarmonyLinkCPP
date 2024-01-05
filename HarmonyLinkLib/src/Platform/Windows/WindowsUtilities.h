#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    WindowsUtilities();
    bool is_running_under_wine() override
    {
        return is_wine_;
    }
    
    FBattery get_battery_status() override;
    
    FOSVerInfo get_os_version() override;
protected:
    inline static bool is_wine_ = false;
};
