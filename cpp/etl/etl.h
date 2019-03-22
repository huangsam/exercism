#if !defined(ETL_H)
#define ETL_H

#define EXERCISM_RUN_ALL_TESTS

#include <map>
#include <vector>

using namespace std;

namespace etl {

    char tolower(char in) {
        if ('A' <= in && in <= 'Z') {
            return in - ('Z' - 'z');
        }
        return in;
    }

    map<char, int> transform(map<int, vector<char>> const old) {
        map<char, int> result;
        for (auto const &it : old) {
            int const points = it.first;
            vector<char> const chars = it.second;
            for (auto const &sit : chars) {
                result[tolower(sit)] = points;
            }
        }
        return result;
    }
}

#endif
