cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)  # Use C++11
project(Project_Euler)

# Set default type as release, and set flags for different build types
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wconversion -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/obj)

# The Euler library
include_directories("${PROJECT_SOURCE_DIR}/src/lib/")
add_subdirectory(src/lib)  # Defines `euler` library

# Build all the problems
file(GLOB SOURCES "src/*.cpp")
foreach(source_file ${SOURCES})
    get_filename_component(bin_file ${source_file} NAME_WE)

    message(STATUS "Found ${bin_file}")

    add_executable(${bin_file} ${source_file})
    target_link_libraries(${bin_file} euler)
endforeach(source_file ${SOURCES})
