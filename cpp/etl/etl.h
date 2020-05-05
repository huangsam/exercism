#if !defined(ETL_H)
#define ETL_H

#define EXERCISM_RUN_ALL_TESTS

#include <cctype>
#include <map>
#include <vector>

namespace etl {

    typedef std::map<int, std::vector<char>> oldmap;
    typedef std::map<char, int> newmap;

    newmap transform(const oldmap &old);

}  // namespace etl

#endif // ETL_H
