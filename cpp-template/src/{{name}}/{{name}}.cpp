#include "{{name}}/{{name}}.hpp"
{% set ns_name = name | replace("-", "_") %}
#include <fmt/format.h>

namespace {{ ns_name }}
{
    auto Foo::foo() const -> std::string
    {
        return "Foo!";
    }

    auto Bar::bar() const -> std::string
    {
        return fmt::format("Bar: {0}", foo_.foo());
    }
}  // namespace {{ ns_name }}
