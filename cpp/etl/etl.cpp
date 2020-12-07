#include "etl.h"

namespace etl {

    newmap transform(const oldmap &old) {
        newmap result;
        for (const auto &mit : old) {
            const auto points = mit.first;
            const auto chars = mit.second;
            for (const auto &vit : chars) {
                result[tolower(vit)] = points;
            }
        }
        return result;
    }

}  // namespace etl
