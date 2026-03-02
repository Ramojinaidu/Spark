
file(GLOB_RECURSE
    SANDBOX_SRC
    LIST_DIRECTORIES true
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "Src/*.cpp" "Src/*.h"
)
# set(SANDBOX_SRC Src/Sandbox.cpp Src/SandboxLayerTest.cpp)
add_executable(sandbox ${SANDBOX_SRC})

target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR}/Spark/Src)
target_link_libraries(sandbox PRIVATE SparkLib)
