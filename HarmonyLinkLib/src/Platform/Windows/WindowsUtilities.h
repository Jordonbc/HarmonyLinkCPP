#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    bool is_running_under_wine() override;
    FBattery get_battery_status() override;
    FDistroInfo get_os_release() override;
};
