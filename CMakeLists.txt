cmake_minimum_required(VERSION 3.10)
project(AtCoder LANGUAGES CXX)

# Default to Debug build if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add executable for day1/read_seq_ch
add_executable(read_seq_ch day1/read_seq_ch.cpp)
add_executable(count_ij day1/count_ij.cpp)

# Compiler flags for Unix-like compilers
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(read_seq_ch PRIVATE -g -O0 -Wall -Wextra -Wpedantic)
elseif(MSVC)
  target_compile_options(read_seq_ch PRIVATE /Zi /Od /W4)
endif()

# Optionally allow the user to specify an output name or install rules later