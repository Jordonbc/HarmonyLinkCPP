#pragma once

#include "FOSVerInfo.h"
#include "Platform/Unix/UnixUtilities.h"

class LinuxUtilities : public UnixUtilities {
public:
    // Implementation for other Linux-specific functions
    std::shared_ptr<FBattery> fetch_battery_status() override;
    
    std::shared_ptr<FOSVerInfo> fetch_os_version() override;

    bool is_linux() override
    {
        return true;
    }
};
