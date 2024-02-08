#pragma once

class Ray
{
  public:
    Ray() = default;
    Ray(const glm::vec3& _origin, const glm::vec3& _direction);

    glm::vec3 origin() const { return orig; }
    glm::vec3 direction() const { return dir; }

    glm::vec3 at(float t) const;

  private:
    glm::vec3 orig;
    glm::vec3 dir;
};