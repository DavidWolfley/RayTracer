#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "ray.hpp"
#include "rtweekend.hpp"
#include "aabb.hpp"

class material;

class hit_record {
public:
    double u;
    double v;
    point3 p;
    vec3 normal;
    double t;
    shared_ptr<material> mat;
    bool front_face;

    void set_face_normal(const ray &r, const vec3 &outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    };
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

    virtual aabb bounding_box() const = 0;
};

class translate : public hittable {
public:
    translate(shared_ptr<hittable> p, const vec3& displacement)
            : object(p), offset(displacement)
    {
        bbox = object->bounding_box() + offset;
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        // Move the ray backwards by the offset
        ray offset_r(r.origin() - offset, r.direction(), r.time());

        // Determine where (if any) an intersection occurs along the offset ray
        if (!object->hit(offset_r, ray_t, rec))
            return false;

        // Move the intersection point forwards by the offset
        rec.p += offset;

        return true;
    }

    aabb bounding_box() const override { return bbox; }

private:
    shared_ptr<hittable> object;
    vec3 offset;
    aabb bbox;
};

#endif