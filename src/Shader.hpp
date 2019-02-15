/**
 * Shader.hpp
 * Contributors:
 *      * Arthur Sonzogni (author)
 * Licence:
 *      * MIT
 */
#ifndef OPENGL_CMAKE_SKELETON_SHADER_HPP
#define OPENGL_CMAKE_SKELETON_SHADER_HPP

#define GLM_FORCE_RADIANS
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <initializer_list>
#include <map>
#include <string>

class Shader;
class ShaderProgram;

// Loads a shader from a file into OpenGL.
class Shader {
 public:
  // Load Shader from a file
  Shader(const std::string& filename, GLenum type);

  // provide opengl shader identifiant.
  GLuint getHandle() const;

  ~Shader();

 private:
  // opengl program identifiant
  GLuint handle;

  friend class ShaderProgram;
};

// A shader program is a set of shader (for instance vertex shader + pixel
// shader) defining the rendering pipeline.
//
// This class provide an interface to define the OpenGL uniforms and attributes
// using GLM objects.
class ShaderProgram {
 public:
  // constructor
  ShaderProgram(std::initializer_list<Shader> shaderList);

  // bind the program
  void use() const;
  void unuse() const;

  // provide the opengl identifiant
  GLuint getHandle() const;

  // clang-format off
  // provide attributes informations.
  GLint attribute(const std::string& name);
  void setAttribute(const std::string& name, GLint size, GLsizei stride, GLuint offset, GLboolean normalize, GLenum type);
  void setAttribute(const std::string& name, GLint size, GLsizei stride, GLuint offset, GLboolean normalize);
  void setAttribute(const std::string& name, GLint size, GLsizei stride, GLuint offset, GLenum type); 
  void setAttribute(const std::string& name, GLint size, GLsizei stride, GLuint offset);
  // clang-format on

  // provide uniform location
  GLint uniform(const std::string& name);
  GLint operator[](const std::string& name);

  // affect uniform
  void setUniform(const std::string& name, float x, float y, float z);
  void setUniform(const std::string& name, const glm::vec3& v);
  void setUniform(const std::string& name, const glm::dvec3& v);
  void setUniform(const std::string& name, const glm::vec4& v);
  void setUniform(const std::string& name, const glm::dvec4& v);
  void setUniform(const std::string& name, const glm::dmat4& m);
  void setUniform(const std::string& name, const glm::mat4& m);
  void setUniform(const std::string& name, const glm::mat3& m);
  void setUniform(const std::string& name, float val);
  void setUniform(const std::string& name, int val);

  ~ShaderProgram();

 private:
  ShaderProgram();

  std::map<std::string, GLint> uniforms;
  std::map<std::string, GLint> attributes;

  // opengl id
  GLuint handle;

  void link();
};

#endif  // OPENGL_CMAKE_SKELETON_SHADER_HPP
