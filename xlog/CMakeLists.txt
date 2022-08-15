cmake_minimum_required(VERSION 3.0)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(XLOG xlog)
set(XLOG ${XLOG} PARENT_SCOPE)

set(XLOG_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB XLOG_SRCS "src/*.cpp" "src/*/*.cpp")

add_library(${XLOG} STATIC ${XLOG_SRCS})
target_include_directories(${XLOG} PUBLIC "$<BUILD_INTERFACE:${XLOG_INCLUDES}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/XLogConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/XLog)

install(TARGETS ${XLOG} EXPORT XLogTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${XLOG_INCLUDES}/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT XLogTargets NAMESPACE xlog::
    FILE "XLogTargets.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/XLog")
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/XLogConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/XLog)
