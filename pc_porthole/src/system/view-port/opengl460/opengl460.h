#pragma once

#include "../../../interfaces.h"
#include "simple-object-3d.h"
#include "simple-shader-3d.h"


class OpenGL460: public IViewPort{

public:
    OpenGL460();
    ~OpenGL460();

    ViewPortType getViewPortType() override {return VIEW_PORT_OPEN_GL_460;}

    bool isSuccess() override;

    ISympleObject3D* addSympleObject(u32* indices, i32 isize, f32* points, i32 psize, f32* colors, i32 csize) override;

    void drow(ISympleObject3D* object) override;

    bool shouldClose() override;

    void startDrow() override;
    void endDrow() override;

private:
    SimpleShader3D* _sympleShader = nullptr;
};