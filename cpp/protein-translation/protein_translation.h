#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <map>
#include <string>
#include <vector>

namespace protein_translation {

    constexpr std::size_t PROTEIN_SIZE = 3;

    const std::map<std::string, std::string> PROTEIN_MAPPING = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"}
    };

    std::vector<std::string> proteins(const std::string &input);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
