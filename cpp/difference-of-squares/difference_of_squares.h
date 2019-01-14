#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H

namespace squares {
    int square_of_sum(int x) {
        int sum = x * (x + 1) / 2;
        return sum * sum;
    }

    int sum_of_squares(int x) {
        return x * (x + 1) * (2 * x + 1) / 6;
    }

    int difference(int x) {
        return square_of_sum(x) - sum_of_squares(x);
    }
}

#endif
