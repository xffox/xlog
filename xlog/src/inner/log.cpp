#include "xlog/inner/log.hpp"

#include "xlog/logger.hpp"

#define XLOG_INNER_LOG(level, context, msg) \
    do \
    { \
        va_list args; \
        va_start(args, msg); \
        log(level, context, msg, args); \
        va_end(args); \
    } \
    while(0)

namespace xlog::inner
{
    Log::Log()
        :logger(config::logger()), formatter(config::formatter())
    {}

    Log &Log::getInstance()
    {
        static Log instance;
        return instance;
    }

    void Log::debug(const char *context, const char *msg, ...)
    {
        XLOG_INNER_LOG(LOG_LEVEL_DEBUG, context, msg);
    }
    void Log::info(const char *context, const char *msg, ...)
    {
        XLOG_INNER_LOG(LOG_LEVEL_INFO, context, msg);
    }
    void Log::warning(const char *context, const char *msg, ...)
    {
        XLOG_INNER_LOG(LOG_LEVEL_WARNING, context, msg);
    }
    void Log::error(const char *context, const char *msg, ...)
    {
        XLOG_INNER_LOG(LOG_LEVEL_ERROR, context, msg);
    }

    void Log::log(LogLevel level, const char *context, const char *msg, ...)
    {
        XLOG_INNER_LOG(level, context, msg);
    }

    void Log::log(LogLevel level, const char *context, const char *msg,
        va_list args)
    {
        if(level >= config::LOG_LEVEL)
        {
            logger.log(formatter, LogContext(level, time(0), context),
                msg, args);
        }
    }
}
