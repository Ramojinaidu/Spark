include(dependencies.cmake)

file(GLOB SPARK_MAIN "src/Spark/*")
file(GLOB SPARK_CORE_SRC "src/Spark/Core/*")
file(GLOB SPARK_MULTI_PLATFORM_SRC "src/Platform/MultiPlatform/*")

list(APPEND SPARK_SRC ${SPARK_MAIN}
                    ${SPARK_CORE_SRC}
                    ${SPARK_MULTI_PLATFORM_SRC}
)

list(APPEND SPARK_BUILD_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


if(LINUX)

    file(GLOB SPARK_LINUX_PLATFORM_SRC "src/Platform/Linux/*")
    list(APPEND SPARK_SRC ${SPARK_LINUX_PLATFORM_SRC})

endif()
if(WINCE)

    file(GLOB SPARK_WINDOWS_PLATFORM_SRC "src/Platform/Windows/*")
    list(APPEND SPARK_SRC ${SPARK_WINDOWS_PLATFORM_SRC})

endif()

add_compile_definitions(GLFW_INCLUDE_NONE)

if (CMAKE_BUILD_TYPE STREQUAL Debug)

    message(STATUS "Configuring for Debug build type")
    add_compile_definitions(SPARK_DEBUG)

elseif (CMAKE_BUILD_TYPE STREQUAL Release)

    message(STATUS "Configuring for Release build type")

endif()


add_library(Spark STATIC)
target_sources(Spark PUBLIC ${SPARK_SRC})

target_link_libraries(Spark PRIVATE glfw glad imgui)

target_include_directories(Spark PUBLIC
    ${SPARK_BUILD_INCLUDE_DIRS}
)
