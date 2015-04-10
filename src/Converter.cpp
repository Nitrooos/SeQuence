#include "Converter.hpp"
#include "Exceptions.hpp"

Converter::Converter() { }

int Converter::convert(string const& oligo) const {

}

string Converter::convert(int oligo, int base_pairs) const {
    if (sizeof(int)*8 < base_pairs)
        throw NoEnoughSpaceInInt(base_pairs);

    string result = "";
    for (int i = 0; i < base_pairs; ++i)
        result += getNthNucleotide(oligo, i);

    return result;
}

char Converter::getNthNucleotide(int oligo, int n) const {
    int nucleotide = (oligo >> n*2) & 0x3;
    switch (nucleotide) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'T';
        case 3: return 'G';
    }
}
