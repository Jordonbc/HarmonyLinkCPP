#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    bool isRunningUnderWine() override;

    battery get_battery_status() override;
};
