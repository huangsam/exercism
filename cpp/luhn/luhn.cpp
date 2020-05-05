#include "lunh.h"

namespace luhn {

    bool valid(const std::string &candidate) {
        int length = 0, sum = 0;
        int map[] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
        };
        for (int i = candidate.size() - 1; i >= 0; i--) {
            char c = candidate[i];
            if (c == ' ') continue;
            if (c < '0' || c > '9') return false;
            length += 1;
            int offset = int(c - '0');
            sum += map[length % 2 == 0 ? offset * 2 : offset];
        }
        return length > 1 && sum % 10 == 0;
    }

}  // namespace luhn
