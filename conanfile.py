from conans import CMake, ConanFile, tools


class {{ package_name }}(ConanFile):
    name = "{{ name }}"
    version = "0.1.0"
    revision_mode = "scm"
    settings = ("os", "compiler", "build_type", "arch")
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "tests": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "tests": True
    }
    generators = "cmake"
    exports_sources = (
        "src/*",
        "tests/*",
        "CMakeLists.txt",
    )
    requires = (
        # Boost libraries
        "boost/1.74.0",
        # Good alternative to IO streams
        "fmt/7.1.2",
        # Customizable alternative for std::function
        "function2/4.1.0",
        # Calendar extensions for chrono
        "date/3.0.0",
        # CLI parser
        "lyra/1.5.1",
        # Enum utils (e.g. stringification)
        "magic_enum/0.7.0",
        # Guideline support library - MS implementation
        "ms-gsl/3.1.0",
        # Alternative to iterators
        "range-v3/0.11.0",
        # Logging library based on FMT
        "spdlog/1.8.1",
    )
    build_requires = (
        # Unit-test framework
        "catch2/2.13.3",
        # Mocking for unit-tests
        "trompeloeil/v39@rollbear/stable",
    )

    def imports(self):
        self.copy("*.so*", dst="lib", keep_path=False)

        with open("version.txt", "w") as version_file:
            version_file.write(str(self.version))

    def build(self):
        cmake = CMake(self)

        cmake.configure()
        cmake.build(target="{{ name }}")

        if self.options.tests:
            cmake.test(target="{{ name }}_tests")

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.hpp", dst="include", src="src")
        self.copy("*.so*", dst="lib", keep_path=False, symlinks=True)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_id(self):
        # Does not impact the resulting package, exclude from package id
        del self.info.options.tests

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
