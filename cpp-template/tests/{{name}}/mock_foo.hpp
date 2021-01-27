#pragma once
{% set ns_name = name | replace("-", "_") %}
#include <trompeloeil.hpp>
#include "{{name}}/{{name}}.hpp"

namespace {{ ns_name }}
{
    class MockFoo final : public IFoo
    {
      public:
        MAKE_MOCK0(foo, std::string(), const override);
    };
}  // namespace {{ ns_name }}
