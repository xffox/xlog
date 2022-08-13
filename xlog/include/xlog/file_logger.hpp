#ifndef XLOG_FILELOGGER_HPP
#define XLOG_FILELOGGER_HPP

#include <string>
#include <fstream>

#include "xlog/logger.hpp"
#include "xlog/log_level.hpp"

namespace xlog
{
    class IFormatter;

    class FileLogger: public ILogger
    {
    public:
        struct Params
        {
            Params(const std::string &filename)
                :filename(filename){}
            std::string filename;
        };

    public:
        FileLogger(const Params &params);

        virtual void log(const IFormatter &formatter,
            const LogContext &context, const char *msg, va_list args);

    private:
        FileLogger(const FileLogger&);
        FileLogger &operator=(const FileLogger&);

    private:
        std::ofstream stream;
    };
}

#endif
