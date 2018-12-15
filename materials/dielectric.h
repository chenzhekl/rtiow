//
// Created by chenzhekl on 12/16/18.
//

#ifndef RTIOW_DIELECTRIC_H
#define RTIOW_DIELECTRIC_H


#include <cmath>
#include <random>

#include "../material.h"
#include "../vec.h"
#include "../ray.h"

class Dielectric : public Material {
public:
    explicit Dielectric(float ri) : mRefractIndex(ri) {}

    bool scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const override;

private:
    float mRefractIndex;
};

inline float schlick(float cosine, float refractIndex) {
    float r0 = (1.0f - refractIndex) / (1.0f + refractIndex);
    r0 = r0 * r0;
    return r0 + (1.0f - r0) * std::pow((1.0f - cosine), 5);
}


#endif //RTIOW_DIELECTRIC_H
