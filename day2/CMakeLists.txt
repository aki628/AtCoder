cmake_minimum_required(VERSION 3.10)
project(day2 LANGUAGES CXX)

add_executable(Yokan_Party Yokan_Praty.cpp)

# Add target-specific settings here if needed (include_directories, target_compile_options, etc.)

set_target_properties(Yokan_Party PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/day2)