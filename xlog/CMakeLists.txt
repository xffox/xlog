cmake_minimum_required(VERSION 3.0)

set(XLOG xlog)
set(XLOG ${XLOG} PARENT_SCOPE)

set(XLOG_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB XLOG_SRCS "src/*.cpp" "src/*/*.cpp")

add_library(${XLOG} STATIC ${XLOG_SRCS})
target_include_directories(${XLOG} PUBLIC ${XLOG_INCLUDES})
