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

    map<char, int> transform(const map<int, vector<char>> old) {
        map<char, int> result;
        for (const auto &it : old) {
            int const points = it.first;
            const vector<char> chars = it.second;
            for (const auto &sit : chars) {
                result[tolower(sit)] = points;
            }
        }
        return result;
    }

}

#endif
