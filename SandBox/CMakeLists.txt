add_executable(sandbox Src/Sandbox.cpp)

target_include_directories(sandbox PUBLIC ${CMAKE_SOURCE_DIR}/Spark/Src)
target_link_libraries(sandbox PRIVATE SparkLib)
