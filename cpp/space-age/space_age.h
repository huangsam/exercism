#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#define EXERCISM_RUN_ALL_TESTS

#include <cstdint>

namespace space_age {

    class space_age {
    public:
        space_age(uint64_t seconds) { seconds_ = seconds; }
        uint64_t seconds() const { return seconds_; }
        double on_earth() const { return seconds_ / earth_seconds_; }
        double on_mercury() const { return seconds_ / mercury_seconds_; }
        double on_venus() const { return seconds_ / venus_seconds_; }
        double on_mars() const { return seconds_ / mars_seconds_; }
        double on_jupiter() const { return seconds_ / jupiter_seconds_; }
        double on_saturn() const { return seconds_ / saturn_seconds_; }
        double on_uranus() const { return seconds_ / uranus_seconds_; }
        double on_neptune() const { return seconds_ / neptune_seconds_; }
    private:
        uint64_t seconds_;
        double earth_seconds_ = 31557600;
        double mercury_seconds_ = earth_seconds_ * 0.2408467;
        double venus_seconds_ = earth_seconds_ * 0.61519726;
        double mars_seconds_ = earth_seconds_ * 1.8808158;
        double jupiter_seconds_ = earth_seconds_ * 11.862615;
        double saturn_seconds_ = earth_seconds_ * 29.447498;
        double uranus_seconds_ = earth_seconds_ * 84.016846;
        double neptune_seconds_ = earth_seconds_ * 164.79132;
    };

}

#endif
