#pragma once

#include <glad/glad.h>
#include "../../../interfaces.h"

class SimpleObject3D: public ISympleObject3D{
private:
    GLuint _pointsVbo = 0;
    GLuint _colorVbo = 0;
    GLuint _indicesEbo = 0;
    GLuint _vao = 0;

public:
    SimpleObject3D(u32* indices, i32 isize, f32* points, i32 psize, f32* colors, i32 csize);
    ~SimpleObject3D(){};
    ViewPortType getViewPortType() override {return VIEW_PORT_OPEN_GL_460;}

    void bind();
};