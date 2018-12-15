//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_CAMERA_H
#define RTIOW_CAMERA_H


#include <cmath>

#include "vec.h"
#include "ray.h"
#include "random.h"

Vec3f randomInUnitDisk();

class Camera {
public:
    Camera(const Vec3f &lookFrom, const Vec3f &lookAt, const Vec3f &vup, float vfov, float aspect, float aperture,
           float focusDist);

    Ray ray(float u, float v) {
        Vec3f rd = mLensRadius * randomInUnitDisk();
        Vec3f offset = mU * rd.x() + mV * rd.y();
        return Ray(mOrigin + offset, mLowerLeftCorner + u * mHorizontal + v * mVertical - mOrigin - offset);
    }

private:
    Vec3f mOrigin = Vec3f(0.0f, 0.0f, 0.0f);
    Vec3f mLowerLeftCorner = Vec3f(-2.0f, -1.0f, -1.0f);
    Vec3f mHorizontal = Vec3f(4.0f, 0.0f, 0.0f);
    Vec3f mVertical = Vec3f(0.0f, 2.0f, 0.0f);
    Vec3f mU, mV, mW;
    float mLensRadius;
};


#endif //RTIOW_CAMERA_H
