cmake_minimum_required(VERSION 3.13)
project(rtiow)

set(CMAKE_CXX_STANDARD 17)

add_executable(rtiow main.cpp vec.cpp vec.h ray.cpp ray.h hittable.cpp hittable.h sphere.cpp sphere.h scene.cpp scene.h camera.cpp camera.h material.cpp material.h materials/lambertian.cpp materials/lambertian.h materials/metal.cpp materials/metal.h materials/dielectric.cpp materials/dielectric.h random.cpp random.h)