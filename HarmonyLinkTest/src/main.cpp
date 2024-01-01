// Copyright (C) 2023  Jordon Brooks

#include <iostream>
#include <chrono>
#include <thread>

#include "HarmonyLink.h"

int main()
{
    std::cout << "Hello from exe!" << '\n';
    HarmonyLink::exampleFunction();

    const bool isWine = HarmonyLink::isRunningUnderWine();

    const char* test = isWine ? "is" : "isn't";
    
    std::cout << "This program " << test << " running under wine.\n";

    // Wait for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;
}
