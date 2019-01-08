#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond {
    ptime advance(const ptime& current) {
        return current + seconds(1000000000);
    }
}
