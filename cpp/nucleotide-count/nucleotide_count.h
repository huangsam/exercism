#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {

    class counter {
    private:
        std::string dna_seq;
        std::map<char, int> dna_map;
    public:
        counter(const std::string &str);
        int count(char ch) const;
        const std::map<char, int>& nucleotide_counts() const;
    };

}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
