#include "trinary.h"

namespace trinary {

    int to_decimal(const std::string &input) {
        int sum = 0;
        int factor = 1;
        for (auto it = input.rbegin(); it != input.rend(); it++, factor *= 3) {
            int num = (int) (*it - '0');
            if (num < 0 || num > 2) return 0;
            sum += num * factor;
        }
        return sum;
    }

}  // namespace trinary
