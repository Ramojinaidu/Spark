project(Spark)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glad glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui imgui)

file(GLOB SPARK_SRC "src/Spark/*")
file(GLOB SPARK_CORE_SRC "src/Spark/Core/*")


# add_compile_definitions(GLFW_INCLUDE_NONE)

add_library(Spark STATIC)
target_sources(Spark PUBLIC ${SPARK_SRC} ${SPARK_CORE_SRC})

target_link_libraries(Spark PRIVATE glfw glad imgui)

target_include_directories(Spark PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glad/include)


target_include_directories(Spark PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)
