//
// Created by chenzhekl on 12/15/18.
//

#include "lambertian.h"

bool Lambertian::scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const {
    Vec3f target = hit.p + hit.normal + randomInUnitSphere();
    scattered = Ray(hit.p, target - hit.p);
    attenuation = mAlbedo;

    return true;
}
