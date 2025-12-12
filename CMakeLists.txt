
cmake_minimum_required(VERSION 3.28.*)

project(Spark
    VERSION 1.0.0
    LANGUAGES CXX
)


string(COMPARE EQUAL "${CMAKE_CURRENT_SOURCE_DIR}"
                "${CMAKE_SOURCE_DIR}"
                SPARK_STANDALONE)

option(SPARK_BUILD_TESTS "Build the SPARK test programs" ${SPARK_STANDALONE})
option(SPARK_INSTALL "Generate installation target" ON)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(SPARK_BUILD_TESTS)
    add_subdirectory(test)
endif()
