#ifndef XLOG_LOG_H
#define XLOG_LOG_H

#include <cstdarg>

#include "xlog/LogLevel.h"

namespace xlog
{
    class ILogger;
    class IFormatter;

    class Log
    {
    public:
        static Log &getInstance()
        {
            static Log instance;
            return instance;
        }

        void debug(const char *context, const char *msg, ...);
        void info(const char *context, const char *msg, ...);
        void warning(const char *context, const char *msg, ...);
        void error(const char *context, const char *msg, ...);

        void log(LogLevel level, const char *context, const char *msg, ...);

    private:
        template<class L>
        static ILogger *getLogger(const L&);
        template<class L>
        static IFormatter &getFormatter(const L&);

    private:
        Log();

        void log(LogLevel level, const char *context, const char *msg,
            va_list args);

    private:
        ILogger *const logger;
        IFormatter &formatter;
    };
}

#endif
