cmake_minimum_required(VERSION 3.14)

# Project name and version
project(SimpleMPI VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

# Add the executable
add_executable(simplempi src/main.cpp)

target_link_libraries(simplempi dl)
