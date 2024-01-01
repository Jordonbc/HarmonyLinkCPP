cmake_minimum_required(VERSION 3.10)
project(HarmonyLinkLib VERSION 0.0.1)

configure_file(include/Version.h.in Version.generated.h)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically add all .cpp files in the src directory
file(GLOB_RECURSE LIB_SOURCES "src/*.cpp" "src/*.h")
file(GLOB_RECURSE LIB_INCLUDES "include/*.h" "include/*.h.in")

# Add library
add_library(HarmonyLinkLib SHARED ${LIB_SOURCES} ${LIB_INCLUDES})

target_include_directories(HarmonyLinkLib 
    PRIVATE 
        "${PROJECT_SOURCE_DIR}/src"
    PUBLIC 
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/include"
)

target_compile_definitions(HarmonyLinkLib PRIVATE HARMONYLINKLIB_EXPORTS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(YourTarget PRIVATE "DEBUG_MODE")
endif()

# Set output directories for all build types
foreach(TYPE IN ITEMS DEBUG RELEASE)
    string(TOUPPER ${TYPE} TYPE_UPPER)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
        LIBRARY_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
        ARCHIVE_OUTPUT_DIRECTORY_${TYPE_UPPER} "${CMAKE_BINARY_DIR}/bin/${TYPE}/${PROJECT_NAME}"
    )
endforeach()
