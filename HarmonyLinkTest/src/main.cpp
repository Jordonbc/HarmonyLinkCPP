// Copyright (C) 2023  Jordon Brooks

#include <iostream>
#include <chrono>
#include <thread>

#include "FBattery.h"
#include "HarmonyLink.h"

int main()
{
    std::cout << "Hello from exe!" << '\n';

    const bool isWine = HarmonyLink::get_is_wine();

    const char* test = isWine ? "is" : "isn't";
    
    std::cout << "This program " << test << " running under wine.\n";

    HarmonyLink::get_battery_status().to_string();

    if (isWine)
    {
        const FDistroInfo distro_info = HarmonyLink::get_distro_info();
        printf("Distro Name: %s\n", distro_info.pretty_name.c_str());
    }

    // Wait for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;
}
