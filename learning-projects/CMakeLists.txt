# 1. STANDALONE FALLBACK BOILERPLATE
# If CLion accidentally targets this folder as the root, these lines satisfy the missing project errors
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.20)
    project(learning_projects CXX)

    # Enforce C++26 standard globally if opened standalone
    set(CMAKE_CXX_STANDARD 26)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    if(NOT MSVC)
        add_compile_options(-Wall -Wextra -Wpedantic)
    endif()
endif()

# 2. YOUR ORIGINAL RECURSIVE LOOP (AUTOMATION MAGIC)
# Recursively find every .cpp file in all subdirectories of learning-projects
file(GLOB_RECURSE LEARNING_SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(SOURCE_FILE ${LEARNING_SOURCES})
    # Extract file name without directory or extension (e.g. "std_vector")
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

    # Get relative path to create a unique target name if duplicate filenames exist
    file(RELATIVE_PATH REL_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${SOURCE_FILE})
    get_filename_component(REL_DIR ${REL_PATH} DIRECTORY)

    # Replace slashes with underscores for clean target names (e.g. "arrays_and_vectors_std_vector")
    if(REL_DIR)
        string(REPLACE "/" "_" SAFE_DIR ${REL_DIR})
        set(EXECUTABLE_NAME "${SAFE_DIR}_${TARGET_NAME}")
    else()
        set(EXECUTABLE_NAME "${TARGET_NAME}")
    endif()

    # Register each snippet as a runnable binary
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    # The MinGW Fix: Automatically unlock std::println for every dynamic file
    if(NOT MSVC)
        target_link_libraries(${EXECUTABLE_NAME} PRIVATE stdc++exp)
    endif()
endforeach()
