/**
 * Application3D.hpp skeleton
 * Contributors:
 *      * Arthur Sonzogni
 * Licence:
 *      * MIT
 */

#ifndef APPLICATION3D_9YCQ0OVR
#define APPLICATION3D_9YCQ0OVR

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "system/Application.hpp"
#include "graphic/Shader.hpp"

class Application3D : public Application
{
    public:
        Application3D();

    protected:
        virtual void loop();

    private:
        float time = 0.f;
        const int size = 100;

        // shader
        Shader vertexShader;
        Shader fragmentShader;
        ShaderProgram shaderProgram;

        // shader matrix uniform
        glm::mat4 projection = glm::mat4(1.0);
        glm::mat4 view = glm::mat4(1.0);

        // VBO/VAO/ibo
        GLuint vao,vbo,ibo;
        
};

#endif /* end of include guard: APPLICATION3D_9YCQ0OVR */
