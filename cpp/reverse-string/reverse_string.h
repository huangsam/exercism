#if !defined(REVERSE_H)
#define REVERSE_H

#include <string>

using namespace std;

namespace reverse_string {

    string reverse_string(string const &word) {
        string result;
        copy(word.crbegin(), word.crend(), back_inserter(result));
        return result;
    }

}

#endif
