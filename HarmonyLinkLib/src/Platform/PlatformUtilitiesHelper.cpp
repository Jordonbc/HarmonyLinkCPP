#include "Platform/PlatformUtilitiesHelper.h"

#if BUILD_WINDOWS
#include "Platform/Windows/WindowsUtilities.h"
#elif BUILD_LINUX
#include "Platform/Unix/Linux/LinuxUtilities.h"
#endif

PlatformUtilitiesHelper* PlatformUtilitiesHelper::INSTANCE = nullptr;

PlatformUtilitiesHelper::PlatformUtilitiesHelper()
{
    if (INSTANCE && INSTANCE != this)
    {
        delete INSTANCE;
        INSTANCE = this;
    }
    #if BUILD_WINDOWS
        helper = std::make_shared<WindowsUtilities>();
    #elif BUILD_LINUX
        helper = std::make_shared<LinuxUtilities>();
        // ... other platform checks
    #endif

    if (helper)
    {
        helper->Init();
    }
}

PlatformUtilitiesHelper::~PlatformUtilitiesHelper()
{
    delete INSTANCE;
}

std::shared_ptr<IPlatformUtilities> PlatformUtilitiesHelper::get_platform_utility()
{
    return GetInstance()->helper;
}
