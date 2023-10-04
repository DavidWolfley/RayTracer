
#ifndef AARECT_HPP
#define AARECT_HPP


#include "hittable.hpp"
#include "vec3.hpp"

class yz_rect : public hittable {
    double k; // x coordinate
    interval ybounds, zbounds;
    shared_ptr<material> mat;
public:
    yz_rect(double _k, interval _ybounds, interval _zbounds, shared_ptr<material> _material)
            : k(_k), ybounds(_ybounds), zbounds(_zbounds), mat(_material) {}


    inline bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
        double t = (k - r.origin().x()) / r.direction().x();
        if (!ray_t.surrounds(t))
            return false;
        point3 pt = r.at(t);
        if (!ybounds.surrounds(pt.y()) || !zbounds.surrounds(pt.z())) {
            return false;
        }
        rec.t = t;
        rec.p = pt;
        vec3 outward_normal(1.0, 0, 0);
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }
};

#endif //AARECT_HPP
