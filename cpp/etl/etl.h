#if !defined(ETL_H)
#define ETL_H

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
        for (auto it = old.cbegin(); it != old.cend(); it++) {
            int points = it->first;
            vector<char> chars = it->second;
            for (auto sit = chars.cbegin(); sit != chars.cend(); sit++) {
                result[tolower(*sit)] = points;
            }
        }
        return result;
    }
}

#endif
