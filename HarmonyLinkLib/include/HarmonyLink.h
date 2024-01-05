// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"
#include "FBattery.h"
#include "FOSInfo.h"
#include "FString.h"

class IPlatformUtilities;

class HARMONYLINKLIB_API HarmonyLink
{
public:
    static bool get_is_wine();

    static FOSInfo get_os_info();
    
    static FBattery get_battery_status();
};
