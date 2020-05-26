#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <cctype>
#include <string>

namespace pangram {

    const int alpha_size = 26;

    bool is_pangram(const std::string &input);

}  // namespace pangram

#endif // PANGRAM_H
