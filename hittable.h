//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_HITTABLE_H
#define RTIOW_HITTABLE_H


#include <memory>

#include "vec.h"
#include "ray.h"
#include "material.h"

class Material;

struct HitRecord {
    float t = 0.0f;
    Vec3f p;
    Vec3f normal;
    std::shared_ptr<Material> material;
};

class Hittable {
public:
    virtual bool hit(const Ray &r, float tMin, float tMax, HitRecord &hit) const = 0;

    virtual ~Hittable() = default;
};


#endif //RTIOW_HITTABLE_H
