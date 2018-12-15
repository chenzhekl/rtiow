//
// Created by chenzhekl on 12/16/18.
//

#include "dielectric.h"

using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;

bool Dielectric::scatter(const Ray &rIn, const HitRecord &hit, Vec3f &attenuation, Ray &scattered) const {
    attenuation = Vec3f(1.0f, 1.0f, 1.0f);

    Vec3f outwardNormal;
    float niOverNt;
    float cosine;

    // Fron inside objects to vacuum.
    if (dot(rIn.direction(), hit.normal) > 0) {
        outwardNormal = -hit.normal;
        niOverNt = mRefractIndex;
        cosine = mRefractIndex * dot(rIn.direction(), hit.normal) / rIn.direction().length();
    } else { // Opposite direction.
        outwardNormal = hit.normal;
        niOverNt = 1.0f / mRefractIndex;
        cosine = -dot(rIn.direction(), hit.normal) / rIn.direction().length();
    }

    Vec3f refracted;
    Vec3f reflected = reflect(rIn.direction(), hit.normal);

    float reflectProb;

    if (refract(rIn.direction(), outwardNormal, niOverNt, refracted)) {
        reflectProb = schlick(cosine, mRefractIndex);
    } else {
        scattered = Ray(hit.p, reflected);
        reflectProb = 1.0f;
    }

    random_device rnd;
    default_random_engine rng{rnd()};
    uniform_real_distribution uniform(0.0f, 1.0f);

    if (uniform(rng) < reflectProb) {
        scattered = Ray(hit.p, reflected);
    } else {
        scattered = Ray(hit.p, refracted);
    }

    return true;
}
