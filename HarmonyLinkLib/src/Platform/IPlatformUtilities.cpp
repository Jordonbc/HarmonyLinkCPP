#include "IPlatformUtilities.h"

#include <fstream>

#include "WineUtilities.h"

void IPlatformUtilities::Init()
{
    // We kinda need to know this first ya know!
    cached_is_wine_ = WineUtilities::detect_wine_presence();
    
    cached_os_version_ = fetch_os_version();
    cached_device_ = fetch_device();

    Initialised = true;
}

std::shared_ptr<FDevice> IPlatformUtilities::fetch_device()
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

    const std::shared_ptr<FBattery> battery_status = fetch_battery_status();

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

IPlatformUtilities::IPlatformUtilities()
{
    std::cout << "Creating new instance of IPlatformUtilities.\n";
}
