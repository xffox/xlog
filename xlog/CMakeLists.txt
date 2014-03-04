cmake_minimum_required(VERSION 2.6)

include(FindThreads)

set(XLOG_NAME xlog)

set(XLOG_INCLUDES "${CMAKE_SOURCE_DIR}/xlog/include")
set(XLOG_INCLUDES ${XLOG_INCLUDES} PARENT_SCOPE)

include_directories(${XLOG_INCLUDES})

set(XLOG_LIBS ${XLOG_NAME})
set(XLOG_LIBS ${XLOG_LIBS} PARENT_SCOPE)

file(GLOB XLOG_SRCS "src/*.cpp")

add_library(${XLOG_NAME} SHARED ${XLOG_SRCS})
target_link_libraries(${XLOG_NAME} ${CMAKE_THREAD_LIBS_INIT})
