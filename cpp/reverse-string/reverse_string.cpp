#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const std::string &word) {
        std::string result;
        copy(word.crbegin(), word.crend(), std::back_inserter(result));
        return result;
    }

}  // namespace reverse_string
