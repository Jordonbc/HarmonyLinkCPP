#include "HarmonyLink.h"
#include <iostream>

#include "Platform/IPlatformUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"

static std::shared_ptr<IPlatformUtilities> PlatformUtilities = nullptr;

HarmonyLink::HarmonyLink()
{
    PlatformUtilities = PlatformUtilitiesHelper::GetInstance()->get_platform_utility();

    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return;
    }

    is_wine_ = PlatformUtilities->is_running_under_wine();
    distro_info_ = PlatformUtilities->get_os_release();
}

FBattery HarmonyLink::get_battery_status()
{
    FBattery battery = FBattery();
    
    if (PlatformUtilities)
    {
        battery = PlatformUtilities->get_battery_status();
    }

    return battery;
}
