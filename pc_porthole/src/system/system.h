#pragma once

#include "../interfaces.h"


class System{

public:
    System();
    ~System();

    bool update();

private:
    IViewPort* viewPort = nullptr;

    ISympleObject3D* sympleObject3D = nullptr;
    ISympleObject3D* sympleObject3D_2 = nullptr;
};