#include "Sphere.h"

Sphere::Sphere(const Vector& center, float radius)
{
    this->center = center;
    this->radius = radius;
}

std::vector<Vector> Sphere::IntersectionWithLine(Line line)
{
    std::vector<Vector> result;

    Vector v = center;
    v -= line.point;

    float a =line.direction.dotProduct(line.direction);
    float b = -2 * (line.direction.x * (center.x - line.point.x) + line.direction.y * (center.y - line.point.y) + line.direction.z * (center.z - line.point.z));
    float c = v.dotProduct(v) - (radius * radius);

    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        std::vector<Vector> resultWrong;
        resultWrong.push_back({ 0,0,0 });
        return resultWrong;
    }

    else if (delta == 0) {
        Vector point;
        float t = (-b + std::sqrt(delta)) / (2 * a);
        point = { line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t };
        result.push_back(point);
    }
    else {
        Vector point;
        float t = (-b + std::sqrt(delta)) / (2 * a);
        point = { line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t };
        result.push_back(point);

        t = (-b - std::sqrt(delta)) / (2 * a);
        point = { line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t };
        result.push_back(point);
    }

    return result;
}
