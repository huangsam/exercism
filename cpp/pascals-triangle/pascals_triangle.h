#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H

#include <string>
#include <vector>

namespace pascals_triangle {

    typedef std::vector<std::vector<int>> triangle;
    typedef std::vector<int> triangle_row;

    triangle generate_rows(int rows);

}  // namespace pascals_triangle

#endif // PASCALS_TRIANGLE_H
