#ifndef XLOG_XLOG_HPP
#define XLOG_XLOG_HPP

#include "xlog/inner/log.hpp"
#include "xlog/config.hpp"
#include "xlog/log_level.hpp"
#include "xlog/console_logger.hpp"
#include "xlog/format_formatter.hpp"

namespace xlog
{
    using DefaultLogger = ConsoleLogger;
    using DefaultFormatter = FormatFormatter;
    inline constexpr LogLevel DEFAULT_LOG_LEVEL = LogLevel::LOG_LEVEL_INFO;

    inline inner::Log &log()
    {
        return inner::Log::getInstance();
    }
}

#endif
