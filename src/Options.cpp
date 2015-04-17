#include "Options.hpp"
#include "Exceptions.hpp"

Options::Options()
    : minCommonPart(7), basePairsPerOligonucleotide(10), solutionsNumber(1), timeout(-1) {}

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

int Options::getSolutionsNumber() {
    return solutionsNumber;
}

int Options::getTimeout() {
    return timeout;
}

void Options::setMinCommonPart(int minCommonPart) {
    this->minCommonPart = minCommonPart;
}

void Options::setBasePairsPerOligonucleotide(int bpPerOligo) {
    if (getBytesPerInt()*8 < bpPerOligo*2)
        throw NoEnoughSpaceInInt(bpPerOligo);

    this->basePairsPerOligonucleotide = bpPerOligo;
}

void Options::setSolutionsNumber(int solutionsNumber) {
    this->solutionsNumber = solutionsNumber;
}

void Options::setTimeout(int timeout) {
    this->timeout = timeout;
}
