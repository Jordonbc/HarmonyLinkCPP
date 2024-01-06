// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"
#include "FBattery.h"
#include "FOSVerInfo.h"
#include "Platforms.h"

class HARMONYLINKLIB_API HarmonyLink
{
public:
    static bool get_is_wine();

    static FDevice get_device_info();

    static FOSVerInfo get_os_version();
    
    static FBattery get_battery_status();
};
