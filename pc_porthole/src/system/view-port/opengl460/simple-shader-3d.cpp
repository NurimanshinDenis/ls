
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "simple-shader-3d.h"

using namespace std;

const char* _vertexShader = 
    "#version 430\n"
    "layout(location = 0) in vec3 vertex_position;"
    "layout(location = 1) in vec3 vertex_color;"
    "out vec3 color;"
    "void main(){"
    "  color = vertex_color;"
    "  gl_Position = vec4(vertex_position,1.0);"
    "}";

const char* _fragmentShader = 
    "#version 430\n"
    "in vec3 color;"
    "out vec4 frag_color;"
    "void main(){"
    "  frag_color = vec4(color,1.0);"
    "}";



GLuint createShader(const char* source, const GLenum shaderType)
{
    GLuint shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);

    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[1024];
        glGetProgramInfoLog(shaderID, 1024, nullptr, infoLog);
        std::cerr << "ERROR::SHADER: Compile-time error:\n" << infoLog << std::endl;
        return 0;
    }
    return shaderID;
}

SimpleShader3D::SimpleShader3D(){
    GLuint vertexShaderID = createShader(_vertexShader, GL_VERTEX_SHADER );
    if (!vertexShaderID)
    {
        std::cerr << "VERTEX SHADER compile-time error" << std::endl;
        return;
    }

    GLuint fragmentShaderID = createShader(_fragmentShader, GL_FRAGMENT_SHADER );
    if (!fragmentShaderID)
    {
        std::cerr << "FRAGMENT SHADER compile-time error" << std::endl;
        glDeleteShader(vertexShaderID);
        return ;
    }

    _glProgrammID = glCreateProgram();
    glAttachShader(_glProgrammID, vertexShaderID);
    glAttachShader(_glProgrammID, fragmentShaderID);
    glLinkProgram(_glProgrammID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    GLint success;
    glGetProgramiv(_glProgrammID, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[1024];
        glGetShaderInfoLog(_glProgrammID, 1024, nullptr, infoLog);
        std::cerr << "ERROR::SHADER: Link-time error:\n" << infoLog << std::endl;
        return;
    }
    _isSuccess = true;
}

bool SimpleShader3D::isSuccess(){
    return _isSuccess;
}

void SimpleShader3D::drow(SimpleObject3D* object){
    glUseProgram(_glProgrammID);
    object->bind();
    //glDrawArrays(GL_TRIANGLES,0,3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

