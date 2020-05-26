#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <cctype>
#include <string>

namespace isogram {

    constexpr int ALPHA_SIZE = 26;

    bool is_isogram(const std::string &input);

}  // namespace isogram

#endif // ISOGRAM_H
