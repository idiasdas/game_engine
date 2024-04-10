cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(game_engine)

# Visibility
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

include(GenerateExportHeader)

# ---------------------------------------------------
# Engine shared library
file(GLOB_RECURSE MY_SOURCES "dds_engine/src/*.cpp")
add_library(DDS_engine SHARED ${MY_SOURCES})
target_include_directories(DDS_engine PUBLIC dds_engine/src)

generate_export_header(DDS_engine EXPORT_FILE_NAME include/dds_export.h)
target_include_directories(DDS_engine PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
# ---------------------------------------------------
# External libraries

# Build static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Add subdirectories
add_subdirectory(dds_engine/vendor/spdlog)
add_subdirectory(dds_engine/vendor/glfw)
add_subdirectory(dds_engine/vendor/glad)
add_subdirectory(dds_engine/vendor/imgui)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Compile options
target_compile_options(spdlog PRIVATE -fPIC) # Required for shared libraries
target_compile_options(glad PRIVATE -fPIC) # Required for shared libraries
target_compile_options(imgui PRIVATE -fPIC) # Required for shared libraries
target_compile_definitions(DDS_engine PUBLIC GLFW_INCLUDE_NONE) # Don't include OpenGL headers

# Link libraries
target_link_libraries(DDS_engine ${OPENGL_LIBRARIES} glfw spdlog glad imgui)

# Include directories
target_include_directories(DDS_engine PUBLIC dds_engine/vendor/spdlog/include)
target_include_directories(DDS_engine PUBLIC dds_engine/vendor/glfw/include)
target_include_directories(DDS_engine PUBLIC dds_engine/vendor/imgui)
# ---------------------------------------------------
#  Precompiled headers
target_precompile_headers(DDS_engine PRIVATE dds_engine/src/dds_enginepch.h)
# ---------------------------------------------------
# Preprocessor definitions
target_compile_definitions(DDS_engine PRIVATE DDS_ENABLE_ASSERTS)
# ---------------------------------------------------
# This test acts as sandbox for the moment
add_executable(DDS_engine_test tests/TestMain.cpp)
target_link_libraries(DDS_engine_test DDS_engine)
