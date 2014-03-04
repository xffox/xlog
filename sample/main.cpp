#include "xlog/xlog.h"
#include "xlog/ConsoleLogger.h"
#include "xlog/Formatter.h"

XLOG_SET_LOGGER(xlog::ConsoleLogger)
XLOG_SET_FORMATTER(xlog::Formatter)

int main()
{
    xlog::log().error("main", "error '%s'", "error");
    xlog::log().warning("main", "warning '%s'", "warning");
    xlog::log().info("main", "info '%s'", "info");
    xlog::log().debug("main", "debug '%s'", "debug");
    return 0;
}
