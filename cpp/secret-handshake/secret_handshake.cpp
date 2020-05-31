#include "secret_handshake.h"

namespace secret_handshake {

    const std::vector<std::string> commands(int n) {
        std::vector<std::string> result;
        for (std::size_t i = 0; i < PATTERNS.size(); i++) {
            if ((1 << i) & n) {
                result.push_back(PATTERNS.at(i));
            }
        }
        if (16 & n) {
            std::reverse(result.begin(), result.end());
        }
        return result;
    }

}  // namespace secret_handshake
