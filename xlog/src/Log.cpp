#include "xlog/Log.h"

#include <ctime>
#include <thread>

#include "xlog/LogContext.h"
#include "xlog/ConsoleLogger.h"
#include "xlog/Formatter.h"

#define LOG(level, context, msg) \
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
    Log::Log()
    :logger(getLogger(*this)), formatter(getFormatter(*this))
    {
    }

    void Log::debug(const char *context, const char *msg, ...)
    {
        LOG(LOG_LEVEL_DEBUG, context, msg);
    }

    void Log::info(const char *context, const char *msg, ...)
    {
        LOG(LOG_LEVEL_INFO, context, msg);
    }

    void Log::warning(const char *context, const char *msg, ...)
    {
        LOG(LOG_LEVEL_WARNING, context, msg);
    }

    void Log::error(const char *context, const char *msg, ...)
    {
        LOG(LOG_LEVEL_ERROR, context, msg);
    }

    void Log::log(LogLevel level, const char *context, const char *msg, ...)
    {
        LOG(level, context, msg);
    }

    void Log::log(LogLevel level, const char *context, const char *msg,
        va_list args)
    {
        if(logger)
        {
            logger->log(formatter, LogContext(level, time(0), context,
                    std::this_thread::get_id()), msg, args);
        }
    }

    template<class L>
    ILogger *Log::getLogger(const L&)
    {
        static ConsoleLogger logger;
        return &logger;
    }

    template<class L>
    IFormatter &Log::getFormatter(const L&)
    {
        static Formatter formatter;
        return formatter;
    }
}
