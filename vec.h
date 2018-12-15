//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_VEC3F_H
#define RTIOW_VEC3F_H

#include <cmath>

class Vec3f {
public:
    Vec3f() = default;

    Vec3f(float e0, float e1, float e2) : mE{e0, e1, e2} {}

    float x() const { return mE[0]; }

    float y() const { return mE[1]; }

    float z() const { return mE[2]; }

    float r() const { return mE[0]; }

    float g() const { return mE[1]; }

    float b() const { return mE[2]; }

    const Vec3f &operator+() const {
        return *this;
    }

    Vec3f operator-() const {
        return Vec3f(-mE[0], -mE[1], -mE[2]);
    }

    const float &operator[](int i) const {
        return mE[i];
    }

    float &operator[](int i) {
        return mE[i];
    }

    Vec3f &operator+=(const Vec3f &rhs) {
        mE[0] += rhs[0];
        mE[1] += rhs[1];
        mE[2] += rhs[2];

        return *this;
    }

    Vec3f &operator-=(const Vec3f &rhs) {
        mE[0] -= rhs[0];
        mE[1] -= rhs[1];
        mE[2] -= rhs[2];

        return *this;
    }

    Vec3f &operator*=(const Vec3f &rhs) {
        mE[0] *= rhs[0];
        mE[1] *= rhs[1];
        mE[2] *= rhs[2];

        return *this;
    }

    Vec3f &operator*=(float rhs) {
        mE[0] *= rhs;
        mE[1] *= rhs;
        mE[2] *= rhs;

        return *this;
    }

    Vec3f &operator/=(const Vec3f &rhs) {
        mE[0] /= rhs[0];
        mE[1] /= rhs[1];
        mE[2] /= rhs[2];

        return *this;
    }

    Vec3f &operator/=(float rhs) {
        mE[0] /= rhs;
        mE[1] /= rhs;
        mE[2] /= rhs;

        return *this;
    }

    float length() const {
        return std::sqrt(mE[0] * mE[0] + mE[1] * mE[1] + mE[2] * mE[2]);
    }

    float lengthSquared() const {
        return mE[0] * mE[0] + mE[1] * mE[1] + mE[2] * mE[2];
    }

private:
    float mE[3] = {};
};

inline Vec3f operator+(const Vec3f &v1, const Vec3f &v2) {
    Vec3f v(v1);
    v += v2;

    return v;
}

inline Vec3f operator-(const Vec3f &v1, const Vec3f &v2) {
    Vec3f v(v1);
    v -= v2;

    return v;
}

inline Vec3f operator*(const Vec3f &v1, const Vec3f &v2) {
    Vec3f v(v1);
    v *= v2;

    return v;
}

inline Vec3f operator*(const Vec3f &v1, float factor) {
    Vec3f v(v1);
    v *= factor;

    return v;
}

inline Vec3f operator*(float factor, const Vec3f &v1) {
    Vec3f v(v1);
    v *= factor;

    return v;
}

inline Vec3f operator/(const Vec3f &v1, const Vec3f &v2) {
    Vec3f v(v1);
    v /= v2;

    return v;
}

inline Vec3f operator/(const Vec3f &v1, float factor) {
    Vec3f v(v1);
    v /= factor;

    return v;
}

inline Vec3f normalize(const Vec3f &v) {
    return v / v.length();
}

inline float dot(const Vec3f &v1, const Vec3f &v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline Vec3f cross(const Vec3f &v1, const Vec3f &v2) {
    return Vec3f(
            v1[1] * v2[2] - v1[2] * v2[1],
            -v1[0] * v2[2] + v1[2] * v2[0],
            v1[0] * v2[1] - v1[1] * v2[0]
    );
}


#endif //RTIOW_VEC3F_H
