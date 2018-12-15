//
// Created by chenzhekl on 12/15/18.
//

#ifndef RTIOW_SCENE_H
#define RTIOW_SCENE_H

#include <vector>
#include <memory>
#include "hittable.h"
#include "ray.h"

class Scene : public Hittable {
public:
    Scene() = default;

    explicit Scene(const std::vector<std::shared_ptr<Hittable>> &hittables) : mHittables(hittables) {}

    explicit Scene(std::vector<std::shared_ptr<Hittable>> &&hittables) : mHittables(std::move(hittables)) {}

    bool hit(const Ray &r, float tMin, float tMax, HitRecord &hit) const override;

private:
    std::vector<std::shared_ptr<Hittable>> mHittables;
};


#endif //RTIOW_SCENE_H
