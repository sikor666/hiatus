cmake_minimum_required(VERSION 3.10)

project(hiatus)

# Setting the C++ standard directly
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Add boost package
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)

find_package(Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${Boost_LIBRARY_DIRS})
endif(Boost_FOUND)

# Add the executable
add_executable(hiatus main.cpp)

# Add link libraries
target_link_libraries(hiatus LINK_PRIVATE ${Boost_SYSTEM_LIBRARY})
