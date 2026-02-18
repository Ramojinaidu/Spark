
#--- GLFW ---
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_WAYLAND OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW)

#--- spdlog ---
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog)
