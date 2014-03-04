cmake_minimum_required(VERSION 2.6)

project(xlog)

if(CMAKE_BUILD_TYPE STREQUAL "debug")
    add_definitions(-DDEBUG)
endif()

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

if(UNIX)
    add_definitions("-Wall -Wextra -pedantic -std=c++11")
endif()

add_subdirectory(xlog)
add_subdirectory(sample)
