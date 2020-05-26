#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <string>

namespace scrabble_score {

    constexpr int SCRABBLE_VALUES[26]{
        1, 3, 3, 2, 1, 4,
        2, 4, 1, 8, 5, 1,
        3, 1, 1, 3, 10, 1,
        1, 1, 1, 4, 4, 8,
        4, 10
    };

    int score(const std::string &word);

}  // namespace scrabble_score

#endif // SCRABBLE_SCORE_H
