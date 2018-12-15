//
// Created by chenzhekl on 12/16/18.
//

#include "random.h"

using std::default_random_engine;
using std::uniform_real_distribution;
using std::random_device;

float uniform() {
    static random_device rnd;
    static default_random_engine rng{rnd()};
    static uniform_real_distribution uniform(0.0f, 1.0f);

    return uniform(rng);
}

