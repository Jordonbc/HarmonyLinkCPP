#pragma once

#include "Platform/IPlatformUtilities.h"

class UnixUtilities : public IPlatformUtilities {
public:
    bool isRunningUnderWine() override;
    
    // Implementation for other Unix/Linux-specific functions
};
