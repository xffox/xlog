cmake_minimum_required(VERSION 3.0)

set(XLOG_SAMPLE "sample")

file(GLOB XLOG_SAMPLE_SRCS "*.cpp")

add_executable(${XLOG_SAMPLE} ${XLOG_SAMPLE_SRCS})
target_link_libraries(${XLOG_SAMPLE} ${XLOG})
