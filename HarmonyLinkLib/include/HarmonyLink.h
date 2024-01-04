﻿// Copyright (C) 2023  Jordon Brooks

#pragma once

#include "Core.h"

struct battery;

class HARMONYLINKLIB_API HarmonyLink
{
public:
    static void exampleFunction();
    static bool isRunningUnderWine();
    static battery get_battery_status();
};
