#include "cpp_template/cpp_template.hpp"

#include <catch2/catch.hpp>
#include <gmock/gmock.h>
#include "cpp_template/mock_foo.hpp"

TEST_CASE("Bar")
{
    auto mock_foo = cpp_template::MockFoo{};
    auto bar = cpp_template::Bar{mock_foo};

    EXPECT_CALL(mock_foo, foo())
        .WillOnce(testing::Return("Mocked"));

    CHECK(bar.bar() == "Bar: Mocked");
}