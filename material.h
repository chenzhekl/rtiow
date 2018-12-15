//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_MATERIAL_H
#define RTIOW_MATERIAL_H


#include <cmath>

#include "ray.h"
#include "hittable.h"
#include "vec.h"
#include "random.h"

struct HitRecord;

class Material {
public:
    virtual bool scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const = 0;
};

Vec3f randomInUnitSphere();

bool refract(const Vec3f &v, const Vec3f &n, float niOverNt, Vec3f &refracted);

inline Vec3f reflect(const Vec3f &v, const Vec3f &n) {
    return v - 2 * dot(v, n) * n;
}


#endif //RTIOW_MATERIAL_H
