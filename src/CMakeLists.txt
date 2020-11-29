add_library({{ name }})
add_library({{ name }}::{{ name }} ALIAS {{ name }})
target_compile_features({{ name }} PUBLIC cxx_std_20)
target_include_directories(
  {{ name }}

  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(
  {{ name }}

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

add_executable({{ name }}_executable)
target_link_libraries(
  {{ name }}_executable

  PRIVATE
  {{ name }}::{{ name }}
)

add_subdirectory({{name}})
