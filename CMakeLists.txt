# Minimum CMake version
cmake_minimum_required(VERSION 3.26)

# Project details
project(
  nougat
  VERSION 1.0
  DESCRIPTION "A simple project using fmt"
  LANGUAGES CXX)

# Dependencies
find_package(fmt REQUIRED)


# Add third-party dependencies
add_subdirectory(third-party/ggml)


# Source files
set(SOURCE_FILES nougat.cpp)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt ggml)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
