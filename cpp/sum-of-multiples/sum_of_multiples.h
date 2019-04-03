#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#include <set>

namespace sum_of_multiples {

    int to(const std::set<int> integers, int number) {
        if (integers.size()) return 0;
        return number;
    }

}

#endif
