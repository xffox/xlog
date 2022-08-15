#include <xlog/xlog.hpp>

#include "lib.h"

XLOG_DEFINE_CONFIG(xlog::LogLevel::LOG_LEVEL_DEBUG,
    xlog::DefaultLogger, xlog::DefaultFormatter)

int main()
{
    xlog::log().debug("main", "this is debug '%s'", "debug");
    xlog::log().info("main", "this is info: '%s'", "info");
    xlog::log().warning("main", "this is warning '%s'", "warn");
    xlog::log().error("main", "this is error: '%d'", 42);
    lib::testLog();
    return 0;
}
