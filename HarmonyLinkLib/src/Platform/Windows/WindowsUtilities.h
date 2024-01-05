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
    
    FOSInfo get_os_release() override;
protected:
    bool is_wine_ = false;

    static bool detect_wine_presence();
};
