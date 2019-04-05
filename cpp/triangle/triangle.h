#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#define EXERCISM_RUN_ALL_TESTS

#include <stdexcept>

namespace triangle {

    enum flavor { equilateral, isosceles, scalene };

    bool is_invalid(double a, double b, double c) {
        return (a <= 0 || b <= 0 || c <= 0) \
            || (a+b < c || b+c < a || c+a < b);
    }

    bool is_equilateral(double a, double b, double c) {
        return a == b && b == c;
    }

    bool is_isosceles(double a, double b, double c) {
        return a == b || b == c || c == a;
    }

    flavor kind(double a, double b, double c) {
        if (is_invalid(a, b, c)) {
            throw std::domain_error("invalid triangle");
        } else if (is_equilateral(a, b, c)) {
            return equilateral;
        } else if (is_isosceles(a, b, c)) {
            return isosceles;
        }
        return scalene;
    }

}

#endif