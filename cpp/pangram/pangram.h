#if !defined(PANGRAM_H)
#define PANGRAM_H

#define EXERCISM_RUN_ALL_TESTS

#define ALPHABET_SIZE 26

#include <string>
#include <cctype>

namespace pangram {

    bool is_pangram(const std::string &input) {
        bool alpha[ALPHABET_SIZE];
        for (const auto &i : input) {
            if (std::isalpha(i)) {
                int ch = int(std::tolower(i) - 'a');
                alpha[ch] |= true;
            }
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (!alpha[i]) return false;
        }
        return true;
    }

}

#endif
