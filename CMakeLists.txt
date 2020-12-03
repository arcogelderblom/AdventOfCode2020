cmake_minimum_required(VERSION 3.0)

project(AdventOfCode2020)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-Wall -Werror)

# Build common first to create the common library
add_subdirectory(Common)

add_subdirectory(Day01)
add_subdirectory(Day02)
add_subdirectory(Day03)