#include "Application3D.hpp"
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtx/matrix_operation.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


struct VertexType
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec4 color;
};

float heightMap(const glm::vec2 position)
{
    return sin(position.x) + sin(position.y);
}

VertexType getHeightMap(const glm::vec2 position)
{
    const glm::vec2 dx(1.0,0.0);
    const glm::vec2 dy(1.0,0.0);

    VertexType v;
    float h = heightMap(position);
    float hx = 100.f * (heightMap(position + 0.01f*dx) - h );
    float hy = 100.f * (heightMap(position + 0.01f*dy) - h );

    v.position = glm::vec3(position,h);
    v.normal = glm::normalize(glm::vec3(-hx,-hy,1.0));
    v.color = glm::vec4(1.0,0.0,0.0,1.0);
}


Application3D::Application3D():
    Application(),
    vertexShader("shader/shader.vert",GL_VERTEX_SHADER),
    fragmentShader("shader/shader.frag",GL_FRAGMENT_SHADER),
    shaderProgram({vertexShader,fragmentShader})
{

    std::vector<VertexType> vertices;
    std::vector<GLuint> index;


    for(int y = 0; y<=10.0; ++y)
    for(int x = 0; x<=10.0; ++x)
    {
        vertices.push_back(getHeightMap(glm::vec2(x*0.1f,y*0.1f)));
    }

    for(int y = 0; y<10.0; ++y)
    for(int x = 0; x<10.0; ++x)
    {
        index.push_back((x+0) + 10*(y+0));
        index.push_back((x+1) + 10*(y+0));
        index.push_back((x+1) + 10*(y+1));

        index.push_back((x+1) + 10*(y+1));
        index.push_back((x+0) + 10*(y+1));
        index.push_back((x+0) + 10*(y+0));
    }


    // vao
    glGenVertexArrays( 1, &vao);
    glBindVertexArray(vao);

        shaderProgram.use();
        
        // vbo
        glGenBuffers( 1, &vbo );
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

        // veo
        glGenBuffers(1, &veo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, veo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(GLuint), index.data(), GL_STATIC_DRAW);

        GLuint positionLoc = shaderProgram.attribute("position");
        GLuint   normalLoc = shaderProgram.attribute("normal");
        GLuint    colorLoc = shaderProgram.attribute("color");

        // map GLSL name with the data
        shaderProgram.setAttribute("position",
                                    false,
                                    sizeof(VertexType::position),
                                    sizeof(VertexType),
                                    offsetof(VertexType, position));

        shaderProgram.setAttribute("normal"  ,
                                    false,
                                    sizeof(VertexType::normal)  ,
                                    sizeof(VertexType),
                                    offsetof(VertexType, normal));

        shaderProgram.setAttribute("color"   ,
                                    false,
                                    sizeof(VertexType::color)   ,
                                    sizeof(VertexType),
                                    offsetof(VertexType, color));

    // vao end
    glBindVertexArray(0);
}



void Application3D::loop()
{
    float t = getTime();
    // set matrix
    projection = glm::perspective(90.0f, getWindowRatio(), 0.1f, 100.f);
    view  = glm::lookAt(
        glm::vec3(6.0*sin(t),6.0,6.0*cos(t)),
        glm::vec3(0.0,3.0,0.0),
        glm::vec3(0.0,1.0,0.0)
    );

    shaderProgram.use();    

    // send uniforms
    shaderProgram.setUniform("projection",projection);
    shaderProgram.setUniform("view",view);

    // send attributes
    glBindVertexArray(vao);
    
        glDrawElements(
             GL_TRIANGLES,      // mode
             40,                // count
             GL_UNSIGNED_INT,   // type
             (void*)0           // element array buffer offset
         );

    glBindVertexArray(0);
}
