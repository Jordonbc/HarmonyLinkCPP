cmake_minimum_required(VERSION 3.10)
project(HarmonyLinkProject)

# Set global output directories for all build types
foreach(TYPE IN ITEMS DEBUG RELEASE)
    string(TOUPPER ${TYPE} TYPE_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}")
endforeach()

# Add the library and executable directories
add_subdirectory(HarmonyLinkLib)
add_subdirectory(HarmonyLinkTest)
