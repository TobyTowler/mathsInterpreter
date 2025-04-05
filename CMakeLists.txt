cmake_minimum_required(VERSION 3.14)
project(mathsInterpreter)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (Make headers accessible)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create executable
add_executable(Interpreter ${SRC_FILES})
