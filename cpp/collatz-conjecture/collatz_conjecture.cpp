#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

    int steps(int number) {
        if (number < 1) {
            throw std::domain_error("invalid number");
        }
        int count = 0;
        while (number != 1) {
            if (number % 2 == 0) {
                number = number / 2;
            } else {
                number = 3 * number + 1;
            }
            count++;
        }
        return count;
    }

}  // namespace collatz_conjecture
