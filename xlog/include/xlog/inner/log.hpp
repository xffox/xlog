#ifndef XLOG_INNER_LOG_HPP
#define XLOG_INNER_LOG_HPP

#include <cstdarg>
#include <ctime>

#include "xlog/log_level.hpp"
#include "xlog/log_context.hpp"

namespace xlog
{
    class ILogger;
    class IFormatter;
}

namespace xlog::config
{
    ILogger &logger();
    IFormatter &formatter();
}

namespace xlog::inner
{
    class Log
    {
    public:
        static Log &getInstance();

        void debug(const char *context, const char *msg, ...);
        void info(const char *context, const char *msg, ...);
        void warning(const char *context, const char *msg, ...);
        void error(const char *context, const char *msg, ...);

        void log(LogLevel level, const char *context, const char *msg, ...);

    private:
        Log();

        void log(LogLevel level, const char *context, const char *msg,
            va_list args);

    private:
        ILogger &logger;
        IFormatter &formatter;
    };
}

#endif
