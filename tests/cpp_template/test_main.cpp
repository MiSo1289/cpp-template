#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <gmock/gmock.h>

auto main(int argc, char** const argv) -> int
{
    // Throw on gmock error to allow co_existence with catch
    testing::GTEST_FLAG(throw_on_failure) = true;
    testing::InitGoogleTest(&argc, argv);

    return Catch::Session{}.run(argc, argv);
}
