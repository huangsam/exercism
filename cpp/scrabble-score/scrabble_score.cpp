#include "scrabble_score.h"
#include <cctype>

namespace scrabble_score {

    int score(const std::string &word) {
        int score = 0;
        for (const auto &ch : word) {
            score += SCRABBLE_VALUES[std::tolower(ch) - 'a'];
        }
        return score;
    }

}  // namespace scrabble_score
