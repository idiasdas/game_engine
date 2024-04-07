<!-- ✅❌ -->
# game_engine

This repository follows The Cherno [tutorial](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) on game engines.

In this series, The Cherno builds [Hazel](https://github.com/TheCherno/Hazel) from scratch.

I'm following his videos with very few modifications so far. Here, Hazel is called `dds_engine` and I use the namespace `dds`. I'm focusing on Linux support and I use `cmake` instead of premake.

# External Requirements

[GFLW requirements for Linux:](https://www.glfw.org/docs/latest/compile.html)
```bash
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev
```
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

### Episode 11 (06/04/2024)

Now, running `DDS_engine_test` creates an empty window.

#### GLFW ✅

The Cherno forked [GLFW](https://github.com/glfw/glfw) to add a premake file. However, I'm using Cmake so I can add it directly.

Added [GLFW](https://github.com/glfw/glfw) as a submodule and successfully compiled it following [this](https://www.glfw.org/docs/latest/compile.html). To link it correctly, I followed the steps described [here](https://www.glfw.org/docs/latest/build_guide.html#build_link_cmake_source).

On Linux, you need to install the following packages:

```bash
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev
```

#### Created Window and LinuxWindow

Only supporting Linux for the moment.

#### Added ASSERTS (Linux Only)✅

```cpp
#define DDS_ASSERT(x, ...)
```

Using `__asm__ __volatile__("int3");` for Linux instead of `__debugbreak();` for Windows.

### Episode 12 (07/04/2024) ✅

Added window event callbacks. And now dispatching WindowCloseEvent so we can end the application.

### Episode 13 (07/04/2024) ✅

Created Layer and LayerStack.

Fixed issue on Event (missing methods).

Reorganized unnecessary precompiled headers.
