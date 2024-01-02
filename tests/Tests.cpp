#include <gtest/gtest.h>

#include "MockUtilities.h"
#include "HarmonyLinkTest.h"
#include "Version.h"

TEST(Versioning, ToString) {
    const std::string versionString = version::ToString().c_str();
    ASSERT_FALSE(versionString.empty());
}

TEST(Versioning, get_build_timestamp) {
    const std::string versionString = version::get_build_timestamp().c_str();
    ASSERT_FALSE(versionString.empty());
}

TEST(Versioning, get_git_branch) {
    const std::string versionString = version::get_git_branch().c_str();
    ASSERT_FALSE(versionString.empty());
}

TEST(Versioning, get_git_commit_timestamp) {
    const std::string versionString = version::get_git_commit_timestamp().c_str();
    ASSERT_FALSE(versionString.empty());
}

TEST_F(HarmonyLinkTest, IsRunningUnderWine_Return_False) {
    EXPECT_CALL(*mockPlatformUtilities, isRunningUnderWine())
        .WillOnce(testing::Return(false)); // Adjust as needed
    
    const bool result = HarmonyLink::isRunningUnderWine();

    EXPECT_FALSE(result); // Adjust as needed
}

TEST_F(HarmonyLinkTest, IsRunningUnderWine_Return_True) {
    EXPECT_CALL(*mockPlatformUtilities, isRunningUnderWine())
        .WillOnce(testing::Return(true)); // Adjust as needed
    
    const bool result = HarmonyLink::isRunningUnderWine();

    EXPECT_TRUE(result); // Adjust as needed
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
