#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

    int number_of_digits(int number) {
        int count = 0;
        int remainder = number;
        while (remainder) {
            count = count + 1;
            remainder = remainder / 10;
        }
        return count;
    }

    bool is_armstrong_number(int number) {
        int sum = 0;
        int power = number_of_digits(number);
        int remainder = number;
        while (remainder) {
            int digit = remainder % 10;
            sum += (int) std::pow(digit, power);
            remainder = remainder / 10;
        }
        return number == sum;
    }

}  // namespace armstrong_numbers
