//
// Created by chenzhekl on 12/15/18.
//

#include "metal.h"

bool Metal::scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const {
    Vec3f reflected = reflect(normalize(rIn.direction()), hit.normal);
    scattered = Ray(hit.p, reflected + mFuzz * randomInUnitSphere());
    attenuation = mAlbedo;
    return dot(scattered.direction(), hit.normal) > 0;
}