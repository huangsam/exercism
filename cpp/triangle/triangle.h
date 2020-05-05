#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#define EXERCISM_RUN_ALL_TESTS

#include <stdexcept>

namespace triangle {

    enum flavor { equilateral, isosceles, scalene };

    bool is_invalid(double a, double b, double c);
    bool is_equilateral(double a, double b, double c);
    bool is_isosceles(double a, double b, double c);
    flavor kind(double a, double b, double c);

}  // namespace triangle

#endif // TRIANGLE_H
