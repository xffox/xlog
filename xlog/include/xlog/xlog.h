#ifndef XLOG_XLOG_H
#define XLOG_XLOG_H

#include "xlog/inner/log.hpp"
#include "xlog/config.hpp"
#include "xlog/console_logger.hpp"
#include "xlog/format_formatter.hpp"

namespace xlog
{
    using DefaultLogger = ConsoleLogger;
    using DefaultFormatter = FormatFormatter;

    inline inner::Log &log()
    {
        return inner::Log::getInstance();
    }
}

#endif
