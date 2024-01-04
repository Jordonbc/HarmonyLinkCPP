#pragma once

#include <memory>

#include "Platform/IPlatformUtilities.h"

class PlatformUtilitiesHelper
{
public:
    PlatformUtilitiesHelper();
    virtual ~PlatformUtilitiesHelper();

    static PlatformUtilitiesHelper* GetInstance()
    {
        if (!INSTANCE)
        {
            INSTANCE = new PlatformUtilitiesHelper();
        }
        
        return INSTANCE;
    }

    PlatformUtilitiesHelper(const PlatformUtilitiesHelper&) = delete;
    PlatformUtilitiesHelper& operator=(const PlatformUtilitiesHelper&) = delete;

    std::shared_ptr<IPlatformUtilities> get_platform_utility();
    
private:
    std::shared_ptr<IPlatformUtilities> helper = nullptr;
    static PlatformUtilitiesHelper* INSTANCE;
};
