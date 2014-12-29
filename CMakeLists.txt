cmake_minimum_required (VERSION 2.8)
project (opengl-skeleton)

# put the executable into the bin directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# c++11 activation
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

# find every source file
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)

# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE STRING "" FORCE)
set(GLFW_INSTALL OFF CACHE STRING "" FORCE)
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)

# glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED "" OFF)
add_subdirectory(lib/glew)
include_directories(lib/glew/include lib/glew/src)

# glm
include_directories(lib/glm)


# executables
add_executable(main ${source_files})
target_link_libraries(main glfw ${GLFW_LIBRARIES} libglew_static)


# 'make run' execute main into the bin directory
add_custom_target(run
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/main
    DEPENDS main
    WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)
