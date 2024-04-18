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

- **Episode 1:** ✅
- **Episode 2:** ✅
- **Episode 3:** ✅
- **Episode 4:** ✅
- **Episode 5:** Entry point ✅
- **Episode 6:** Logging ✅
- **Episode 7:** Premake ✅
    - Using CMake instead
- **Episode 8:** ✅
- **Episode 9:** Event System ✅
- **Episode 10:** Precompiled Headers ✅
    - Using CMake to achieve the same
- **Episode 11:** Window Abstraction and GLFW ✅
    - Added [GLFW](https://github.com/glfw/glfw) using CMake instead of Premake.
    - Supporting Linux instead of Windows.
- **Episode 12:** Window Events ✅
- **Episode 13:** Layers ✅
    - Created Layer and LayerStack.
    - Fixed issue on Event (missing methods).
    - Reorganized unnecessary precompiled headers.
- **Episode 14:** Modern OpenGL ✅
    - Added [GLAD](https://glad.dav1d.de/) with CMake.
- **CMake Export:** ✅
    - I'm now using the `generate_export_header` method from CMake instead of doing it manually at `Core.h` as The Cherno did.
- **Episode 15:** ImGui ✅
    - Using the most recent release of ImGui. Many files are different from the tutorial but so far everything is working properly.
- **Episode 16:** ImGui Events ✅
    - Added KeyMap between ImGui and GLFW.
    - Created KeyTyped Event.
    - Now you can type on the console.
- **Episode 19:** Input Polling ✅
---
