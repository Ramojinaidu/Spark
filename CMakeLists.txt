cmake_minimum_required(VERSION 3.28.*)

project(Spark
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/${CMAKE_BUILD_TYPE}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/${CMAKE_BUILD_TYPE}/lib")

add_subdirectory(Spark)
add_subdirectory(SandBox)
