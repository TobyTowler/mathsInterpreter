cmake_minimum_required(VERSION 3.14)
project(mathsInterpreter)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (Make headers accessible)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Find packages
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

# Create executable FIRST
add_executable(Interpreter ${SRC_FILES})

# THEN link libraries (use the same name as add_executable)
target_link_libraries(Interpreter
    fmt::fmt
    spdlog::spdlog
)
