//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_LAMBERTIAN_H
#define RTIOW_LAMBERTIAN_H


#include "../material.h"
#include "../ray.h"

class Lambertian : public Material {
public:
    explicit Lambertian(const Vec3f &a) : mAlbedo(a) {}

    bool scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const override;

private:
    Vec3f mAlbedo;
};


#endif //RTIOW_LAMBERTIAN_H
