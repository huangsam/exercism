#include "sum_of_multiples.h"

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
