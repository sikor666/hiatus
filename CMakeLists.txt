cmake_minimum_required(VERSION 3.12)

project(hiatus)

# Setting the C++ standard directly
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Add the executable
add_executable(matrix main.cpp)
