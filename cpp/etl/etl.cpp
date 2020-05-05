#include "etl.h"

namespace etl {

    newmap transform(const oldmap &old) {
        newmap result;
        for (const auto &it : old) {
            const auto points = it.first;
            const auto chars = it.second;
            for (const auto &sit : chars) {
                result[tolower(sit)] = points;
            }
        }
        return result;
    }

}
