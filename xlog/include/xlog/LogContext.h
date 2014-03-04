#ifndef XLOG_LOGCONTEXT_H
#define XLOG_LOGCONTEXT_H

#include <thread>
#include <ctime>

#include "xlog/LogLevel.h"

namespace xlog
{
    struct LogContext
    {
        LogContext(LogLevel level, std::time_t time, const char *context,
            const std::thread::id &threadId)
            :level(level), time(time), context(context), threadId(threadId) {}

        LogLevel level;
        std::time_t time;
        const char *context;
        std::thread::id threadId;
    };
}

#endif
