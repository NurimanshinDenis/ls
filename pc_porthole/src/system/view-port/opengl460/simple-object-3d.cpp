#include "simple-object-3d.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

SimpleObject3D::SimpleObject3D(u32* indices, i32 isize, f32* points, i32 psize, f32* colors, i32 csize):ISympleObject3D(){

    glGenBuffers(1, &_pointsVbo);
    glBindBuffer(GL_ARRAY_BUFFER, _pointsVbo);
    glBufferData(GL_ARRAY_BUFFER, psize, points, GL_STATIC_DRAW);

    glGenBuffers(1, &_colorVbo);
    glBindBuffer(GL_ARRAY_BUFFER, _colorVbo);
    glBufferData(GL_ARRAY_BUFFER, csize, colors, GL_STATIC_DRAW);

    glGenBuffers(1, &_indicesEbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesEbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _pointsVbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, _colorVbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,0, nullptr);
}

void SimpleObject3D::bind(){
    glBindVertexArray(_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesEbo);
}



