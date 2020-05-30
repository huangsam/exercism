#include "atbash_cipher.h"
#include <locale>

namespace atbash_cipher {

    const std::string encode(const std::string &input) {
        std::string result("");
        int alnum_count = 0;
        std::string::iterator last_alnum;
        for (auto it = input.begin(); it != input.end(); it++) {
            const char ch = *it;
            if (std::isdigit(ch)) {
                result += ch;
            } else if (std::isalpha(ch)) {
                result += CIPHER_ALPHA.at(std::tolower(ch) - PLAIN_BASE);
            } else {
                continue;
            }
            last_alnum = result.end();
            if (++alnum_count % CIPHER_SEQ_SIZE == 0) {
                result += ' ';
            }
        }
        result.erase(last_alnum, result.end());
        return result;
    }

    const std::string decode(const std::string &input) {
        std::string result("");
        for (auto it = input.begin(); it != input.end(); it++) {
            const char ch = *it;
            if (std::isdigit(ch)) {
                result += ch;
            } else if (std::isalpha(ch)) {
                result += PLAIN_ALPHA.at(CIPHER_BASE - std::tolower(ch));
            }
        }
        return result;
    }

}  // namespace atbash_cipher
