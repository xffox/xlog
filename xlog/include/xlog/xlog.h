#ifndef XLOG_XLOG_H
#define XLOG_XLOG_H

#include <cstdarg>

#include "xlog/Log.h"

namespace xlog
{
    inline Log &log()
    {
        return Log::getInstance();
    }
}

// static can be transformed to dynamic with an additional logger
// implementation
#define XLOG_SET_LOGGER(type) \
namespace xlog \
{ \
    template<> \
    ILogger *Log::getLogger(const Log&) \
    { \
        static type logger; \
        return &logger; \
    } \
}

#define XLOG_SET_NO_LOGGER() \
namespace xlog \
{ \
    template<> \
    ILogger *Log::getLogger(const Log&) \
    { \
        return nullptr; \
    } \
}

#define XLOG_SET_LOGGER_CONF(type, conf) \
namespace xlog \
{ \
    template<> \
    ILogger *Log::getLogger(const Log&) \
    { \
        static type logger(conf); \
        return &logger; \
    } \
}

#define XLOG_SET_FORMATTER(type) \
namespace xlog \
{ \
    template<> \
    IFormatter &Log::getFormatter(const Log&) \
    { \
        static type formatter; \
        return formatter; \
    } \
}

#define XLOG_SET_FORMATTER_CONF(type, conf) \
namespace xlog \
{ \
    template<> \
    IFormatter &Log::getFormatter(const Log&) \
    { \
        static type formatter(conf); \
        return formatter; \
    } \
}

#endif
