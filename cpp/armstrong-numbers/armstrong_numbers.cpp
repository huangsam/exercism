#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

    bool is_armstrong_number(int number) {
        int sum = 0;
        int digits = (int) (std::log10(number) + 1);
        for (int left = number; left > 0; left /= 10) {
            sum += (int) std::pow(left % 10, digits);
        }
        return number == sum;
    }

}  // namespace armstrong_numbers
