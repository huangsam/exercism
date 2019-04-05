#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#define EXERCISM_RUN_ALL_TESTS

#include <cctype>
#include <string>

namespace isogram {

    const int alpha_size = 26;

    bool is_isogram(const std::string &input) {
        bool cache[alpha_size] = {false};
        for (const auto &it : input) {
            if (isalpha(it)) {
                int cid = (int) (tolower(it) - 'a');
                if (cache[cid]) {
                    return false;
                }
                cache[cid] = true;
            }
        }
        return true;
    }

}

#endif
