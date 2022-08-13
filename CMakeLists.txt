cmake_minimum_required(VERSION 3.0)

project(xlog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

if(UNIX)
    add_compile_options(-Werror -Wall -Wextra -Weffc++ -pedantic)
endif()

add_subdirectory(xlog)
if(NOT DISABLE_SAMPLE)
    add_subdirectory(sample)
endif()
