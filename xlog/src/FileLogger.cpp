#include "xlog/FileLogger.h"

#include "xlog/IFormatter.h"
#include "xlog/LogContext.h"
#include "xlog/xlog.h"

namespace xlog
{
    FileLogger::FileLogger(const Params &params)
        :level(params.level), stream(params.filename.c_str(),
            std::ios::out)
    {
    }

    void FileLogger::log(const IFormatter &formatter,
        const LogContext &context, const char *msg, va_list args)
    {
        if(context.level >= level)
        {
            char buf[1024];
            formatter.format(buf, sizeof(buf), context, msg, args);
            stream<<buf<<std::endl;
        }
    }
}
