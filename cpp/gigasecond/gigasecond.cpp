#include "gigasecond.h"

namespace gigasecond {

    ptime advance(const ptime &current) {
        return current + seconds(1000000000);
    }

}
