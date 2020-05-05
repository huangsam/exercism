#if !defined(TRANSCRIPTION_H)
#define TRANSCRIPTION_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace transcription {

    char to_rna(char in);
    std::string to_rna(const std::string &in);

}  // namespace transcription

#endif // TRANSCRIPTION_H
