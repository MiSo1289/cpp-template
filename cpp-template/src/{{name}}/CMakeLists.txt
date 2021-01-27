configure_file(build_config.hpp.in build_config.hpp @ONLY)

target_sources(
  {{ name }}

  PUBLIC
  build_config.hpp
  {{name}}.hpp

  PRIVATE
  {{name}}.cpp
)

target_sources(
  {{ name }}_executable

  PRIVATE
  main.cpp
)
