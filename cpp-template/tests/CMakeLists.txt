add_executable({{ name }}_tests)
target_include_directories(
  {{ name }}_tests

  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
)
target_link_libraries(
  {{ name }}_tests

  PRIVATE
  CONAN_PKG::catch2
  CONAN_PKG::trompeloeil
  {{ name }}::{{ name }}
)

add_subdirectory({{name}})
