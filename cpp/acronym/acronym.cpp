#include "acronym.h"
#include <locale>
#include <sstream>

namespace acronym {

    const std::string acronym(const std::string &input) {
        std::stringstream ss;
        for (std::size_t i = 0; i < input.length(); i++) {
            const char ch = input[i];
            if (i == 0 && isalpha(ch)) {
                ss << (char) std::toupper(ch);
            } else if (i + 1 < input.length() && (ch == '-' || ch == ' ')) {
                const char nextCh = input[i + 1];
                if (isalpha(nextCh)) {
                    ss << (char) std::toupper(nextCh);
                }
            }
        }
        return ss.str();
    }

}  // namespace acronym
