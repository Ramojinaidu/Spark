project(Spark_app)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Spark Lib/Spark)

file(GLOB SPARK_APP_SRC "src/*")

add_executable(Spark_app ${SPARK_APP_SRC})

target_link_libraries(Spark_app PRIVATE Spark)
target_include_directories(Spark_app PUBLIC ../Spark/src)
