#if !defined(TRANSCRIPTION_H)
#define TRANSCRIPTION_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace transcription {

    char to_rna(char in) {
        switch (in) {
            case 'C': return 'G';
            case 'G': return 'C';
            case 'A': return 'U';
            case 'T': return 'A';
            default: return '?';
        }
    }

    std::string to_rna(const std::string &in) {
        std::string result;
        for (const auto &i : in) {
            result += to_rna(i);
        }
        return result;
    }

}

#endif
