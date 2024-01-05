#pragma once

#include "FOSVerInfo.h"
#include "Platform/Unix/UnixUtilities.h"

class LinuxUtilities : public UnixUtilities {
public:
    // Implementation for other Linux-specific functions
    FBattery get_battery_status() override;
    
    FOSVerInfo get_os_version() override;
};
