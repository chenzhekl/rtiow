//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_METAL_H
#define RTIOW_METAL_H


#include "../material.h"
#include "../vec.h"
#include "../ray.h"

class Metal : public Material {
public:
    explicit Metal(const Vec3f &a, float fuzz = 0.0f) : mAlbedo(a) {
        if (fuzz < 1) {
            mFuzz = fuzz;
        } else {
            mFuzz = 1;
        }
    }

    bool scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const override;

private:
    Vec3f mAlbedo;
    float mFuzz;
};


#endif //RTIOW_METAL_H
