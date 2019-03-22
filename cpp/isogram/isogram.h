#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#define EXERCISM_RUN_ALL_TESTS

#include <cctype>
#include <string>

using namespace std;

namespace isogram {

    bool is_isogram(string const &input) {
        bool c[26] = {false};
        for (auto const &it : input) {
            if (isalpha(it)) {
                int cid = (int) (tolower(it) - 'a');
                if (c[cid]) {
                    return false;
                }
                c[cid] = true;
            }
        }
        return true;
    }

}

#endif
