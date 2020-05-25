#include "protein_translation.h"

namespace protein_translation {

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
