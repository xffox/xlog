#include "xlog/console_logger.hpp"

#include <iostream>

#include "xlog/formatter.hpp"
#include "xlog/log_context.hpp"

namespace xlog
{
    ConsoleLogger::ConsoleLogger()
        :level(LOG_LEVEL_DEBUG){}

    ConsoleLogger::ConsoleLogger(LogLevel level)
        :level(level){}

    void ConsoleLogger::log(const IFormatter &formatter,
        const LogContext &context, const char *msg, va_list args)
    {
        if(context.level >= level)
        {
            char buf[1024];
            formatter.format(buf, sizeof(buf), context, msg, args);
            std::cout<<buf<<std::endl;
        }
    }
}
