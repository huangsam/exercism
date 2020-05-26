#include "pascals_triangle.h"

namespace pascals_triangle {

    triangle_row next_row(const triangle_row &current) {
        triangle_row next{current.front()};
        for (std::size_t i = 1; i < current.size(); i++) {
            next.push_back(current[i] + current[i - 1]);
        }
        next.push_back(current.back());
        return next;
    }

    triangle generate_rows(int row) {
        if (row == 0) return triangle{};
        triangle result{triangle_row{1}};
        for (int i = 1; i < row; i++) {
            triangle_row next = next_row(result.back());
            result.push_back(next);
        }
        return result;
    }

}  // namespace pascals_triangle
