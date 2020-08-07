from conans import CMake, ConanFile, tools


class CppTemplate(ConanFile):
    name = "cpp-template"
    version = "0.1.0"
    revision_mode = "scm"
    settings = ("os", "compiler", "build_type", "arch")
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "tests": [True, False],
    }
    default_options = {
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
        "boost/1.73.0",
        "fmt/7.0.1",
        "function2/4.1.0",
        "date/2.4.1",
        "lyra/1.4.0",
        "magic_enum/0.6.6",
        "ms-gsl/3.0.1",
        "range-v3/0.10.0",
        "spdlog/1.7.0",
    )
    build_requires = (
        "catch2/2.13.0",
        "gtest/1.10.0",
    )

    def imports(self):
        self.copy("*.so*", dst="lib", keep_path=False)

        with open("version.txt", "w") as version_file:
            version_file.write(str(self.version))

    def build(self):
        cmake = CMake(self)

        cmake.configure()
        cmake.build(target="cpp_template")

        if self.options.tests:
            cmake.test(target="cpp_template_tests")

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
