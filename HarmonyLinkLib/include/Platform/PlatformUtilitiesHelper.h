#pragma once

#include "Core.h"
#include <memory>
#include <utility>

#include "Platform/IPlatformUtilities.h"

class HARMONYLINKLIB_API PlatformUtilitiesHelper
{
public:
    PlatformUtilitiesHelper();
    virtual ~PlatformUtilitiesHelper();

    PlatformUtilitiesHelper(const PlatformUtilitiesHelper&) = delete;
    PlatformUtilitiesHelper& operator=(const PlatformUtilitiesHelper&) = delete;
    
    static std::shared_ptr<IPlatformUtilities> GetPlatformUtility();

    // For testing purposes
    static void SetMockPlatformUtility(std::shared_ptr<IPlatformUtilities> mockUtility)
    {
        INSTANCE = std::move(mockUtility);
    }

    // For testing purposes
    static void reset_mock_platform_utility();

private:
    static std::shared_ptr<IPlatformUtilities> INSTANCE;
};
