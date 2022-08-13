#ifndef XLOG_FORMATFORMATTER_HPP
#define XLOG_FORMATFORMATTER_HPP

#include "xlog/base_formatter.hpp"

namespace xlog
{
    class FormatFormatter: public BaseFormatter
    {
    public:
        virtual void format(char *buf, std::size_t size,
            const LogContext &context, const char *msg, va_list args) const;
    };
}

#endif
