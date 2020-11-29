#include <cstdio>
#include <cstdlib>
{% set ns_name = name | replace("-", "_") %}
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <lyra/lyra.hpp>
#include <spdlog/spdlog.h>
#include "{{name}}/{{name}}.hpp"

auto main(int const argc, char const* const* const argv) -> int
{
    auto print_help = false;

    auto cli = lyra::cli_parser{} | lyra::help{print_help};

    if (auto const result = cli.parse({argc, argv});
        not result)
    {
        fmt::print(stderr, "Error: {0}\n", result.errorMessage());
        fmt::print("Run with --help to see correct usage.\n");

        return EXIT_FAILURE;
    }

    if (print_help)
    {
        fmt::print("{0}\n", cli);

        return EXIT_SUCCESS;
    }

    auto foo = {{ ns_name }}::Foo{};
    auto bar = {{ ns_name }}::Bar{foo};

    spdlog::info("Message: {0}", bar.bar());

    return EXIT_SUCCESS;
}
