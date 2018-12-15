//
// Created by chenzhekl on 12/15/18.
//

#include "scene.h"

bool Scene::hit(const Ray &r, float tMin, float tMax, HitRecord &hit) const {
    HitRecord tmpHit{};
    bool hitAny = false;
    float closest = tMax;
    for (auto const &obj: mHittables) {
        if (obj->hit(r, tMin, closest, tmpHit)) {
            hitAny = true;
            closest = tmpHit.t;
            hit = tmpHit;
        }
    }

    return hitAny;
}
