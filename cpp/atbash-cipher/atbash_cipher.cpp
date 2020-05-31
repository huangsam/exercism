#include "atbash_cipher.h"
#include <locale>

namespace atbash_cipher {

    inline char cipher(char ch) {
        return 'z' - (std::tolower(ch) - 'a');
    }

    const std::string inverse(const std::string &input, bool space) {
        std::string result("");
        int alnum_count = 0;
        for (auto it = input.begin(); it != input.end(); it++) {
            const char ch = *it;
            if (!std::isalnum(ch)) {
                continue;
            }
            result += std::isdigit(ch) ? ch : cipher(ch);
            if (space && ++alnum_count % CIPHER_SEQ_SIZE == 0) {
                result += ' ';
            }
        }
        if (space && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    const std::string encode(const std::string &input) {
        return inverse(input, true);
    }

    const std::string decode(const std::string &input) {
        return inverse(input, false);
    }

}  // namespace atbash_cipher
