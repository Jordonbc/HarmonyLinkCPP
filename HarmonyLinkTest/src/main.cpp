// Copyright (C) 2023  Jordon Brooks

#include <iostream>
#include <chrono>
#include <thread>

#include "..\..\HarmonyLinkLib\include\FBattery.h"
#include "HarmonyLink.h"

int main()
{
    std::cout << "Hello from exe!" << '\n';

    const bool isWine = HarmonyLink::is_running_under_wine();

    const char* test = isWine ? "is" : "isn't";
    
    std::cout << "This program " << test << " running under wine.\n";

    HarmonyLink::get_battery_status().to_string();

    if (isWine)
    {
        HarmonyLink::test_uname();
    }

    // Wait for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;
}
