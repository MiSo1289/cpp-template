add_executable(cpp_template_tests)
target_include_directories(
  cpp_template_tests

  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_link_libraries(
  cpp_template_tests

  PRIVATE
  CONAN_PKG::catch2
  CONAN_PKG::gtest
  cpp_template
)
target_compile_definitions(
  cpp_template_tests

  PRIVATE
  GTEST_DONT_DEFINE_FAIL=1
  GTEST_DONT_DEFINE_SUCCEED=1
)

add_subdirectory(cpp_template)
