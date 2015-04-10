#ifndef CONVERTER
#define CONVERTER

#include <string>

using namespace std;

class Converter {
    char getNthNucleotide(int oligo, int n) const;
    char getNthNucleotide(char nucleotide) const;

    public:
        Converter();
        int convert(string const& oligo) const;
        string convert(int oligo, int base_pairs = 10) const;
};

#endif  // CONVERTER
