#include "HarmonyLink.h"
#include <iostream>

#include "Platform/IPlatformUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"

bool HarmonyLink::is_running_under_wine()
{
    const std::shared_ptr<IPlatformUtilities> PlatformUtilities = PlatformUtilitiesHelper::GetInstance()->get_platform_utility();

    if (!PlatformUtilities)
    {
        return false;
    }

    return PlatformUtilities->is_running_under_wine();
}

battery HarmonyLink::get_battery_status()
{
    const std::shared_ptr<IPlatformUtilities> PlatformUtilities = PlatformUtilitiesHelper::GetInstance()->get_platform_utility();

    if (!PlatformUtilities)
    {
        return {};
    }

    return PlatformUtilities->get_battery_status();
}
