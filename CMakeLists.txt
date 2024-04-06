cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(DDS_engine)

add_library(DDS_engine SHARED
        src/dds_engine/Application.cpp
        src/dds_engine/Log.cpp
        src/dds_engine/Core.cpp)

target_include_directories(DDS_engine PUBLIC src
        src/dds_engine/Events)

add_subdirectory(vendor/spdlog)

target_include_directories(DDS_engine PUBLIC vendor/spdlog/include)
target_precompile_headers(DDS_engine PRIVATE src/dds_enginepch.h)

target_compile_definitions(DDS_engine PUBLIC DDS_PLATFORM_LINUX)
target_compile_definitions(DDS_engine PRIVATE DDS_BUILD_LIB)


add_executable(DDS_engine_test tests/TestMain.cpp)

target_link_libraries(DDS_engine_test DDS_engine)
