# Standalone fallback boilerplate
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.20)
    project(learning_projects CXX)

    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    if(NOT MSVC)
        add_compile_options(-Wall -Wextra -Wpedantic)
    endif()
endif()

# Recursively find every .cpp file in all subdirectories of learning-projects
add_executable(namespaces_unit_converter namespaces/unit_converter.cpp)

foreach(SOURCE_FILE ${LEARNING_SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

    file(RELATIVE_PATH REL_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${SOURCE_FILE})
    get_filename_component(REL_DIR ${REL_PATH} DIRECTORY)

    if(REL_DIR)
        string(REPLACE "/" "_" SAFE_DIR ${REL_DIR})
        set(EXECUTABLE_NAME "${SAFE_DIR}_${TARGET_NAME}")
    else()
        set(EXECUTABLE_NAME "${TARGET_NAME}")
    endif()

    # Register each snippet as a runnable binary
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    if(NOT MSVC)
        # 1. THE NATIVE WORKAROUND FLAG: Fixes the float16 bug in the MinGW <print> header
        target_compile_definitions(${EXECUTABLE_NAME} PRIVATE __STDCPP_FLOAT16_T__=1)

        # 2. THE LINKER FLAG: Links the experimental standard library components
        target_link_libraries(${EXECUTABLE_NAME} PRIVATE stdc++exp)
    endif()
endforeach()
