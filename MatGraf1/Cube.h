#pragma once
#include "Vector.h"
#include "Plane.h"

class Cube
{
public:
    Vector cubePoints[8];
    Plane cubePlanes[6];
    Cube(float distance);

};

