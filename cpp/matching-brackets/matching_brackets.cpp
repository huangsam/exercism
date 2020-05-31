#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

    inline bool isopen(char ch) {
        return OPEN.count(ch);
    }

    inline char complement(char ch) {
        return MATCHES.count(ch) ? MATCHES.at(ch) : MATCH_BAD;
    }

    bool check(const std::string &input) {
        std::stack<char> outer;
        for (const char &ch: input) {
            const char match = complement(ch);
            if (match == MATCH_BAD) {
                continue;
            } else if (isopen(ch)) {
                outer.push(match);
            } else if (outer.empty() || outer.top() != ch) {
                return false;
            } else {
                outer.pop();
            }
        }
        return outer.empty();
    }

}  // namespace matching_brackets
