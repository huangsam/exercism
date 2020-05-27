#include "hexadecimal.h"

namespace hexadecimal {

    int convert(const std::string &hex) {
        if (COLORS.count(hex)) {
            return COLORS.at(hex);
        }
        int factor = 1;
        int sum = 0;
        for (auto it = hex.rbegin(); it != hex.rend(); it++, factor *= HEXMAX) {
            char ch = *it;
            int value = (ch >= 'a') ? (ch - 'a' + 10) : (ch - '0');
            if (value < HEXMIN || value > HEXMAX) return 0;
            sum += value * factor;
        }
        return sum;
    }

}  // namespace hexadecimal
