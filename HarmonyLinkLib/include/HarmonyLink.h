// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"
#include "FBattery.h"
#include "FOSVerInfo.h"

class IPlatformUtilities;

class HARMONYLINKLIB_API HarmonyLink
{
public:
    static bool get_is_wine();

    static FOSVerInfo get_os_version();
    
    static FBattery get_battery_status();
};
