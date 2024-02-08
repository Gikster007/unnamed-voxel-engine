#pragma once

class Ray;

struct HitRecord
{
    glm::vec3 point;
    glm::vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const Ray& r, const glm::vec3& outward_normal)
    {
        // Sets the hit record normal vector
        // NOTE: the parameter 'outward_normal' is assumed to have unit length (normalised)

        front_face = glm::dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Camera
{
  public:
    Camera(glm::vec3 _pos = glm::vec3(0.0f, 0.0f, 1.0f));
    ~Camera();

    void render();

    bool sphere_hit(const Ray& r, float tmin, float tmax, HitRecord& rec, glm::vec3 center, float radius);

  public:
    glm::mat4 view, proj;
    glm::vec3 pos, up, front;