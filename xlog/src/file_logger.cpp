#include "xlog/file_logger.hpp"

#include "xlog/formatter.hpp"
#include "xlog/log_context.hpp"

namespace xlog
{
    FileLogger::FileLogger(const Params &params)
        :stream(params.filename.c_str(),
            std::ios::out)
    {
    }

    void FileLogger::log(const IFormatter &formatter,
        const LogContext &context, const char *msg, va_list args)
    {
        char buf[1024];
        formatter.format(buf, sizeof(buf), context, msg, args);
        stream<<buf<<std::endl;
    }
}
