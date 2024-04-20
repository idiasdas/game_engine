<!-- ✅❌ -->
# game_engine

This repository follows [The Cherno tutorial](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) on game engines where he builds [Hazel](https://github.com/TheCherno/Hazel) from scratch.

I'm following his videos with very few modifications so far. Here, [Hazel](https://github.com/TheCherno/Hazel) is called `DDS engine` and uses the namespace `dds`. I'm focusing on Linux support and using `CMake` instead of premake.

[Hazel](https://github.com/TheCherno/Hazel) is an open-source project using an [Apache](https://github.com/TheCherno/Hazel/blob/master/LICENSE)[ License](https://github.com/TheCherno/Hazel/blob/master/LICENSE). `DDS engine` uses the same [license](./LICENSE).

# Requirements

GFLW [requirements](https://www.glfw.org/docs/latest/compile.html) for Linux:

```bash
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev
```

> [!NOTE]
> I have changed to X11 instead of Wayland and this requirement is likely deprecated. However, I have not yet tested it so I will leave this in the documentation until I have the time to make sure this is the case.
# Quick Start

Clone this repo:

```bash
git clone https://github.com/idiasdas/game_engine.git
```

Initialize the submodules:

```bash
$ git submodule update --init
```

Configure CMake with:

```bash
$ cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/Debug
```

You should now, hopefully, have the directory `game_engine/build/Debug/` with all the necessary CMake files. In this directory, you can use `make` to build the engine executable.

> [!NOTE]
> The `CMakeLists.txt` automatically detects all the source files within the project. ***However***, you must redo the configuration step above whenever you add new files instead of simply running `make` to build the executable.

# Project Status

- [x] **Episode 1:**
- [x] **Episode 2:**
- [x] **Episode 3:**
- [x] **Episode 4:**
- [x] **Episode 5:** Entry point
- [x] **Episode 6:** Logging
- [x] **Episode 7:** Premake
    - Using CMake instead
- [x] **Episode 8:**
- [x] **Episode 9:** Event System
- [x] **Episode 10:** Precompiled Headers
    - Using CMake to achieve the same
- [x] **Episode 11:** Window Abstraction and GLFW
    - Added GLFW using CMake instead of Premake.
    - Supporting Linux instead of Windows.
- [x] **Episode 12:** Window Events
- [x] **Episode 13:** Layers
    - Created Layer and LayerStack.
    - Fixed issue on Event (missing methods).
    - Reorganized unnecessary precompiled headers.
- [x] **Episode 14:** Modern OpenGL
    - Added GLAD with CMake.
- [x] **CMake Export:**
    - I'm now using the `generate_export_header` method from CMake instead of doing it manually at `Core.h` as The Cherno did.
- [x] **Episode 15:** ImGui
    - Using the most recent release of ImGui. Many files are different from the tutorial but so far everything is working properly.
- [x] **Episode 16:** ImGui Events
    - Added KeyMap between ImGui and GLFW.
    - Created KeyTyped Event.
    - Now you can type on the console.
- [x] **Episode 19:** Input Polling
- [x] **Episode 20:** Key and Mouse Codes
    - Using codes defined in `GLFW/glf3.h`.
- [x] **Episode 21:** Maths
    - Added glm submodule.
    - Included glm into the CMake project and `Application.cpp`.
- [x] **Episode 22:** ImGui Docking and Viewports
    - Wayland does not support `glfwSetWindowPosCallback` so Viewport does not work properly. Therefore, I have changed to X11 instead of Wayland.


# Third-Party Software

The following are all the submodules currently used:

- [spdlog](https://github.com/gabime/spdlog)
- [GLFW](https://github.com/glfw/glfw)
- [GLAD](https://glad.dav1d.de/)
- [ImGui](https://github.com/ocornut/imgui)
- [glm](https://github.com/g-truc/glm)
---
