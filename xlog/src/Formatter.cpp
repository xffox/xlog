#include "xlog/Formatter.h"

#include <cstdio>
#include <sstream>

#include "xlog/LogContext.h"

namespace xlog
{
    namespace
    {
        inline char makeLogLevel(LogLevel level)
        {
            switch(level) {
            case LOG_LEVEL_DEBUG:
                return 'D';
            case LOG_LEVEL_INFO:
                return 'I';
            case LOG_LEVEL_WARNING:
                return 'W';
            case LOG_LEVEL_ERROR:
                return 'E';
            };
            return '-';
        }
    }

    void Formatter::format(char *buf, std::size_t size,
        const LogContext &context, const char *msg, va_list args) const
    {
        char msgBuf[1024];
        BaseFormatter::format(msgBuf, sizeof(msgBuf), context, msg, args);
#ifndef _MSC_VER
        snprintf(buf, size, "[%lu][%c][%s] %s",
            static_cast<unsigned long>(context.time),
            makeLogLevel(context.level),
            context.context, msgBuf);
#else
        _snprintf(buf, size, "[%lu][%c][%s] %s",
            static_cast<unsigned long>(context.time),
            makeLogLevel(context.level),
            context.context, msgBuf);
#endif
    }
}
