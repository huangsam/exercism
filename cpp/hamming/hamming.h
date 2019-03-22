#if !defined(HAMMING_H)
#define HAMMING_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

using namespace std;

namespace hamming {
    int compute(string const &s1, string const &s2) {
        if (s1.length() != s2.length()) {
            throw domain_error("Both strands are not of equal length");
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
