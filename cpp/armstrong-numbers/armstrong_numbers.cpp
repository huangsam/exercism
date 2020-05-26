#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

    bool is_armstrong_number(int number) {
        int sum = 0;
        int power = (int) std::log10(number) + 1;
        int remainder = number;
        while (remainder) {
            int digit = remainder % 10;
            sum += (int) std::pow(digit, power);
            remainder = remainder / 10;
        }
        return number == sum;
    }

}  // namespace armstrong_numbers
