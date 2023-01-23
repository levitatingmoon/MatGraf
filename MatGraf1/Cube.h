#pragma once
#include "Vector.h"
#include "Plane.h"

class Cube
{
public:
    Vector cubePoints[8];
    Plane cubePlanes[6];
    int pointsInPlanes[6][4] = { 0,1,2,3,1,6,5,2,6,7,4,5,7,0,3,4,3,2,5,4,0,1,6,7 };
    Cube(float distance);

    bool checkIntersection(Line line);

};

