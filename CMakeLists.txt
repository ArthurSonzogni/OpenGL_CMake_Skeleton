# Projects Settings
cmake_minimum_required (VERSION 3.1)
project(opengl-cmake-skeleton)

# The opengl-cmake-skeleton executable
add_executable(opengl-cmake-skeleton
  src/Application.cpp
  src/Application.cpp
  src/MyApplication.cpp
  src/MyApplication.cpp
  src/glError.hpp
  src/glError.cpp
  src/main.cpp
  src/Shader.hpp
  src/Shader.cpp
)

if (EMSCRIPTEN)
  set_target_properties(opengl-cmake-skeleton PROPERTIES OUTPUT_NAME "main.js")

  # glfw
  #string(APPEND CMAKE_CXX_FLAGS " -s USE_GLFW=3")

  string(APPEND CMAKE_CXX_FLAGS " -s DEMANGLE_SUPPORT=1")
  string(APPEND CMAKE_CXX_FLAGS " -s DISABLE_EXCEPTION_CATCHING=2")
  string(APPEND CMAKE_CXX_FLAGS " -s USE_GLFW=3")
  string(APPEND CMAKE_CXX_FLAGS " -s USE_WEBGL2=1")
  string(APPEND CMAKE_CXX_FLAGS " -s WASM=1")

  # Release flags
  #string(APPEND CMAKE_CXX_FLAGS " --closure 1")
  #string(APPEND CMAKE_CXX_FLAGS " --js-opts 3")
  #string(APPEND CMAKE_CXX_FLAGS " --llvm-lto 3")
  #string(APPEND CMAKE_CXX_FLAGS " --llvm-opts 3")
  #string(APPEND CMAKE_CXX_FLAGS " -O3")

  # Copy the index.html file.
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/index.html
    ${CMAKE_CURRENT_BINARY_DIR}/index.html
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/style.css
    ${CMAKE_CURRENT_BINARY_DIR}/style.css
  )

  # Allow the directories /shader and /data to be fetched by the web browser.
  file(GLOB shader_files "./shader/*")
  foreach(file ${shader_files})
    file(RELATIVE_PATH relative_file ${CMAKE_SOURCE_DIR} ${file})
    string(APPEND CMAKE_CXX_FLAGS " --preload-file ${file}@/${relative_file}")
    message(STATUS CMAKE_CXX_FLAGS " --preload-file ${file}@/${relative_file}")
  endforeach()
  
else() # Not Web

  # glfw
  add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
  target_link_libraries(opengl-cmake-skeleton PRIVATE glfw)

  # glew
  add_definitions(-DGLEW_STATIC)
  add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
  target_link_libraries(opengl-cmake-skeleton PRIVATE libglew_static)

endif()

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(opengl-cmake-skeleton PRIVATE glm)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/asset.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/asset.hpp
)
target_include_directories(opengl-cmake-skeleton
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
)
