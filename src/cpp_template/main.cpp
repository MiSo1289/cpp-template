#include <iostream>

#include <lyra/lyra.hpp>
#include <spdlog/spdlog.h>
#include "cpp_template/cpp_template.hpp"

auto main(int const argc, char const* const* const argv) -> int
{
    auto print_help = false;

    auto cli = lyra::cli_parser{} | lyra::help{print_help};

    if (auto const result = cli.parse({argc, argv});
        not result)
    {
        std::cerr << "Error: " << result.errorMessage() << "\n";
        std::cout << "Run with --help to see correct usage.\n";

        return EXIT_FAILURE;
    }

    if (print_help)
    {
        std::cout << cli << "\n";

        return EXIT_SUCCESS;
    }

    auto foo = cpp_template::Foo{};
    auto bar = cpp_template::Bar{foo};

    spdlog::info("Message: {0}", bar.bar());

    return EXIT_SUCCESS;
}
