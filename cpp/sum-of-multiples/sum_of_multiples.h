#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#define EXERCISM_RUN_ALL_TESTS

#include <set>

namespace sum_of_multiples {

    int to(const std::set<int> &integers, int number) {
        int sum = 0;
        for (int i = 1; i < number; i++) {
            for (const auto &j : integers) {
                if (i % j == 0) {
                    sum += i;
                    break;
                }
            }
        }
        return sum;
    }

}

#endif
