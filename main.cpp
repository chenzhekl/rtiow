#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <memory>

#include "vec.h"
#include "ray.h"
#include "hittable.h"
#include "scene.h"
#include "sphere.h"
#include "camera.h"
#include "materials/lambertian.h"
#include "materials/metal.h"
#include "materials/dielectric.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::sqrt;
using std::vector;
using std::shared_ptr;
using std::make_shared;

Scene randomScene() {
    int n = 500;
    vector<shared_ptr<Hittable>> objList;
    // Add ground;
    objList.push_back(make_shared<Sphere>(Vec3f(0.0f, -1000.0f, 0.0f), 1000.0f,
                                          make_shared<Lambertian>(Vec3f(0.5f, 0.5f, 0.5f))));

    for (int a = -11; a < 11; ++a) {
        for (int b = -11; b < 11; ++b) {
            float chooseMat = uniform();
            Vec3f center(a + 0.9f * uniform(), 0.2f, b + 0.9f * uniform());
            if ((center - Vec3f(4.0f, 0.2f, 0.0f)).length() > 0.9f) {
                if (chooseMat < 0.8) { // Lambertian
                    objList.push_back(make_shared<Sphere>(center, 0.2f, make_shared<Lambertian>(
                            Vec3f(uniform() * uniform(), uniform() * uniform(), uniform() * uniform()))));
                } else if (chooseMat < 0.95) { // Metal
                    objList.push_back(make_shared<Sphere>(center, 0.2f, make_shared<Metal>(
                            Vec3f(0.5f * (1 + uniform()), 0.5f * (1 + uniform()), 0.5f * (1 + uniform())),
                            0.5 * uniform())));
                } else { // Dielectric
                    objList.push_back(make_shared<Sphere>(center, 0.2f, make_shared<Dielectric>(1.5f)));
                };
            }
        }
    }

    objList.push_back(make_shared<Sphere>(Vec3f(0.0f, 1.0f, 0.0f), 1.0f, make_shared<Dielectric>(1.5f)));
    objList.push_back(
            make_shared<Sphere>(Vec3f(-4.0f, 1.0f, 0.0f), 1.0f, make_shared<Lambertian>(Vec3f(0.4f, 0.2f, 0.1f))));
    objList.push_back(
            make_shared<Sphere>(Vec3f(4.0f, 1.0f, 0.0f), 1.0f, make_shared<Metal>(Vec3f(0.7f, 0.6f, 0.5f), 0.0f)));

    return Scene(std::move(objList));
}

Vec3f color(const Ray &r, Hittable &world, int depth) {
    HitRecord hit{};
    if (world.hit(r, 0.001f, std::numeric_limits<float>::max(), hit)) {
        Ray scattered;
        Vec3f attenuation;

        if (depth < 50 && hit.material->scatter(r, hit, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth + 1);
        } else {
            return Vec3f(0.0f, 0.0f, 0.0f);
        }
    }

    Vec3f unitDir = normalize(r.direction());
    float t = 0.5f * (unitDir.y() + 1.0f);
    return (1.0f - t) * Vec3f(1.0f, 1.0f, 1.0f) + t * Vec3f(0.5f, 0.7f, 1.0f);
}

int main() {
    constexpr int nx = 1200;
    constexpr int ny = 800;
    constexpr int ns = 20;
    ofstream canvas("./out.ppm");

    canvas << "P3\n" << nx << " " << ny << "\n255\n";

    Scene world = randomScene();

    Vec3f lookFrom(13.0f, 2.0f, 3.0f);
    Vec3f lookAt(0.0f, 0.0f, 0.0f);
    float distToFocus = 10.0f;
    float aperture = 0.1f;
    Camera camera(lookFrom, lookAt, Vec3f(0.0f, 1.0f, 0.0f), 20.0f, 1.0f * nx / ny, aperture, distToFocus);

    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            Vec3f col(0.0f, 0.0f, 0.0f);
            for (int s = 0; s < ns; ++s) {
                float u = (i + uniform()) / nx;
                float v = (j + uniform()) / ny;
                Ray r = camera.ray(u, v);
                col += color(r, world, 0);
            }

            col /= ns;
            col = Vec3f(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

            auto ir = static_cast<int>(255.99 * col[0]);
            auto ig = static_cast<int>(255.99 * col[1]);
            auto ib = static_cast<int>(255.99 * col[2]);

            canvas << ir << " " << ig << " " << ib << "\n";
            cout << "Progress: " << (ny - 1 - j) * nx + i + 1 << "/" << nx * ny << endl;
        }
    }

    return 0;
}
