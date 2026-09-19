cmake_minimum_required(VERSION 3.20)
project(c_plus_plus CXX)

# Enforce C++20 standard globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable strict compiler warnings for high code quality
if(MSVC)
    # MSVC warnings: /W4 (high warnings), /WX (treat warnings as errors)
    add_compile_options(/W4)
else()
    # GCC / Clang warnings: -Wall -Wextra -Wpedantic
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Register your two top-level subdirectories
add_subdirectory(learning-projects)
add_subdirectory(app-projects)