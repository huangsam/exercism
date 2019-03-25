#if !defined(TRANSCRIPTION_H)
#define TRANSCRIPTION_H

#include <string>

using namespace std;

#define EXERCISM_RUN_ALL_TESTS

namespace transcription {
    char to_rna(char in) {
        if (in == 'G') {
            return 'C';
        } else if (in == 'C') {
            return 'G';
        } else if (in == 'A') {
            return 'U';
        } else if (in == 'T') {
            return 'A';
        }
        return '?';
    }

    string to_rna(string in) {
        string result;
        for (auto const &i : in) {
            result += to_rna(i);
        }
        return result;
    }
}

#endif
