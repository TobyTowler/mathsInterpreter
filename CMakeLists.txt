cmake_minimum_required(VERSION 3.10)

project(mathsInterpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mathsInterpreter
    src/main.cpp
    src/lexer.cpp
)

# Include directories (optional, if you have header files in include/)
target_include_directories(MyExecutable PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link additional libraries (optional)
# target_link_libraries(MyCppExecutable PRIVATE some_library)

# Add custom compiler options (optional)
# target_compile_options(MyCppExecutable PRIVATE -Wall -Wextra -pedantic)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
