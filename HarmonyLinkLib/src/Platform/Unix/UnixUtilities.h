#pragma once

#include "Platform/IPlatformUtilities.h"

class UnixUtilities : public IPlatformUtilities {
public:
    bool is_running_under_wine() override;
    
    // Implementation for other Unix/Linux-specific functions
};
