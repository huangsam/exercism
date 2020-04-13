#include "binary.h"

namespace binary {

    int convert(const std::string &input) {
        int result = 0;
        for (const auto &it: input) {
            if ('a' <= it && it <= 'z') {
                return 0;
            }
            result = (result << 1) + (int) (it - '0');
        }
        return result;
    }

}  // namespace binary
