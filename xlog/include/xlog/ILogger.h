#ifndef XLOG_ILOGGER_H
#define XLOG_ILOGGER_H

#include <ctime>
#include <cstdarg>

#include "xlog/xlog.h"

namespace xlog
{
    class IFormatter;
    class LogContext;

    class ILogger
    {
    public:
        virtual ~ILogger(){}

        virtual void log(const IFormatter &formatter,
            const LogContext &context, const char *msg, va_list args) = 0;
    };
}

#endif
