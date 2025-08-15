cmake_minimum_required(VERSION 3.14)

# Project name and version
project(SimpleMPI VERSION 1.0)

# Add the executable
add_executable(simplempi src/main.cpp)

# Specify the C++ standard
target_compile_features(simplempi PUBLIC cxx_std_11)

target_link_libraries(simplempi dl)
