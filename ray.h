//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_RAY_H
#define RTIOW_RAY_H


#include "vec.h"

class Ray {
public:
    Ray() = default;

    Ray(const Vec3f &origin, const Vec3f &dir) : mOrigin(origin), mDirection(dir) {}

    Vec3f &origin() {
        return mOrigin;
    }

    const Vec3f &origin() const {
        return mOrigin;
    }

    Vec3f &direction() {
        return mDirection;
    }

    const Vec3f &direction() const {
        return mDirection;
    }

    Vec3f operator()(float t) const {
        return mOrigin + mDirection * t;
    }


private:
    Vec3f mOrigin;
    Vec3f mDirection;
};


#endif //RTIOW_RAY_H
