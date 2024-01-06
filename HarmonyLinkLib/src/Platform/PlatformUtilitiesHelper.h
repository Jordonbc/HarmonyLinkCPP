#pragma once

#include <memory>

#include "Platform/IPlatformUtilities.h"

class PlatformUtilitiesHelper
{
public:
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

    static std::shared_ptr<IPlatformUtilities> get_platform_utility();
    
private:
    PlatformUtilitiesHelper();
    virtual ~PlatformUtilitiesHelper();
    
    std::shared_ptr<IPlatformUtilities> helper = nullptr;
    static PlatformUtilitiesHelper* INSTANCE;
};
