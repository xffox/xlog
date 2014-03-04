#include "xlog/ConsoleLogger.h"

#include <iostream>

#include "xlog/IFormatter.h"
#include "xlog/LogContext.h"
#include "xlog/xlog.h"

namespace xlog
{
    ConsoleLogger::ConsoleLogger()
        :level(LOG_LEVEL_DEBUG){}

    ConsoleLogger::ConsoleLogger(LogLevel level)
        :level(level){}

    void ConsoleLogger::log(const IFormatter &formatter,
        const LogContext &context, const char *msg, va_list args)
    {
        if(level >= level)
        {
            char buf[1024];
            formatter.format(buf, sizeof(buf), context, msg, args);
            std::cout<<buf<<std::endl;
        }
    }
}
