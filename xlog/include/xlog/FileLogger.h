#ifndef XLOG_FILELOGGER_H
#define XLOG_FILELOGGER_H

#include <string>
#include <fstream>

#include "xlog/ILogger.h"
#include "xlog/LogLevel.h"

namespace xlog
{
    class IFormatter;

    class FileLogger: public ILogger
    {
    public:
        struct Params
        {
            Params(const std::string &filename, LogLevel level)
                :filename(filename), level(level){}
            std::string filename;
            LogLevel level;
        };

    public:
        FileLogger(const Params &params);

        virtual void log(const IFormatter &formatter,
            const LogContext &context, const char *msg, va_list args);

    private:
        FileLogger(const FileLogger&);
        FileLogger &operator=(const FileLogger&);

    private:
        const LogLevel level;
        std::ofstream stream;
    };
}

#endif
