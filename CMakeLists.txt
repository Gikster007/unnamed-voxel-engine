# CMakeList.txt : CMake project for unnamed-voxel-engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("unnamed-voxel-engine")

# Add all .cpp files in the source directory to the project
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add main.cpp to the sources
list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Add source files to the project
add_executable(unnamed-voxel-engine ${SOURCES})

# Includes
target_include_directories(unnamed-voxel-engine PRIVATE "./src/")

# Precompiled Headers
target_precompile_headers(unnamed-voxel-engine PRIVATE "./src/precomp.h")

# Add source files to the program
target_sources(unnamed-voxel-engine PRIVATE ${SOURCES})

# Add GLAD to the project
add_library(GLAD "libs/glad.c")

# Link GLAD to your target executable or library
target_link_libraries(unnamed-voxel-engine GLAD)

# Add GLFW to the project
add_subdirectory(libs/glfw)

# Link GLFW to your target executable or library
target_link_libraries(unnamed-voxel-engine glfw)

# Set the path to the libs in libs folder
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/libs/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/libs/glm)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET unnamed-voxel-engine PROPERTY CXX_STANDARD 20)
endif()