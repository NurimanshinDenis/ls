#pragma once

#include "simple-object-3d.h"
#include <glad/glad.h>



class SimpleShader3D{

public:
    SimpleShader3D();
    ~SimpleShader3D(){};

    bool isSuccess();

    void drow(SimpleObject3D* object);
private:
    bool _isSuccess = false;
    GLuint  _glProgrammID = 0;
};