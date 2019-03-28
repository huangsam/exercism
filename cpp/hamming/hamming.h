#if !defined(HAMMING_H)
#define HAMMING_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace hamming {

    int compute(const std::string &s1, const std::string &s2) {
        if (s1.length() != s2.length()) {
            throw std::domain_error("strands are not of equal length");
        }
        int result = 0;
        int i = 0;
        for (auto it = s1.begin(); it != s1.end(); i++, it++) {
            if (s1[i] != s2[i]) {
                result += 1;
            }
        }
        return result;
    }

}

#endif
