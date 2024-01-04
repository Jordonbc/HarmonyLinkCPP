#pragma once

#include "Platform/Unix/UnixUtilities.h"

class LinuxUtilities : public UnixUtilities {
public:
    // Implementation for other Linux-specific functions
    FBattery get_battery_status() override;
    
    FDistroInfo get_os_release() override
    {
        return get_os_info("/etc/os-release");
    }
};
