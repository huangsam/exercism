#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    void school::add(const std::string &name, int grade) {
        rosterclass &names = r[grade];
        const auto it = std::lower_bound(names.begin(), names.end(), name);
        names.insert(it, name);
    }

    const rostermap school::roster() const {
        return r;
    }

    const rosterclass school::grade(int grade) const {
        return r.count(grade) ? r.at(grade) : rosterclass{};
    }

}  // namespace grade_school
