// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"
#include "FBattery.h"
#include "FDistroInfo.h"

class IPlatformUtilities;

class HARMONYLINKLIB_API HarmonyLink
{
public:
    HarmonyLink();
    static bool get_is_wine()
    {
        return is_wine_;
    }

    static FDistroInfo& get_distro_info()
    {
        return distro_info_;
    }
    
    static FBattery get_battery_status();

private:
    inline static bool is_wine_ = false;
    inline static FDistroInfo distro_info_;
};
