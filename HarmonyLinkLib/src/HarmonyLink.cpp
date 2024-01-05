#include "HarmonyLink.h"
#include <iostream>

#include "Platform/IPlatformUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"

static std::shared_ptr<IPlatformUtilities> PlatformUtilities = nullptr;

bool HarmonyLink::get_is_wine()
{
    if (!PlatformUtilities)
    {
        PlatformUtilities = PlatformUtilitiesHelper::GetInstance()->get_platform_utility();
    }

    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return false;
    }

    return PlatformUtilities->is_running_under_wine();
}

FOSVerInfo HarmonyLink::get_os_version()
{
    FOSVerInfo NewOSInfo = FOSVerInfo();
    if (!PlatformUtilities)
    {
        PlatformUtilities = PlatformUtilitiesHelper::GetInstance()->get_platform_utility();
    }

    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return NewOSInfo;
    }

    return PlatformUtilities->get_os_version();
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
