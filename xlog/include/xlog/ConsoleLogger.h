#ifndef XLOG_CONSOLELOGGER_H
#define XLOG_CONSOLELOGGER_H

#include "xlog/ILogger.h"
#include "xlog/LogLevel.h"

namespace xlog
{
    class IFormatter;

    class ConsoleLogger: public ILogger
    {
    public:
        ConsoleLogger();
        ConsoleLogger(LogLevel level);

        virtual void log(const IFormatter &formatter,
            const LogContext &context, const char *msg, va_list args);

    private:
        ConsoleLogger(const ConsoleLogger&);
        ConsoleLogger &operator=(const ConsoleLogger&);

    private:
        const LogLevel level;
    };
}

#endif
