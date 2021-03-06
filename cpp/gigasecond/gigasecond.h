#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

using boost::posix_time::ptime;
using boost::posix_time::seconds;

namespace gigasecond {

    ptime advance(const ptime &current);

}  // namespace gigasecond

#endif // GIGASECOND_H
