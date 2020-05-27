#include "allergies.h"

namespace allergies {

    allergy_test::allergy_test(int score) {
        allergy_score = score % MAX_SCORE;
    }

    bool allergy_test::is_allergic_to(const std::string &item) const {
        int score_one = allergy_score;
        int score_two = ITEM_VALUES.at(item);
        while (score_two > 1) {
            score_one >>= 1;
            score_two >>= 1;
        }
        return (score_one & score_two) == 1;
    }

    const allergy_set allergy_test::get_allergies() const {
        allergy_set result{};
        for (auto it = ITEM_VALUES.begin(); it != ITEM_VALUES.end(); it++) {
            const std::string item = it->first;
            if (is_allergic_to(item)) result.insert(item);
        }
        return result;
    }

}  // namespace allergies
