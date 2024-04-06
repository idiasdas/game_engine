<!-- ✅❌ -->
# game_engine

This repository follows The Cherno [tutorial](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) on game engines.

In this series, The Cherno builds [Hazel](https://github.com/TheCherno/Hazel) from scratch.

I'm following his videos with very few modifications so far. Here, Hazel is called `dds_engine` and I use the namespace `dds`. I'm focusing on Linux support and I use `cmake` instead of premake.

# Usage

You can compile the main branch using:

```bash
cd scripts
./debug.sh
```

This script creates the executable `build/debug/DDS_engine_test`.

## Features

### Logging ✅

We are using `spdlog` to do so. As in Hazel, `dds_engine` provides the following macros:

```cpp
// Core log macros
#define DDS_CORE_TRACE(...)    ::dds::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DDS_CORE_INFO(...)     ::dds::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DDS_CORE_WARN(...)     ::dds::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DDS_CORE_ERROR(...)    ::dds::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DDS_CORE_FATAL(...)    ::dds::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DDS_TRACE(...)         ::dds::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DDS_INFO(...)          ::dds::Log::GetClientLogger()->info(__VA_ARGS__)
#define DDS_WARN(...)          ::dds::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DDS_ERROR(...)         ::dds::Log::GetClientLogger()->error(__VA_ARGS__)
#define DDS_FATAL(...)         ::dds::Log::GetClientLogger()->fatal(__VA_ARGS__)
```

### Events ✅

We can now create events as done in [episode 9](https://www.youtube.com/watch?v=xnopUoZbMEk&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=9&pp=iAQB).


### Precompiled Headers ✅

[Episode 10](https://www.youtube.com/watch?v=UQ718BrbQ5E&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=10) adds precompiled headers to Hazel using premake. The same was done to DDS Engine with Cmake.
