#include "allergies.h"

namespace allergies {

    allergy_test::allergy_test(int score) {
        for (int i = 0; i < 8; i++) {
            if (1 << i & score) {
                all_allergies.insert(VALUE_PER_ITEM[i]);
            }
        }
    }

    bool allergy_test::is_allergic_to(const std::string &item) const {
        return all_allergies.count(item);
    }

    const allergy_set allergy_test::get_allergies() const {
        return all_allergies;
    }

}  // namespace allergies
