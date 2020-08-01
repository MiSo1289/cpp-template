#pragma once

#include <gmock/gmock.h>
#include "cpp_template/cpp_template.hpp"

namespace cpp_template
{
    class MockFoo final : public IFoo
    {
      public:
        MOCK_METHOD(std::string, foo, (), (const override));
    };
}  // namespace cpp_template
