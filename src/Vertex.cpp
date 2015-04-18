#include "Vertex.hpp"

#include <iostream>

Vertex::Vertex(int oligo) : oligonucleotide(oligo) {}

void Vertex::addSuccessor(Vertex *v, int commonPart) {
    successors.insert(make_pair(v, commonPart));
}

int Vertex::getValue() const {
    return oligonucleotide;
}

void Vertex::printSuccessors() const {
    for (auto &s : successors) {
        cout << s.second << "\n";
    }
}
