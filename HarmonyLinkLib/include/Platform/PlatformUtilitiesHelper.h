#pragma once

#include "Core.h"
#include <memory>

#include "Platform/IPlatformUtilities.h"

class HARMONYLINKLIB_API PlatformUtilitiesHelper
{
public:
    PlatformUtilitiesHelper();
    virtual ~PlatformUtilitiesHelper();

    PlatformUtilitiesHelper(const PlatformUtilitiesHelper&) = delete;
    PlatformUtilitiesHelper& operator=(const PlatformUtilitiesHelper&) = delete;

    static std::shared_ptr<IPlatformUtilities> get_platform_utility();
};
