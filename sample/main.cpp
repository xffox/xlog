#include <xlog/xlog.h>

#include "lib.h"

XLOG_DEFINE_CONFIG(xlog::DefaultLogger, xlog::DefaultFormatter)

int main()
{
    xlog::log().error("main", "error '%s'", "error");
    xlog::log().warning("main", "warning '%s'", "warning");
    xlog::log().info("main", "info '%s'", "info");
    xlog::log().debug("main", "debug '%s'", "debug");
    lib::testLog();
    return 0;
}
