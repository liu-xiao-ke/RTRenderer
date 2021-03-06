//
// Created by VRLAB on 2020/12/7.
//
#include "../include/flip_face.h"

bool flip_face::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    if(!ptr->hit(r, t_min, t_max, rec))
        return false;

    rec.front_face = !rec.front_face;
    return true;
}

bool flip_face::bounding_box(double time0, double time1, aabb &output_box) const {
    return ptr->bounding_box(time0, time1, output_box);
}