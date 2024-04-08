cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(game_engine)

# ---------------------------------------------------
# Engine shared library
file(GLOB_RECURSE MY_SOURCES "dds_engine/src/*.cpp")
add_library(DDS_engine SHARED ${MY_SOURCES})
target_include_directories(DDS_engine PUBLIC dds_engine/src)
# ---------------------------------------------------
# External libraries
add_subdirectory(dds_engine/vendor/spdlog)
add_subdirectory(dds_engine/vendor/glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(DDS_engine ${OPENGL_LIBRARIES} glfw)

target_include_directories(DDS_engine PUBLIC dds_engine/vendor/spdlog/include)
target_include_directories(DDS_engine PUBLIC dds_engine/vendor/glfw/include)
# ---------------------------------------------------
#  Precompiled headers
target_precompile_headers(DDS_engine PRIVATE dds_engine/src/dds_enginepch.h)
# ---------------------------------------------------
# Preprocessor definitions
target_compile_definitions(DDS_engine PUBLIC DDS_PLATFORM_LINUX)
target_compile_definitions(DDS_engine PRIVATE DDS_BUILD_LIB)
target_compile_definitions(DDS_engine PRIVATE DDS_ENABLE_ASSERTS)
# ---------------------------------------------------
# This test acts as sandbox for the moment
add_executable(DDS_engine_test tests/TestMain.cpp)
target_link_libraries(DDS_engine_test DDS_engine)
