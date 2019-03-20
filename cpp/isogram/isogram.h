#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <cctype>
#include <string>

using namespace std;

namespace isogram {

    bool is_isogram(const string& input) {
        bool c[26] = {false};
        for (const auto& it : input) {
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
