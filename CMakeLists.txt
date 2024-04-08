cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(game_engine)

add_library(DDS_engine SHARED
        dds_engine/src/dds_engine/Application.cpp
        dds_engine/src/dds_engine/Log.cpp
        dds_engine/src/dds_engine/Core.cpp
        dds_engine/src/Platform/Linux/LinuxWindow.cpp
        dds_engine/src/dds_engine/Layer.cpp
        dds_engine/src/dds_engine/LayerStack.cpp
        )

target_include_directories(DDS_engine PUBLIC dds_engine/src)

add_subdirectory(dds_engine/vendor/spdlog)
add_subdirectory(dds_engine/vendor/glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(DDS_engine ${OPENGL_LIBRARIES} glfw)

target_include_directories(DDS_engine PUBLIC dds_engine/vendor/spdlog/include)
target_include_directories(DDS_engine PUBLIC dds_engine/vendor/glfw/include)

target_precompile_headers(DDS_engine PRIVATE dds_engine/src/dds_enginepch.h)

target_compile_definitions(DDS_engine PUBLIC DDS_PLATFORM_LINUX)
target_compile_definitions(DDS_engine PRIVATE DDS_BUILD_LIB)
target_compile_definitions(DDS_engine PRIVATE DDS_ENABLE_ASSERTS)


add_executable(DDS_engine_test tests/TestMain.cpp)

target_link_libraries(DDS_engine_test DDS_engine)
