#include "Cube.h"

Cube::Cube(float distance)
{
    cubePoints[0] = Vector(-distance, distance,-distance); //-+-
    cubePoints[1] = Vector(distance, distance, -distance); //++-
    cubePoints[2] = Vector(distance, distance, distance); //+++
    cubePoints[3] = Vector(-distance, distance, distance); //-++
    cubePoints[4] = Vector(-distance, -distance, distance); //--+
    cubePoints[5] = Vector(distance, -distance, distance); //+-+
    cubePoints[6] = Vector(distance, -distance, -distance); //+--
    cubePoints[7] = Vector(-distance, -distance, -distance);  //---

    cubePlanes[0] = Plane(cubePoints[0], cubePoints[1], cubePoints[2], cubePoints[3]);
    cubePlanes[1] = Plane(cubePoints[1], cubePoints[6], cubePoints[5], cubePoints[2]);
    cubePlanes[2] = Plane(cubePoints[6], cubePoints[7], cubePoints[4], cubePoints[5]);
    cubePlanes[3] = Plane(cubePoints[7], cubePoints[0], cubePoints[3], cubePoints[4]);
    cubePlanes[4] = Plane(cubePoints[3], cubePoints[2], cubePoints[5], cubePoints[4]);
    cubePlanes[5] = Plane(cubePoints[0], cubePoints[1], cubePoints[6], cubePoints[7]);
}

