#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#define EXERCISM_RUN_ALL_TESTS

#include <stdexcept>

using namespace std;

namespace triangle {

    enum flavor { equilateral, isosceles, scalene };

    bool is_invalid(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            return true;
        } else if (a+b < c || b+c < a || c+a < b) {
            return true;
        }
        return false;
    }

    bool is_equilateral(double a, double b, double c) {
        return a == b && b == c;
    }

    bool is_isosceles(double a, double b, double c) {
        return a == b || b == c || c == a;
    }

    flavor kind(double a, double b, double c) {
        if (is_invalid(a, b, c)) {
            throw domain_error("invalid");
        } else if (is_equilateral(a, b, c)) {
            return equilateral;
        } else if (is_isosceles(a, b, c)) {
            return isosceles;
        }
        return scalene;
    }

}

#endif
