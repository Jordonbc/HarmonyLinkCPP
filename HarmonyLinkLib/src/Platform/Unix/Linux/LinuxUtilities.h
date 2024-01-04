#pragma once

#include "Platform/Unix/UnixUtilities.h"

class LinuxUtilities : public UnixUtilities {
public:
    // Implementation for other Linux-specific functions
    battery get_battery_status() override;
};
