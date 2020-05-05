#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#define EXERCISM_RUN_ALL_TESTS

#include <cstdint>

namespace space_age {

    class space_age {
    public:
        space_age(uint64_t seconds): seconds_(seconds) {}
        constexpr uint64_t seconds() const { return seconds_; }
        constexpr double on_earth() const { return seconds_ / earth_seconds_; }
        constexpr double on_mercury() const { return seconds_ / mercury_seconds_; }
        constexpr double on_venus() const { return seconds_ / venus_seconds_; }
        constexpr double on_mars() const { return seconds_ / mars_seconds_; }
        constexpr double on_jupiter() const { return seconds_ / jupiter_seconds_; }
        constexpr double on_saturn() const { return seconds_ / saturn_seconds_; }
        constexpr double on_uranus() const { return seconds_ / uranus_seconds_; }
        constexpr double on_neptune() const { return seconds_ / neptune_seconds_; }
    private:
        uint64_t seconds_;
        static constexpr double earth_seconds_ = 31557600;
        static constexpr double mercury_seconds_ = earth_seconds_ * 0.2408467;
        static constexpr double venus_seconds_ = earth_seconds_ * 0.61519726;
        static constexpr double mars_seconds_ = earth_seconds_ * 1.8808158;
        static constexpr double jupiter_seconds_ = earth_seconds_ * 11.862615;
        static constexpr double saturn_seconds_ = earth_seconds_ * 29.447498;
        static constexpr double uranus_seconds_ = earth_seconds_ * 84.016846;
        static constexpr double neptune_seconds_ = earth_seconds_ * 164.79132;
    };

}  // namespace space_age

#endif // SPACE_AGE_H
