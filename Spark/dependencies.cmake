
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glad glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui imgui)
