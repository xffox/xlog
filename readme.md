Dead simple logging library. Configurable at build time.

# Usage

With CMake:
```
find_package(XLog REQUIRED)
```

The main header is `xlog/xlog.hpp`.

Logging configuration:
```
XLOG_DEFINE_CONFIG(xlog::DEFAULT_LOG_LEVEL, xlog::DefaultLogger, xlog::DefaultFormatter)
```
Should be defined once.

Logging:
```
xlog::log().debug("main", "this is debug '%s'", "debug");
xlog::log().info("main", "this is info: '%s'", "info");
xlog::log().warning("main", "this is warning '%s'", "warn");
xlog::log().error("main", "this is error: '%d'", 42);
```

# Building

Uses CMake.

Can be as simple as
```
mkdir build; cd build
cmake ..
cmake --build .
```
