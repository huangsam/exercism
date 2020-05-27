#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <map>
#include <string>
#include <unordered_set>

namespace allergies {

    typedef std::unordered_set<std::string> allergy_set;

    constexpr int MAX_SCORE = 256;

    const std::map<std::string, int> ITEM_VALUES{
        {"eggs", 1},
        {"peanuts", 2},
        {"shellfish", 4},
        {"strawberries", 8},
        {"tomatoes", 16},
        {"chocolate", 32},
        {"pollen", 64},
        {"cats", 128}
    };

    class allergy_test {
    private:
        int allergy_score;
    public:
        allergy_test(int score);
        bool is_allergic_to(const std::string &item) const;
        const allergy_set get_allergies() const;
    };

}  // namespace allergies

#endif // ALLERGIES_H