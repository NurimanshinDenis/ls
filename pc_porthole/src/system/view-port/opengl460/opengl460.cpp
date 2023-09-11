#include "opengl460.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


using namespace std;

int _windowSizeX = 640;
int _windowSizey = 480;

bool _isSuccess = false;

GLFWwindow* _window = nullptr;


void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    _windowSizeX = width;
    _windowSizey = height;
    glViewport(0,0,_windowSizeX,_windowSizey);
}

OpenGL460::OpenGL460():IViewPort(){
    if(_window){
        return;
    }

    if (!glfwInit())
    {
        cout << "glfwInit error" << endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(_windowSizeX, _windowSizey, "Porthole", NULL, NULL);
    if (!_window)
    {
        std::cout << "glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(_window);
    glfwSetWindowSizeCallback(_window, glfwWindowSizeCallback);

    if (!gladLoadGL())
    {
        cout << "Can't load GLAD!" << endl;
        return ;
    }
    cout << "Renderer" << glGetString(GL_RENDERER) << endl;
    cout << "GL version" << " " << glGetString(GL_VERSION) << endl;

    _sympleShader = new SimpleShader3D();

    glClearColor(0.2,0.3,0.4,1);

}

ISympleObject3D* OpenGL460::addSympleObject(u32* indices, i32 isize, f32* points, i32 psize, f32* colors, i32 csize){
    return new SimpleObject3D(indices,isize,points,psize,colors,csize);
}

void OpenGL460::drow(ISympleObject3D* object){
    _sympleShader->drow((SimpleObject3D*)object);
}

bool OpenGL460::isSuccess(){
    return _sympleShader->isSuccess();
}

bool OpenGL460::shouldClose(){
    return glfwWindowShouldClose(_window);
}

void OpenGL460::startDrow(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    
}

void OpenGL460::endDrow(){
    glfwSwapBuffers(_window);
    glfwPollEvents();
}


OpenGL460::~OpenGL460(){
    if(_sympleShader){
        delete _sympleShader;
    }
    glfwTerminate();
    _isSuccess = false;
    _window = nullptr;
    _windowSizeX = 640;
    _windowSizey = 480;
}


