//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_SPHERE_H
#define RTIOW_SPHERE_H


#include <cmath>
#include <memory>

#include "hittable.h"
#include "ray.h"
#include "vec.h"
#include "material.h"

class Sphere : public Hittable {
public:
    Sphere() = default;

    Sphere(const Vec3f &center, float radius, std::shared_ptr<Material> material) : mCenter(center), mRadius(radius),
                                                                                    mMaterial(std::move(material)) {}

    bool hit(const Ray &r, float tMin, float tMax, HitRecord &hit) const override;

private:
    Vec3f mCenter;
    float mRadius = 0.0f;
    std::shared_ptr<Material> mMaterial;
};


#endif //RTIOW_SPHERE_H
