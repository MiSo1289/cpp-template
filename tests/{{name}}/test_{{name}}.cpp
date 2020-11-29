#include "{{name}}/{{name}}.hpp"
{% set ns_name = name | replace("-", "_") %}
#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include "{{name}}/mock_foo.hpp"

TEST_CASE("Bar")
{
    auto mock_foo = {{ ns_name }}::MockFoo{};
    auto bar = {{ ns_name }}::Bar{mock_foo};

    REQUIRE_CALL(mock_foo, foo())
        .RETURN("Mocked");

    CHECK(bar.bar() == "Bar: Mocked");
}
