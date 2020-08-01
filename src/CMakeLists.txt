add_library(cpp_template)
target_compile_features(cpp_template PUBLIC cxx_std_20)
target_include_directories(
  cpp_template

  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(
  cpp_template

  PUBLIC
  CONAN_PKG::boost
  CONAN_PKG::fmt
  CONAN_PKG::function2
  CONAN_PKG::date
  CONAN_PKG::lyra
  CONAN_PKG::magic_enum
  CONAN_PKG::ms-gsl
  CONAN_PKG::range-v3
  CONAN_PKG::spdlog
)

add_executable(cpp_template_executable)
target_link_libraries(
  cpp_template_executable

  PRIVATE
  cpp_template
)

add_subdirectory(cpp_template)