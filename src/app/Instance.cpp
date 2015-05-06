#include "Instance.hpp"
#include "Options.hpp"

#include <sstream>

Instance::Instance(string file) : name(file), positiveErrors(0), negativeErrors(0), n(0) {
    vector<string> tokens = split(name, '/');
    tokens = split(tokens.back(), '.');

    tokens = split(tokens.back(), '-');
    if (tokens.size() == 1) {
        tokens = split(tokens.back(), '+');
        this->positiveErrors = stoul(tokens[1], nullptr);
    } else {
        this->negativeErrors = stoul(tokens[1], nullptr);
    }
    this->idealSpectrum = stoul(tokens[0], nullptr);
    this->n = idealSpectrum + Options::getInstance().getBasePairsPerOligonucleotide() - 1;
}

vector<string> Instance::split(string const& s, char delim) {
    vector<string> tokens;
    istringstream ss(s);
    string item;

    while(getline(ss, item, delim))
        tokens.push_back(item);

    return tokens;
}
