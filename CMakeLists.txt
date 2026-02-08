cmake_minimum_required(VERSION 3.10)
project(AtCoder LANGUAGES CXX)

# Default to Debug build if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add day1 as subdirectory
add_subdirectory(day1)
add_subdirectory(day2)

# Common compiler flags for Unix-like compilers and MSVC
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-g -O0 -Wall -Wextra -Wpedantic)
elseif(MSVC)
  add_compile_options(/Zi /Od /W4)
endif()

# Optionally allow the user to specify an output name or install rules later