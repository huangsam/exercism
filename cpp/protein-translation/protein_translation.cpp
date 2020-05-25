#include "protein_translation.h"
#include <map>

namespace protein_translation {

    static constexpr std::size_t PROTEIN_SIZE = 3;

    static const std::map<std::string, std::string> PROTEIN_MAPPING = {
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

    std::vector<std::string> proteins(const std::string &input) {
        std::vector<std::string> result;
        for (std::size_t i = 0; i < input.length(); i += PROTEIN_SIZE) {
            auto sequence = input.substr(i, PROTEIN_SIZE);
            auto protein = PROTEIN_MAPPING.find(sequence)->second;
            if (protein.empty()) break;
            result.push_back(protein);
        }
        return result;
    }

}  // namespace protein_translation
