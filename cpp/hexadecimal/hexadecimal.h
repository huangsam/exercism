#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <map>
#include <string>

namespace hexadecimal {

    constexpr int HEXMIN = 0;
    constexpr int HEXMAX = 16;

    const std::map<std::string, int> COLORS{
        {"black", 0x000000},
        {"white", 0xffffff},
        {"yellow", 0xffff00}
    };

    int convert(const std::string &hex);

}  // namespace hexadecimal

#endif // HEXADECIMAL_H
