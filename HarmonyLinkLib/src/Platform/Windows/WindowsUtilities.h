#pragma once

#include "Platform/IPlatformUtilities.h"

class WindowsUtilities : public IPlatformUtilities
{
public:
    bool isRunningUnderWine()
    {
        return false;
    }
};
