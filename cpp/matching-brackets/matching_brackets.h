#if !defined(MATCHING_BRACKETS_H)
#define MATCHING_BRACKETS_H

#include <map>
#include <string>
#include <set>

namespace matching_brackets {

    constexpr char MATCH_BAD = '?';
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
