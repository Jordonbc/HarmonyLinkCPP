cmake_minimum_required(VERSION 3.10)
project(HarmonyLinkLib)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically add all .cpp and .h/.hpp files in the src directory
file(GLOB_RECURSE LIB_SOURCES "src/*.cpp")
file(GLOB_RECURSE LIB_HEADERS "src/*.h" "src/*.hpp")

# Add library
add_library(HarmonyLinkLib SHARED ${LIB_SOURCES} ${LIB_HEADERS})

# Specify include directories
target_include_directories(HarmonyLinkLib PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/src")

target_compile_definitions(HarmonyLinkLib PRIVATE HARMONYLINKLIB_EXPORTS)

# Set output directories for all build types
foreach(TYPE IN ITEMS DEBUG RELEASE)
    string(TOUPPER ${TYPE} TYPE_UPPER)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
        LIBRARY_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
        ARCHIVE_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
    )
endforeach()
