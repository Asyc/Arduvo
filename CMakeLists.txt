cmake_minimum_required(VERSION 3.19)
project(Arduvo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arduvo src/main.cpp src/file/file.cpp src/file/file.hpp test/dll/library.cpp src/log/logger.hpp src/log/logger.cpp src/file/dll_file.cpp src/file/dll_file.hpp src/process/process_finder.cpp src/process/process_finder.hpp)

add_subdirectory(vendors/cxxopts)
add_subdirectory(vendors/spdlog)

target_link_libraries(Arduvo PRIVATE cxxopts spdlog)
target_include_directories(Arduvo PRIVATE src)

add_subdirectory(test)