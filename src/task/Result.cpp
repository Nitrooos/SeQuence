#include "Result.hpp"

void Result::addOligonucleotide(const Vertex *o) {
    oligonucleotidesUsed.push_back(o);
}

void Result::recalculate() {
    nOligonucleotides = oligonucleotidesUsed.size();
    
    for (auto o : oligonucleotidesUsed) {
        // sklejanie sequence
    }
    
    sequenceLength = sequence.size();
}
