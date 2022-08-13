#ifndef XLOG_LOGGER_HPP
#define XLOG_LOGGER_HPP

#include <ctime>
#include <cstdarg>

namespace xlog
{
    class IFormatter;
    struct LogContext;

    class ILogger
    {
    public:
        virtual ~ILogger(){}

        virtual void log(const IFormatter &formatter,
            const LogContext &context, const char *msg, va_list args) = 0;
    };
}

#endif
