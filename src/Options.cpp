#include "Options.hpp"
#include "Exceptions.hpp"

Options::Options()
    : minCommonPart(7), basePairsPerOligonucleotide(10) {}

Options& Options::getInstance() {
    static Options instance;

    return instance;
}

int Options::getMinCommonPart() {
    return minCommonPart;
}

int Options::getBasePairsPerOligonucleotide() {
    return basePairsPerOligonucleotide;
}

void Options::setMinCommonPart(int minCommonPart) {
    this->minCommonPart = minCommonPart;
}

void Options::setBasePairsPerOligonucleotide(int bpPerOligo) {
    if (getBytesPerInt()*8 < bpPerOligo*2)
        throw NoEnoughSpaceInInt(bpPerOligo);

    this->basePairsPerOligonucleotide = bpPerOligo;
}
