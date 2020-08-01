#pragma once

#include <string>

namespace cpp_template
{
    class IFoo
    {
      public:
        virtual ~IFoo() noexcept = default;

        [[nodiscard]] virtual auto foo() const -> std::string = 0;
    };

    class Foo final : public IFoo
    {
      public:
        [[nodiscard]] auto foo() const -> std::string override;
    };

    class Bar
    {
      public:
        explicit Bar(IFoo& foo)
          : foo_{foo} { }

        [[nodiscard]] auto bar() const -> std::string;

      private:
        IFoo& foo_;
    };
}  // namespace cpp_template
