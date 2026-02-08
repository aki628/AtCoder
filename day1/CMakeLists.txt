cmake_minimum_required(VERSION 3.10)
project(day1 LANGUAGES CXX)

add_executable(read_seq_ch read_seq_ch.cpp)
add_executable(count_ij count_ij.cpp)
add_executable(music_player music_player.cpp)

# Add target-specific settings here if needed (include_directories, target_compile_options, etc.)

foreach(t IN ITEMS read_seq_ch count_ij music_player)
  set_target_properties(${t} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/day1)
endforeach()

