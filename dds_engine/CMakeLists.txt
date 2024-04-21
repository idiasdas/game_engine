# Visibility
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)


# ---------------------------------------------------
# Engine static library
file(GLOB_RECURSE MY_SOURCES "src/*.cpp")
# add_library(DDS_engine SHARED ${MY_SOURCES})
add_library(DDS_engine STATIC ${MY_SOURCES})
target_include_directories(DDS_engine PUBLIC src)

# ---------------------------------------------------
# Export header
include(GenerateExportHeader)
generate_export_header(DDS_engine EXPORT_FILE_NAME include/dds_export.h)
target_include_directories(DDS_engine PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)

# ---------------------------------------------------
# External libraries

# Build static libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Using X11 instead of Wayland to support ImGui docking
set(GLFW_BUILD_X11 ON)
set(GLFW_BUILD_WAYLAND OFF)

# Add subdirectories
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/glm)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Compile options
# target_compile_options(spdlog PRIVATE -fPIC) # Required for shared libraries
# target_compile_options(glad PRIVATE -fPIC) # Required for shared libraries
# target_compile_options(imgui PRIVATE -fPIC) # Required for shared libraries
target_compile_definitions(DDS_engine PUBLIC GLFW_INCLUDE_NONE) # Don't include OpenGL headers

# Link libraries
target_link_libraries(DDS_engine PUBLIC
                    ${OPENGL_LIBRARIES}
                    glfw
                    spdlog
                    glad
                    imgui
                    glm::glm
)

# Include directories
target_include_directories(DDS_engine PUBLIC vendor/spdlog/include)
target_include_directories(DDS_engine PUBLIC vendor/glfw/include)
target_include_directories(DDS_engine PUBLIC vendor/imgui)
target_include_directories(DDS_engine PUBLIC vendor/glm)
# ---------------------------------------------------
#  Precompiled headers
target_precompile_headers(DDS_engine PRIVATE src/dds_enginepch.h)
# ---------------------------------------------------
# Preprocessor definitions
target_compile_definitions(DDS_engine PRIVATE DDS_ENABLE_ASSERTS)
# ---------------------------------------------------
# Compile options
target_compile_options(DDS_engine PRIVATE -Wall)
# ---------------------------------------------------
