#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    bool is_running_under_wine() override;

    battery get_battery_status() override;
};
