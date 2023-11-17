# Minimum CMake version
cmake_minimum_required(VERSION 3.26)

# Project details
project(
  pix2tex
  VERSION 1.0
  DESCRIPTION "A C++ GUI implementation of pix2tex."
  LANGUAGES CXX)

# Dependencies
find_package(fmt REQUIRED)
find_package(imgui REQUIRED)
# Add third-party dependencies
add_subdirectory(third-party/ggml)

# Source files
set(SOURCE_FILES source/main.cpp source/ui.cpp include/ui.h source/modle.cpp
                 include/modle.h)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link Libraries
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt imgui::imgui ggml)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
