#pragma once
{% set ns_name = name | replace("-", "_") %}
#include <string>

namespace {{ ns_name }}
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
}  // namespace {{ ns_name }}
