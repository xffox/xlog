#include "xlog/Formatter.h"

#include <cstdio>
#include <sstream>
#include <thread>

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

        inline std::string makeThreadId(const std::thread::id &id)
        {
            std::stringstream stream;
            stream<<id;
            return stream.str();
        }
    }

    void Formatter::format(char *buf, std::size_t size,
        const LogContext &context, const char *msg, va_list args) const
    {
        char msgBuf[1024];
        BaseFormatter::format(msgBuf, sizeof(msgBuf), context, msg, args);
        snprintf(buf, size, "[%lu][%c][%s:%s] %s",
            static_cast<unsigned long>(context.time),
            makeLogLevel(context.level),
            makeThreadId(context.threadId).c_str(),
            context.context, msgBuf);
    }
}
