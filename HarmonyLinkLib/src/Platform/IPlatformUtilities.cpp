#include "IPlatformUtilities.h"

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

    if (const std::shared_ptr<FOSVerInfo> version = get_os_version())
    {
        if (version->variant_id == "steamdeck" && version->name == "SteamOS")
        {
            new_device.device = EDevice::STEAM_DECK;
        }
    }

    return std::make_shared<FDevice>(new_device);
}
