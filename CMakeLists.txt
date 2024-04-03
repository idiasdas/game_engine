cmake_minimum_required(VERSION 3.0)

project(DDS_engine)

add_library(DDS_engine SHARED src/dds_engine/Application.cpp)

target_include_directories(DDS_engine PUBLIC src)

add_executable(DDS_engine_test tests/TestMain.cpp)


target_link_libraries(DDS_engine_test DDS_engine)
