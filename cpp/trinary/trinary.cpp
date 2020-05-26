#include "trinary.h"
#include <cmath>
#include <cstdlib>

namespace trinary {

    int to_decimal(const std::string &input) {
        int sum = 0;
        int power = 0;
        for (auto it = input.rbegin(); it != input.rend(); it++, power++) {
            int num = (int) (*it - '0');
            if (num < 0 || num > 2) return 0;
            sum += (int) (num * std::pow(3, power));
        }
        return sum;
    }

}  // namespace trinary
