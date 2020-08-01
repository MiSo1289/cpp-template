configure_file(build_config.hpp.in build_config.hpp @ONLY)

target_sources(
  cpp_template

  PUBLIC
  build_config.hpp
  cpp_template.hpp

  PRIVATE
  cpp_template.cpp
)

target_sources(
  cpp_template_executable

  PRIVATE
  main.cpp
)
