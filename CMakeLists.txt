# Minimum CMake version
cmake_minimum_required(VERSION 3.26)

# Project details
project(
  pix2tex
  VERSION 1.0
  DESCRIPTION "A C++ implementation of pix2tex.")

if(NOT XCODE
   AND NOT MSVC
   AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      Release
      CACHE STRING "Build type" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -fopenmp")

# if debug type run sanitizers

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,leak")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,leak")
endif()

# Dependencies
add_subdirectory(third-party/ggml)
add_subdirectory(third-party/fmt)

# Source files
set(SOURCE_FILES source/ui.cpp include/ui.h source/pix2tex.cpp)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link Libraries
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt ggml)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
