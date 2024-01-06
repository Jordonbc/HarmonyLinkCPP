// Copyright (C) 2023  Jordon Brooks

#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

#include "FBattery.h"
#include "FOSVerInfo.h"
#include "HarmonyLink.h"

// Include necessary headers for platform-specific functionality
#ifdef BUILD_WINDOWS
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For system("cls")
#else
#include <unistd.h> // For read()
#include <termios.h> // For termios
#include <stdio.h> // For getchar()
#include <fcntl.h> // For F_GETFL, F_SETFL and O_NONBLOCK
#endif

std::atomic<bool> quitFlag(false);

// Function to clear the screen cross-platform
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}


// Function to check if 'q' or 'Q' is pressed in Windows
void checkForQuit() {
    while (!quitFlag) {
#ifdef BUILD_WINDOWS
        if (_kbhit()) {
            char c = _getch();
            if (c == 'q' || c == 'Q') {
                quitFlag = true;
                break;
            }
        }
#else
        struct termios oldt, newt;
        int ch;
        int oldf;
        
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        
        ch = getchar();
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        
        if (ch != EOF) {
            ungetc(ch, stdin);
            if (ch == 'q' || ch == 'Q') {
                quitFlag = true;
                break;
            }
        }
#endif
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}


int main()
{
    std::cout << "Hello, World!" << '\n';

    std::thread inputThread(checkForQuit);

    // This loop is to test how stable & expensive these functions are
    while (!quitFlag)
    {
        // Clear the screen
        clearScreen();

        const bool isWine = HarmonyLink::get_is_wine();

        const char* test = isWine ? "is" : "isn't";
    
        std::cout << "This program " << test << " running under wine.\n";

        HarmonyLink::get_battery_status().to_string();
    
        const FOSVerInfo distro_info = HarmonyLink::get_os_version();
        distro_info.print();
        //printf("pretty_name: %s\n", distro_info.pretty_name.c_str());

        const FDevice device_info = HarmonyLink::get_device_info();

        printf("Is SteamDeck: %s\n", device_info.device == EDevice::STEAM_DECK ? "true" : "false");

        // Wait for 100 milisecods
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    if (inputThread.joinable())
    {
        inputThread.join();
    }
    
    return 0;
}
