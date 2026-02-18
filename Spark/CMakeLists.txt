include(dependencies.cmake)

file(GLOB_RECURSE
    SPARK_SRC
    LIST_DIRECTORIES true
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "Src/*.cpp" "Src/*.h"
)


list(APPEND SPARK_BUILD_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)


add_library(SparkLib STATIC)

target_sources(SparkLib PUBLIC ${SPARK_SRC})

target_link_libraries(SparkLib PRIVATE glfw spdlog_header_only)

target_precompile_headers(SparkLib PUBLIC "pch.h")

target_include_directories(SparkLib PUBLIC
    ${SPARK_BUILD_INCLUDE_DIRS}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Src>
)



add_compile_definitions(SparkLib GLFW_INCLUDE_NONE)

if (CMAKE_BUILD_TYPE STREQUAL Debug)

    message(STATUS "Configuring for Debug build type")
    target_compile_definitions(SparkLib PUBLIC SPARK_DEBUG)

elseif (CMAKE_BUILD_TYPE STREQUAL Release)

    message(STATUS "Configuring for Release build type")
    target_compile_definitions(SparkLib PUBLIC SPARK_RELEASE)
endif()
