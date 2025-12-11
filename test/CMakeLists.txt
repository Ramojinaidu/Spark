project(Spark_test)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Spark Lib/Spark)

file(GLOB SPARK_TEST_SRC "src/*")

add_executable(Spark_test ${SPARK_TEST_SRC})

target_link_libraries(Spark_test PUBLIC Spark)

target_include_directories(Spark_test PUBLIC ../Spark/src)
