#include "ray.h"

Ray::Ray(const glm::vec3& _origin, const glm::vec3& _direction)
{
    orig = _origin;
    dir = _direction;
}

glm::vec3 Ray::at(float t) const
{
    return orig + (t * dir);
}