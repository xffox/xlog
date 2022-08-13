#ifndef XLOG_LOGCONTEXT_HPP
#define XLOG_LOGCONTEXT_HPP

#include <ctime>

#include "xlog/log_level.hpp"

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
