#include "Platform/PlatformUtilitiesHelper.h"

#if BUILD_WINDOWS
#include "Platform/Windows/WindowsUtilities.h"
#elif BUILD_LINUX
#include "Platform/Unix/Linux/LinuxUtilities.h"
#endif

std::shared_ptr<IPlatformUtilities> PlatformUtilitiesHelper::INSTANCE = nullptr;

PlatformUtilitiesHelper::PlatformUtilitiesHelper()
{
    reset_mock_platform_utility();
}

PlatformUtilitiesHelper::~PlatformUtilitiesHelper()
{
    INSTANCE = nullptr;
}

std::shared_ptr<IPlatformUtilities> PlatformUtilitiesHelper::GetPlatformUtility()
{
    return INSTANCE;
}

void PlatformUtilitiesHelper::reset_mock_platform_utility()
{
#if BUILD_WINDOWS
    INSTANCE = std::make_shared<WindowsUtilities>();
#elif BUILD_LINUX
    INSTANCE = std::make_shared<LinuxUtilities>();
    // ... other platform checks
#endif
}
