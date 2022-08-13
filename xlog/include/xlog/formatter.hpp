#ifndef XLOG_FORMATTER_HPP
#define XLOG_FORMATTER_HPP

#include <cstdarg>
#include <string>

namespace xlog
{
    struct LogContext;

    class IFormatter
    {
    public:
        virtual ~IFormatter(){}
        virtual void format(char *buf, std::size_t size,
            const LogContext &context, const char *msg, va_list args) const
            = 0;
    };
}

#endif
