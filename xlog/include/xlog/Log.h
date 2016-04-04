#ifndef XLOG_LOG_H
#define XLOG_LOG_H

#include <cstdarg>
#include <ctime>

#include "xlog/ConsoleLogger.h"
#include "xlog/Formatter.h"
#include "xlog/ILogger.h"
#include "xlog/LogContext.h"
#include "xlog/LogLevel.h"

#define XLOG_INNER_LOG(level, context, msg) \
    do \
    { \
        va_list args; \
        va_start(args, msg); \
        log(level, context, msg, args); \
        va_end(args); \
    } \
    while(0)

namespace xlog
{
    class IFormatter;

    template<typename T>
    class TemplLog
    {
    public:
        static TemplLog &getInstance()
        {
            static TemplLog instance;
            return instance;
        }

        void debug(const char *context, const char *msg, ...)
        {
            XLOG_INNER_LOG(LOG_LEVEL_DEBUG, context, msg);
        }
        void info(const char *context, const char *msg, ...)
        {
            XLOG_INNER_LOG(LOG_LEVEL_INFO, context, msg);
        }
        void warning(const char *context, const char *msg, ...)
        {
            XLOG_INNER_LOG(LOG_LEVEL_WARNING, context, msg);
        }
        void error(const char *context, const char *msg, ...)
        {
            XLOG_INNER_LOG(LOG_LEVEL_ERROR, context, msg);
        }

        void log(LogLevel level, const char *context, const char *msg, ...)
        {
            XLOG_INNER_LOG(level, context, msg);
        }

    private:
        TemplLog()
            :logger(getLogger(*this)), formatter(getFormatter(*this))
        {}

        void log(LogLevel level, const char *context, const char *msg,
            va_list args)
        {
            if(logger)
            {
                logger->log(formatter, LogContext(level, time(0), context),
                    msg, args);
            }
        }

    private:
        ILogger *const logger;
        IFormatter &formatter;
    };

    typedef TemplLog<int> Log;

    template<class L>
    ILogger *getLogger(const L&)
    {
        static ConsoleLogger logger;
        return &logger;
    }

    template<class L>
    IFormatter &getFormatter(const L&)
    {
        static Formatter formatter;
        return formatter;
    }

#ifdef _MSC_VER
    template<>
    ILogger *getLogger(const TemplLog<int>&);
    template<>
    IFormatter &getFormatter(const TemplLog<int>&);
#endif
}

#endif
