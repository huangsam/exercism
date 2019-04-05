#if !defined(PANGRAM_H)
#define PANGRAM_H

#define EXERCISM_RUN_ALL_TESTS

#include <cctype>
#include <string>

namespace pangram {

    const int alpha_size = 26;

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

#endif
