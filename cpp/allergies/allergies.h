#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>

namespace allergies {

    typedef std::unordered_set<std::string> allergy_set;

    const std::string VALUE_PER_ITEM[8]{
        "eggs", "peanuts", "shellfish", "strawberries",
        "tomatoes", "chocolate", "pollen", "cats"
    };

    class allergy_test {
    private:
        allergy_set all_allergies;
    public:
        allergy_test(int score);
        bool is_allergic_to(const std::string &item) const;
        const allergy_set get_allergies() const;
    };

}  // namespace allergies

#endif // ALLERGIES_H
