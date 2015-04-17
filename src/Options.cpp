#include "Options.hpp"
#include "Exceptions.hpp"

Options::Options()
    : minCommonPart(7), basePairsPerOligonucleotide(10), solutionsNumber(1), timeout(-1),
      logFilename("log"), resultsFilename("results") {}

Options& Options::getInstance() {
    static Options instance;

    return instance;
}

string Options::getInstanceFilename() {
    return instanceFilename;
}

string Options::getLogFilename() {
    return logFilename;
}

string Options::getResultsFilename() {
    return resultsFilename;
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

void Options::setInstanceFilename(string file) {
    this->instanceFilename = file;
}

void Options::setLogFilename(string file) {
    this->logFilename = file;
}

void Options::setResultsFilename(string file) {
    this->resultsFilename = file;
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
