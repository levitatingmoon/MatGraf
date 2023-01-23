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

    //cout << pointsInPlanes[0] << endl;
}

bool Cube::checkIntersection(Line line) {

    Vector intersection = line.IntersectionWithPlane(cubePlanes[0]);
    if (intersection.x >= cubePoints[0].x && intersection.x <= cubePoints[1].x &&
        intersection.z >= cubePoints[0].z && intersection.z <= cubePoints[3].z) {
        return true;
    }

    Vector intersection = line.IntersectionWithPlane(cubePlanes[1]);
    if (intersection.y >= cubePoints[6].y && intersection.y <= cubePoints[1].y &&
        intersection.z >= cubePoints[1].z && intersection.z <= cubePoints[2].z) {
        return true;
    }

    Vector intersection = line.IntersectionWithPlane(cubePlanes[2]);
    if (intersection.x >= cubePoints[7].x && intersection.x <= cubePoints[6].x &&
        intersection.z >= cubePoints[6].z && intersection.z <= cubePoints[5].z) {
        return true;
    }

    Vector intersection = line.IntersectionWithPlane(cubePlanes[3]);
    if (intersection.y >= cubePoints[7].y && intersection.y <= cubePoints[0].y &&
        intersection.z >= cubePoints[0].z && intersection.z <= cubePoints[3].z) {
        return true;
    }

    Vector intersection = line.IntersectionWithPlane(cubePlanes[4]);
    if (intersection.x >= cubePoints[3].x && intersection.x <= cubePoints[2].x &&
        intersection.y >= cubePoints[4].y && intersection.y <= cubePoints[3].y) {
        return true;
    }

    Vector intersection = line.IntersectionWithPlane(cubePlanes[5]);
    if (intersection.x >= cubePoints[0].x && intersection.x <= cubePoints[1].x &&
        intersection.y >= cubePoints[7].y && intersection.y <= cubePoints[0].y) {
        return true;
    }

    return false;
}

