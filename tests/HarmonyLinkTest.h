#pragma once
#include <gtest/gtest.h>

#include "MockUtilities.h"
#include "Platform/PlatformUtilitiesHelper.h"

class HarmonyLinkTest : public ::testing::Test {
protected:
    void SetUp() override {
        mockPlatformUtilities = std::make_shared<MockPlatformUtilities>();
        PlatformUtilitiesHelper::SetMockPlatformUtility(mockPlatformUtilities);
    }

    void TearDown() override {
        PlatformUtilitiesHelper::reset_mock_platform_utility();
    }

    std::shared_ptr<MockPlatformUtilities> mockPlatformUtilities;
};
