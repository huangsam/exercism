#if !defined(MATCHING_BRACKETS_H)
#define MATCHING_BRACKETS_H

#include <map>
#include <set>
#include <string>

namespace matching_brackets {

    constexpr char MATCH_BAD = '\0';
    const std::set<char> OPEN{'{', '[', '('};
    const std::map<char, char> MATCHES{
        {'{', '}'},
        {'}', '{'},
        {'[', ']'},
        {']', '['},
        {'(', ')'},
        {')', '('}
    };

    bool check(const std::string &input);

}  // namespace matching_brackets

#endif // MATCHING_BRACKETS_H
