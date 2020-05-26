#if !defined(TRANSCRIPTION_H)
#define TRANSCRIPTION_H

#include <string>

namespace rna_transcription {

    char to_rna(char in);
    std::string to_rna(const std::string &in);

}  // namespace rna_transcription

#endif // TRANSCRIPTION_H
