#include "pangram.h"

namespace pangram {

    bool is_pangram(const std::string &input) {
        bool cache[alpha_size] = {false};
        for (const auto &i : input) {
            if (std::isalpha(i)) {
                int ch = int(std::tolower(i) - 'a');
                cache[ch] |= true;
            }
        }
        for (int i = 0; i < alpha_size; i++) {
            if (!cache[i]) return false;
        }
        return true;
    }

}
