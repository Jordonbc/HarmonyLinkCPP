#pragma once

#include "Core.h"
#include <memory>

#include "Platform/IPlatformUtilities.h"

class HARMONYLINKLIB_API PlatformUtilitiesHelper
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
