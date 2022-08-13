#ifndef XLOG_CONFIG_HPP
#define XLOG_CONFIG_HPP

#include "xlog/logger.hpp"
#include "xlog/formatter.hpp"

#define XLOG_INNER_SET_LOGGER(type) \
    xlog::ILogger &xlog::config::logger() \
    { \
        static type logger{}; \
        return logger; \
    } \

#define XLOG_INNER_SET_FORMATTER(type) \
    xlog::IFormatter &xlog::config::formatter() \
    { \
        static type formatter{}; \
        return formatter; \
    } \

#define XLOG_DEFINE_CONFIG(logger, formatter) \
    XLOG_INNER_SET_LOGGER(logger) \
    XLOG_INNER_SET_FORMATTER(formatter)

#endif
