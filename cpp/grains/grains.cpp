#include "grains.h"

namespace grains {

    typedef uint_fast64_t grains_count;

    grains_count square(int n) {
        return grains_count(1) << (n-1);
    }

    grains_count total() {
        return ~0; // 2^64-1
    }

}
