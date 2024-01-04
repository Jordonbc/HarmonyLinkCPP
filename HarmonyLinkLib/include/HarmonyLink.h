// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"

struct battery;

class HARMONYLINKLIB_API HarmonyLink
{
public:
    static bool is_running_under_wine();
    static battery get_battery_status();
};
