
#--- GLFW ---
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_WAYLAND OFF)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW)

#--- spdlog ---
set(SPDLOG_DISABLE_DEFAULT_LOGGER ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog)

#--- imgui ---
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)

#--- glad ---
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad)
