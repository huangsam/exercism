#include "isogram.h"

namespace isogram {

    bool is_isogram(const std::string &input) {
        bool cache[ALPHA_SIZE] = {false};
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

}  // namespace isogram
