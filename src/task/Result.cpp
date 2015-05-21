#include "Result.hpp"
#include "../helper/Converter.hpp"

void Result::addOligonucleotide(pair<const Vertex*, int> const& o, bool visited) {
    oligonucleotidesUsed.push_back(o);
    if (!visited)
        ++nOligonucleotides;
}

void Result::recalculate() {
    Converter c;
    sequence = "";
    for (auto o : oligonucleotidesUsed) {
        sequence += c.convert(o.first->getValue()).substr(o.second);
    }
    sequenceLength = sequence.size();
}
