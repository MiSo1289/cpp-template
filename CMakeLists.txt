cmake_minimum_required(VERSION 3.17)
file(READ "${CMAKE_CURRENT_BINARY_DIR}/version.txt" CPP_TEMPLATE_VERSION)
project(CppTemplate VERSION "${CPP_TEMPLATE_VERSION}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")
include(conanbuildinfo)

conan_basic_setup(TARGETS)

add_subdirectory(src)
add_subdirectory(tests)
