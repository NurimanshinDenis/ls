#pragma once

#include <ls_vm.h>

enum ShaderType{
    SHADER_SYMPLY,
    SHADER_TYPE_COUNT,
};

enum ViewPortType{
    VIEW_PORT_OPEN_GL_460,
    VIEW_PORT_COUNT,
};

class ISympleObject3D{
public:
    ISympleObject3D(){}
    virtual ~ISympleObject3D(){};
    virtual ViewPortType getViewPortType() = 0;
};
    

class IViewPort{
public:
    IViewPort(){}
    virtual ~IViewPort(){};

    virtual ViewPortType getViewPortType() = 0;

    virtual ISympleObject3D* addSympleObject(u32* indices, i32 isize, f32* points, i32 psize, f32* colors, i32 csize) = 0;
    virtual void drow(ISympleObject3D* object) = 0;
    
    virtual bool shouldClose() = 0;
    virtual void startDrow() = 0;
    virtual void endDrow() = 0;

    virtual bool isSuccess() = 0;
};