cmake_minimum_required(VERSION 3.17)
file(READ "${CMAKE_CURRENT_BINARY_DIR}/version.txt" CPP_TEMPLATE_VERSION)
project(CppTemplate VERSION "${CPP_TEMPLATE_VERSION}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")
include(conanbuildinfo)

conan_basic_setup(TARGETS)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIRECTORY "docs")
  set(DOXYGEN_EXCLUDE_SYMBOLS "detail")
  set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
  doxygen_add_docs(cpp_template_doxygen "src")
endif()

add_subdirectory(src)
add_subdirectory(tests)
