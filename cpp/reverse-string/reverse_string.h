#if !defined(REVERSE_H)
#define REVERSE_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace reverse_string {

    std::string reverse_string(const std::string &word) {
        std::string result;
        copy(word.crbegin(), word.crend(), std::back_inserter(result));
        return result;
    }

}

#endif
