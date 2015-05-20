#include "Result.hpp"
#include "../helper/Converter.hpp"

void Result::addOligonucleotide(pair<const Vertex*, int> const& o) {
    oligonucleotidesUsed.push_back(o);
}

void Result::recalculate() {
    nOligonucleotides = oligonucleotidesUsed.size();
    
    Converter c;
    sequence = "";
    for (auto o : oligonucleotidesUsed) {
        sequence += c.convert(o.first->getValue()).substr(o.second);
    }
    sequenceLength = sequence.size();
}
