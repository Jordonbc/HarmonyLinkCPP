#include <gtest/gtest.h>
#include "Version.h" // Adjust this path to point to your version.h file

TEST(Versioning, ToString) {
    const std::string versionString = version::ToString();
    ASSERT_FALSE(versionString.empty());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
