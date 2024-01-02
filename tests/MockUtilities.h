#pragma once

#include <gmock/gmock.h>

#include "HarmonyLink.h" // Include your HarmonyLink class
#include "Platform/IPlatformUtilities.h"

class MockPlatformUtilities : public IPlatformUtilities {
public:
    MOCK_METHOD(bool, isRunningUnderWine, (), (override));
};
