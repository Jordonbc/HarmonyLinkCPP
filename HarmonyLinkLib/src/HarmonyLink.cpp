#include "HarmonyLink.h"
#include <iostream>

#include "Platform/IPlatformUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"


void HarmonyLink::exampleFunction()
{
    std::cout << "Hello from HarmonyLink!\n";
}

bool HarmonyLink::isRunningUnderWine()
{
    const std::shared_ptr<IPlatformUtilities> PlatformUtilities = PlatformUtilitiesHelper::GetPlatformUtility();

    if (!PlatformUtilities)
    {
        return false;
    }

    return PlatformUtilities->isRunningUnderWine();
}
