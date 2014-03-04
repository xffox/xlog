#ifndef XLOG_BASEFORMATTER_H
#define XLOG_BASEFORMATTER_H

#include "xlog/IFormatter.h"

namespace xlog
{
    class BaseFormatter: public IFormatter
    {
    public:
        virtual void format(char *buf, std::size_t size,
            const LogContext &context, const char *msg, va_list args) const;
    };
}

#endif
