cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(game_engine)

# Static library DDS_Engine
add_subdirectory(dds_engine)

# Sandbox executable DDS_SandboxApp
add_subdirectory(sandbox)
