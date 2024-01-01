cmake_minimum_required(VERSION 3.10)
project(HarmonyLinkProject)

if(WIN32)
  add_definitions(-DBUILD_WINDOWS)
endif()

if(UNIX AND NOT APPLE)
  add_definitions(-DBUILD_LINUX)
endif()

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
