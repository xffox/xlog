#include "lib.h"

#include "xlog/xlog.h"

namespace lib
{
    void testLog()
    {
        xlog::log().debug("testLog", "testing");
    }
}
