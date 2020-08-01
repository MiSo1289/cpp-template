#include "cpp_template/cpp_template.hpp"

#include <fmt/format.h>

namespace cpp_template
{
    auto Foo::foo() const -> std::string
    {
        return "Foo!";
    }

    auto Bar::bar() const -> std::string
    {
        return fmt::format("Bar: {0}", foo_.foo());
    }
}  // namespace cpp_template
