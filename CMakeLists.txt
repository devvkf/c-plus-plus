cmake_minimum_required(VERSION 3.20)
project(c_plus_plus CXX)

# Enforce C++26 standard globally
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT MSVC)
    add_compile_options(-Wall -Wextra -Wpedantic)
else()
    # Use the latest C++ standard on MSVC (C++26 / C++23 preview)
    add_compile_options(/std:c++latest)
endif()

add_subdirectory(learning-projects)
add_subdirectory(app-projects)
