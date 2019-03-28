#if !defined(ETL_H)
#define ETL_H

#define EXERCISM_RUN_ALL_TESTS

#include <map>
#include <vector>

namespace etl {

    char tolower(char in) {
        if ('A' <= in && in <= 'Z') {
            return in - ('Z' - 'z');
        }
        return in;
    }

    std::map<char, int> transform(const std::map<int, std::vector<char>> &old) {
        std::map<char, int> result;
        for (const auto &it : old) {
            const auto points = it.first;
            const auto chars = it.second;
            for (const auto &sit : chars) {
                result[tolower(sit)] = points;
            }
        }
        return result;
    }

}

#endif
