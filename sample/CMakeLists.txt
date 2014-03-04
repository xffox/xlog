cmake_minimum_required(VERSION 2.6)

include_directories(${XLOG_INCLUDES})

set(SAMPLE_NAME "sample")

file(GLOB SAMPLE_SRCS "*.cpp")

add_executable(${SAMPLE_NAME} ${SAMPLE_SRCS})
target_link_libraries(${SAMPLE_NAME} ${XLOG_LIBS})
