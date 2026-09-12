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
endforeach()