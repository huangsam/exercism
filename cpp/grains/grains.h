#if !defined(GRAINS_H)
#define GRAINS_H

#define EXERCISM_RUN_ALL_TESTS

#include <cstdint>

namespace grains {

    typedef uint_fast64_t grains_count;

    grains_count square(int n) {
        return grains_count(1) << (n-1);
    }

    grains_count total() {
        return ~0;
    }

}

#endif
