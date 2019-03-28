#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#define EXERCISM_RUN_ALL_TESTS

#include <cctype>
#include <string>

namespace isogram {

    bool is_isogram(const std::string &input) {
        bool c[26] = {false};
        for (const auto &it : input) {
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
