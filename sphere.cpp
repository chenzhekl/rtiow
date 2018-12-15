//
// Created by chenzhekl on 12/15/18.
//

#include "sphere.h"

using std::sqrt;

bool Sphere::hit(const Ray &r, float tMin, float tMax, HitRecord &hit) const {
    Vec3f oc = r.origin() - mCenter;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - mRadius * mRadius;
    float discriminant = b * b - a * c;

    if (discriminant > 0) {
        float hitT = (-b - sqrt(discriminant)) / a;
        if (hitT < tMax && hitT > tMin) {
            hit.t = hitT;
            hit.p = r(hitT);
            hit.normal = (hit.p - mCenter) / mRadius;
            hit.material = mMaterial;

            return true;
        }

        hitT = (-b + sqrt(discriminant)) / a;
        if (hitT < tMax && hitT > tMin) {
            hit.t = hitT;
            hit.p = r(hitT);
            hit.normal = (hit.p - mCenter) / mRadius;
            hit.material = mMaterial;

            return true;
        }
    }

    return false;
}
