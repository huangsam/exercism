#include "nucleotide_count.h"

namespace nucleotide_count {

    counter::counter(const std::string &str) {
        dna_seq = str;
        dna_map = {
            {'A', 0},
            {'T', 0},
            {'C', 0},
            {'G', 0}
        };
        for (const auto &ch : dna_seq) {
            switch (ch) {
                case 'A':
                case 'T':
                case 'C':
                case 'G':
                    dna_map[ch] += 1;
                    break;
                default:
                    throw std::invalid_argument("invalid");
            }
        }
    }

    int counter::count(char ch) const {
        auto search = dna_map.find(ch);
        if (search == dna_map.end()) {
            throw std::invalid_argument("invalid");
        }
        return dna_map.at(ch);
    }

    const std::map<char, int>& counter::nucleotide_counts() const {
        return dna_map;
    }

}  // namespace nucleotide_count
