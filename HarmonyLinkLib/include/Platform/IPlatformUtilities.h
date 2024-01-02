﻿#pragma once

class IPlatformUtilities {
public:
    IPlatformUtilities() = default;
    virtual ~IPlatformUtilities() = default;

    // General OS-level functions
    virtual bool isRunningUnderWine()
    {
        return false;
    }

    // Add more virtual functions for other OS interactions here
};
