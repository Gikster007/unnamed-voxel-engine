#include "camera.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "ray/ray.h"

Camera::Camera(glm::vec3 _pos)
{
    pos = _pos;
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);

    proj = glm::perspective(glm::radians(45.0f), static_cast<float>(WIN_WIDTH / WIN_HEIGHT), 0.1f, 100.0f);
    view = glm::lookAt(pos, pos + front, up);
}

Camera::~Camera()
{
}

void Camera::render()
{
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
        {
            HitRecord rec;

            glm::mat4 ndc_to_world = glm::inverse(proj * view);

            /* Calculate the ray position in normalized device coordinates */
            glm::vec4 ray_end_ndc(((float)x / (float)WIN_WIDTH - 0.5f) * 2.0f, ((float)y / (float)WIN_HEIGHT - 0.5f) * 2.0f, 0.0, 1.0f);
            glm::vec4 ray_end_world = ndc_to_world * ray_end_ndc;
            glm::vec3 ray_end = glm::vec3(ray_end_world) / ray_end_world.w;

            /* Calculate the ray direction */
            glm::vec3 ray_dir = glm::normalize(ray_end - pos);
            glm::vec3 ray_origin = pos;

            Ray r(pos, ray_dir);
            if (sphere_hit(r, 0.001f, INFINITY, rec, { 0.0f, 0.0f, -2.0f }, 1.0f))
            {
                //draw sphere somehow
            }
        }
    }
}

bool Camera::sphere_hit(const Ray& r, float tmin, float tmax, HitRecord& rec, glm::vec3 center, float radius)
{
    glm::vec3 oc = r.origin() - center;
    float a = r.direction().length() * r.direction().length();
    float half_b = dot(oc, r.direction());
    float c = oc.length() * oc.length() - radius * radius;

    float discrimnant = half_b * half_b - a * c;
    if (discrimnant < 0)
        return false;
    float sqrtd = sqrt(discrimnant);

    // Find the nearest root that lies in the acceptable range;
    float root = (-half_b - sqrtd) / a;
    if (!(tmin < root && root < tmax))
    {
        root = (-half_b + sqrtd) / a;
        if (!(tmin < root && root < tmax))
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    glm::vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}