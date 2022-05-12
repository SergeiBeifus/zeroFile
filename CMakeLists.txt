cmake_minimum_required(VERSION 3.21)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(cmake-build-debug/googletest-main)
include_directories(googletest-main/googletest/include)
add_executable(untitled2 main.cpp cmake-build-debug/box.cpp cmake-build-debug/box.h cmake-build-debug/Container3D.cpp cmake-build-debug/Container3D.h)
target_link_libraries(untitled2 gtest)
