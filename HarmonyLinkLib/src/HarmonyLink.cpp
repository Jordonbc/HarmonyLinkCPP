#include "HarmonyLink.h"

#include <iostream>
#include "Platform/IPlatformUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"

static std::shared_ptr<IPlatformUtilities> PlatformUtilities = PlatformUtilitiesHelper::get_platform_utility();

bool HarmonyLink::get_is_wine()
{
    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return false;
    }

    return PlatformUtilities->is_running_under_wine();
}

FDevice HarmonyLink::get_device_info()
{
    FDevice new_device = FDevice();

    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return new_device;
    }

    if (const std::shared_ptr<FDevice> device = PlatformUtilities->get_device())
    {
        new_device = *device;
    }
    return new_device;
}

FOSVerInfo HarmonyLink::get_os_version()
{
    FOSVerInfo new_os_info = FOSVerInfo();

    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return new_os_info;
    }

    if (const std::shared_ptr<FOSVerInfo> os_version_info = PlatformUtilities->get_os_version())
    {
        new_os_info = *os_version_info;
    }

    return new_os_info;
}

FBattery HarmonyLink::get_battery_status()
{
    FBattery battery = FBattery();
    
    if (!PlatformUtilities)
    {
        std::cout << "Failed to get platform utilities!\n";
        return battery;
    }

    if (const std::shared_ptr<FBattery> new_battery = PlatformUtilities->get_battery_status())
    {
        battery = *new_battery;
    }

    return battery;
}
