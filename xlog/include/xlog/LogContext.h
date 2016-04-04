#ifndef XLOG_LOGCONTEXT_H
#define XLOG_LOGCONTEXT_H

#include <ctime>

#include "xlog/LogLevel.h"

namespace xlog
{
    struct LogContext
    {
        LogContext(LogLevel level, std::time_t time, const char *context)
            :level(level), time(time), context(context) {}

        LogLevel level;
        std::time_t time;
        const char *context;
    };
}

#endif
