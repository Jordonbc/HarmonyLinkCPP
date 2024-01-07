﻿#include "IPlatformUtilities.h"

#include <set>

#include "WineUtilities.h"
#if BUILD_WINDOWS
#include "Windows/WindowsUtilities.h"
#elif BUILD_LINUX
#include "Unix/Linux/LinuxUtilities.h"
#elif BUILD_APPLE
#include "Unix/Mac/MacUtilities.h"
#elif BUILD_UNIX
#include "Unix/Mac/MacUtilities.h"
#endif

static std::shared_ptr<IPlatformUtilities> INSTANCE = nullptr;

std::shared_ptr<IPlatformUtilities>& IPlatformUtilities::GetInstance()
{
    if (!INSTANCE)
    {
#if BUILD_WINDOWS
        INSTANCE = std::make_shared<WindowsUtilities>();
#elif BUILD_LINUX
        INSTANCE = std::make_shared<LinuxUtilities>();
#elif BUILD_APPLE
        INSTANCE = std::make_shared<MacUtilities>();
#elif BUILD_UNIX
        INSTANCE = std::make_shared<UnixUtilities>();
// ... other platform checks
#else
        std::cout << "Platform is not supported.\n"
#endif
    }
    
    return INSTANCE;
}

bool IPlatformUtilities::is_running_under_wine()
{
    return WineUtilities::is_wine_present();
}

bool IPlatformUtilities::is_linux()
{
#ifdef BUILD_LINUX
    return true;
#else
    return is_running_under_wine();
#endif
}

std::shared_ptr<FDevice> IPlatformUtilities::get_device()
{
    FDevice new_device;
    
    if (is_linux())
    {
        new_device.platform = EPlatform::LINUX;
    }
    else
    {
        new_device.platform = EPlatform::WINDOWS;
    }

    const std::shared_ptr<FBattery> battery_status = get_battery_status();

    if (battery_status && !battery_status->has_battery)
    {
        new_device.device = EDevice::DESKTOP;
    }
    else
    {
        new_device.device = EDevice::LAPTOP;
    }

    if (is_steam_deck(new_device)) {
        new_device.device = EDevice::STEAM_DECK;
    }
    return std::make_shared<FDevice>(new_device);
}

// Helper function to check if the device is a Steam Deck
bool IPlatformUtilities::is_steam_deck(const FDevice& device) {

    // Check if the device is already identified as a Steam Deck
    if (device.device == EDevice::STEAM_DECK) {
        return true;
    }

    // Check for Steam Deck by OS version
    if (const std::shared_ptr<FOSVerInfo> version = get_os_version()) {
        if (version->variant_id == "steamdeck" && version->name == "SteamOS") {
            return true;
        }
    } else {
        printf("OS version information not available.\n");
    }

    // Set of known Steam Deck CPU model names
    const std::set<std::string> steam_deck_models = {"amd custom apu 0405" /*, other models... */};

    // Check for Steam Deck by CPU model name
    if (const std::shared_ptr<FCPUInfo> cpu_info = get_cpu_info()) {
        const FString cpu_model_lower = FString::to_lower(cpu_info->Model_Name);
        for (const auto& model : steam_deck_models) {
            if (cpu_model_lower == model) {
                printf("Steam Deck detected by CPU model name.\n");
                return true;
            }
        }
    } else {
        printf("CPU information not available.\n");
    }

    printf("Device is not a Steam Deck.\n");
    
    return false;
}
