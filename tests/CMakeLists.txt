add_executable({{ name }}_tests)
target_include_directories(
  {{ name }}_tests

  PRIVATE
  "."
)
target_link_libraries(
  {{ name }}_tests

  PRIVATE
  CONAN_PKG::catch2
  CONAN_PKG::trompeloeil
  {{ name }}::{{ name }}
)

add_subdirectory({{name}})
