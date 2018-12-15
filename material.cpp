//
// Created by chenzhekl on 12/15/18.
//

#include "material.h"

using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;
using std::sqrt;

Vec3f randomInUnitSphere() {
    Vec3f p;
    do {
        p = 2.0 * Vec3f(uniform(), uniform(), uniform()) - Vec3f(1.0f, 1.0f, 1.0f);
    } while (p.lengthSquared() >= 1.0);

    return p;
}

bool refract(const Vec3f &v, const Vec3f &n, float niOverNt, Vec3f &refracted) {
    Vec3f uv = normalize(v);
    float dt = dot(uv, n);
    float discriminant = 1.0f - niOverNt * niOverNt * (1 - dt * dt);

    if (discriminant > 0) {
        refracted = niOverNt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }

    return false;
}
