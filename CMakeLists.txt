cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "usr/bin/g++-4.2")

add_compile_definitions(DDS_BUILD_LIB)

project(DDS_engine)

add_library(DDS_engine SHARED src/dds_engine/Application.cpp)

target_include_directories(DDS_engine PUBLIC src)

add_subdirectory(vendor/spdlog)

target_include_directories(DDS_engine PUBLIC vendor/spdlog/include)

add_executable(DDS_engine_test tests/TestMain.cpp)

target_link_libraries(DDS_engine_test DDS_engine)
