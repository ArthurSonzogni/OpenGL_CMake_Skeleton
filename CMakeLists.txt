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
  target_link_libraries(opengl-cmake-skeleton PUBLIC "-s USE_GLFW=3")
  target_link_libraries(opengl-cmake-skeleton PUBLIC "-s USE_WEBGL2=1")
  target_link_libraries(opengl-cmake-skeleton PUBLIC "-s WASM=1")

  # Copy the index.html file.
  foreach(file "index.html" "run_webassembly.py")
    configure_file(src/${file} ${file})
  endforeach(file)

  foreach(file "shader/shader.frag" "shader/shader.vert")
    configure_file(${file} ${file})
  endforeach(file)

  # Allow the directories /shader and /data to be fetched by the web browser.
  set_property(TARGET opengl-cmake-skeleton APPEND_STRING PROPERTY LINK_FLAGS
    "--preload-file ${CMAKE_CURRENT_BINARY_DIR}/shader/@/shader/")
  
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
