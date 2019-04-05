#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <string>
#include <cctype>

namespace pangram {

    bool is_pangram(const std::string &input) {
        bool alpha[26];
        for (const auto &i : input) {
            if (std::isalpha(i)) {
                int ch = int(std::tolower(i) - 'a');
                alpha[ch] |= true;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (!alpha[i]) return false;
        }
        return true;
    }

}

#endif