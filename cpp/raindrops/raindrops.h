#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#define EXERCISM_RUN_ALL_TESTS

#include <string>

using namespace std;

namespace raindrops {

    string convert(int n) {
        string s = "";
        if (n % 3 == 0) {
            s += "Pling";
        }
        if (n % 5 == 0) {
            s += "Plang";
        }
        if (n % 7 == 0) {
            s += "Plong";
        }
        if (s.length() > 0) {
            return s;
        }
        return to_string(n);
    }

}

#endif
