#include "../include/xz_rect.h"

bool xz_rect::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const{
    double inD = 1.0 / r.direction().y();
    double t = (k - r.origin().y()) * inD;

    if(t < t_min || t > t_max) return false;

    auto p = r.at(t);
    double x = p.x(), z = p.z();

    if(x < x0 || x > x1 || z < z0 || z > z1) return false;

    rec.u = (x - x0) / (x1 - x0);
    rec.v = (z - z0) / (z1 - z0);
    rec.p = p;
    rec.t = t;

    auto outward_normal = vec3(0, 1, 0);
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}

bool xz_rect::bounding_box(double time0, double time1, aabb& output_box) const{
    output_box = aabb(point3(x0, k - 0.0001, z0), point3(x1, k + 0.0001, z1));
    return true;
}