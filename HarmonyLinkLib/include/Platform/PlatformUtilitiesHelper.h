#pragma once

#include <memory>

#include "Platform/IPlatformUtilities.h"

class PlatformUtilitiesHelper
{
public:
    PlatformUtilitiesHelper();
    virtual ~PlatformUtilitiesHelper();

    PlatformUtilitiesHelper(const PlatformUtilitiesHelper&) = delete;
    PlatformUtilitiesHelper& operator=(const PlatformUtilitiesHelper&) = delete;
    
    static std::shared_ptr<IPlatformUtilities> GetPlatformUtility();

private:
    static std::shared_ptr<IPlatformUtilities> INSTANCE;
};
