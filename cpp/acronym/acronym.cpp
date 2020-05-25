#include "acronym.h"
#include <numeric>
#include <regex>

namespace acronym {

    const std::string acronym(const std::string &input) {
        const std::regex expr(R"(\w+)");
        return std::accumulate(
            std::sregex_iterator(input.begin(), input.end(), expr),
            std::sregex_iterator(),
            std::string{},
            [](const auto &result, const auto &match) {
                return result + (char) std::toupper(match.str()[0]);
            }
        );
    }

}  // namespace acronym
