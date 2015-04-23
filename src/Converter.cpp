#include "Converter.hpp"
#include "Options.hpp"
#include "Exceptions.hpp"

Converter::Converter() { }

int Converter::convert(string const& oligo) const {
    int result = 0;
    for (int i = 0; i < oligo.size(); ++i)
        result |= (getNthNucleotide(oligo[i]) << 2*i);

    return result;
}

string Converter::convert(int oligo) const {
    int base_pairs = Options::getInstance().getBasePairsPerOligonucleotide();

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
        default: return 'A';
    }
}

char Converter::getNthNucleotide(char nucleotide) const {
    switch (nucleotide) {
        case 'A': return 0;
        case 'C': return 1;
        case 'T': return 2;
        case 'G': return 3;
        default: return 0;
    }
}
