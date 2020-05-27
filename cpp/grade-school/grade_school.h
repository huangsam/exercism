#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <string>
#include <vector>

namespace grade_school {

    typedef std::map<int, std::vector<std::string>> rostermap;
    typedef std::vector<std::string> rosterclass;

    class school {
    private:
        rostermap r;
    public:
        void add(const std::string &name, int grade);
        rostermap roster() const;
        rosterclass grade(int grade) const;
    };

}  // namespace grade_school

#endif // GRADE_SCHOOL_H
