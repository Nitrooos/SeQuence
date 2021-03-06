#include "Vertex.hpp"

Vertex::Vertex() : oligonucleotide(0) {}

Vertex::Vertex(int oligo) : oligonucleotide(oligo) {}

void Vertex::addSuccessor(Vertex *v, int commonPart) {
    successors.insert(make_pair(v, commonPart));
}

int Vertex::getValue() const {
    return oligonucleotide;
}
