# Sample Version Of CMake minimum setup
cmake_minimum_required(VERSION 3.15)

#Project name and version
project(RaylibBasic VERSION 0.1 LANGUAGES CXX)

# Set path 
set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(EXTERNAL_ROOT_DIR "${PROJECT_ROOT_DIR}/External")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_DIR}/Bin")

message(STATUS "PROJECT_ROOT_DIR: ${PROJECT_ROOT_DIR}")
message(STATUS "EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")

# Compiler setup
if (MSVC)
    add_compile_options(/W4)
else()
    # Clang all warning
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# configure header file to pass version number
configure_file("${PROJECT_ROOT_DIR}/Source/CMakeConfig.h.in" "${PROJECT_ROOT_DIR}/Source/CMakeConfig.h")

# Add source to your executable :
add_executable(${PROJECT_NAME})

# Setup generated project
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT RaylibBasic)

# Add sources (sets SOURCE_HEADERS_CLIENT and SOURCE_CPPS_CLIENT in this scope)
add_subdirectory(Source)

# Replicate the Source folder hierarchy as VS solution filters
source_group(TREE "${PROJECT_ROOT_DIR}/Source" PREFIX "Source" FILES ${SOURCE_HEADERS_CLIENT} ${SOURCE_CPPS_CLIENT})

# Add libraries HEADER
target_include_directories(${PROJECT_NAME} PUBLIC "${EXTERNAL_ROOT_DIR}/raylib/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${EXTERNAL_ROOT_DIR}")

# Determine architecture folder (x64 / Win32) like the MSBuild $(Platform) macro
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(RAYLIB_ARCH "x64")
else()
    set(RAYLIB_ARCH "Win32")
endif()

# Link libraries BINARY
# $<CONFIG> replaces the MSBuild $(Configuration) macro and works with every generator (Ninja, VS, ...)
target_link_directories(${PROJECT_NAME} PUBLIC "${EXTERNAL_ROOT_DIR}/raylib/lib/${RAYLIB_ARCH}/$<CONFIG>")
target_link_libraries(${PROJECT_NAME} raylib winmm)

# set Raylib definitions
add_compile_definitions(GRAPHICS_API_OPENGL_33 PLATFORM_DESKTOP)

# set target properties
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)