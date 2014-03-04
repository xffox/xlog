#include "xlog/BaseFormatter.h"

#include <cstdio>

namespace xlog
{
    void BaseFormatter::format(char *buf, std::size_t size,
        const LogContext&, const char *msg, va_list args) const
    {
        vsnprintf(buf, size, msg, args);
    }
}
