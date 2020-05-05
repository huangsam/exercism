#include "rna_transcription.h"

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

}  // namespace transcription
