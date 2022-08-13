#include "lib.h"

#include "xlog/xlog.hpp"

namespace lib
{
    void testLog()
    {
        xlog::log().debug("testLog", "testing");
    }
}
