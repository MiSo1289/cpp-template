#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

auto main(int const argc, char const* const* const argv) -> int
{
    return Catch::Session{}.run(argc, argv);
}
