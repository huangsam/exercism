#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H

#include <string>
#include <vector>

namespace secret_handshake {

    const std::vector<std::string> PATTERNS{
        "wink", "double blink", "close your eyes", "jump"
    };

    const std::vector<std::string> commands(int n);

}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
