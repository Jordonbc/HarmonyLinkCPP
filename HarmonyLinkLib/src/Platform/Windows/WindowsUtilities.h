#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    std::shared_ptr<FBattery> get_battery_status() override;
    
    std::shared_ptr<FOSVerInfo> get_os_version() override;
};
