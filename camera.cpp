//
// Created by chenzhekl on 12/15/18.
//

#include "camera.h"

using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;
using std::tan;

Camera::Camera(const Vec3f &lookFrom, const Vec3f &lookAt, const Vec3f &vup, float vfov, float aspect, float aperture,
               float focusDist) {
    auto theta = static_cast<float>(vfov * M_PI / 180.0f);
    float halfHeight = tan(theta / 2.0f);
    float halfWidth = aspect * halfHeight;


    mW = normalize(lookFrom - lookAt);
    mU = normalize(cross(vup, mW));
    mV = cross(mW, mU);
    mLensRadius = aperture / 2.0f;

    mOrigin = lookFrom;
    mLowerLeftCorner = mOrigin - halfWidth * focusDist * mU - halfHeight * focusDist * mV - focusDist * mW;
    mHorizontal = 2 * halfWidth * focusDist * mU;
    mVertical = 2 * halfHeight * focusDist * mV;

};

Vec3f randomInUnitDisk() {
    Vec3f p;
    do {
        p = 2.0 * Vec3f(uniform(), uniform(), 0) - Vec3f(1.0f, 1.0f, 0.0f);
    } while (p.lengthSquared() >= 1.0);

    return p;
}