#include "system.h"
#include "view-port/opengl460/opengl460.h"


f32 points[] = {
    0.5f,  0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};

f32 points2[] = {
    0.6f,  0.6f, 0.0f,  // top right
    0.6f, -0.4f, 0.0f,  // bottom right
    -0.4f, -0.4f, 0.0f,  // bottom left
    -0.4f,  0.6f, 0.0f   // top left 
};

f32 colors[] = {
    0.3f, 0.9f, 0.1f,
    0.3f, 0.8f, 0.3f,
    0.3f, 0.9f, 0.5f,
    0.1f, 0.7f, 0.4f,
};

f32 colors2[] = {
    0.1f, 0.6f, 0.1f,
    0.1f, 0.6f, 0.1f,
    0.1f, 0.6f, 0.2f,
    0.1f, 0.6f, 0.1f,
};

u32 indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};


System::System(){
    viewPort = new OpenGL460();
    sympleObject3D = viewPort->addSympleObject(indices,sizeof(indices),points, sizeof(points), colors, sizeof(colors));
    sympleObject3D_2 = viewPort->addSympleObject(indices,sizeof(indices),points2, sizeof(points2), colors2, sizeof(colors2));
}

System::~System(){
    if(viewPort){
        delete viewPort;
    }
    viewPort = nullptr;
}

bool System::update(){

    if(!viewPort){
        return false;
    }
    if(viewPort->shouldClose()){
        return false;
    }

    viewPort->startDrow();

    viewPort->drow(sympleObject3D);
    viewPort->drow(sympleObject3D_2);

    viewPort->endDrow();
    return true;
}
