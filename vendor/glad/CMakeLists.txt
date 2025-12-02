file(GLOB GLAD_SRC "src/*")

add_library(glad STATIC ${GLAD_SRC})

target_include_directories(glad PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
