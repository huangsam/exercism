#include "acronym.h"
#include <locale>

namespace acronym {

    const std::string acronym(const std::string &input) {
        std::string result{};
        bool firstAlpha = true;
        for (auto sit = input.begin(); sit != input.end(); sit++) {
            const char ch = *sit;
            if (std::isalpha(ch)) {
                if (!firstAlpha) continue;
                firstAlpha = false;
                result += std::toupper(ch);
            } else {
                firstAlpha = true;
            }
        }
        return result;
    }

}  // namespace acronym
