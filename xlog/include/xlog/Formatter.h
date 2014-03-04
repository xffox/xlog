#ifndef XLOG_FORMATTER_H
#define XLOG_FORMATTER_H

#include "xlog/BaseFormatter.h"

namespace xlog
{
    class Formatter: public BaseFormatter
    {
    public:
        virtual void format(char *buf, std::size_t size,
            const LogContext &context, const char *msg, va_list args) const;
    };
}

#endif
