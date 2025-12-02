

project(Spark)

file(GLOB SPARK_SRC "src/*")


set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glad glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui imgui)

add_compile_definitions(GLFW_INCLUDE_NONE)

add_library(Spark STATIC ${SPARK_SRC})

target_link_libraries(Spark PRIVATE glfw glad imgui)


target_include_directories(Spark PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)
