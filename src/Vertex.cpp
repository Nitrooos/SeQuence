#include "Vertex.hpp"

Vertex::Vertex(int oligo) : oligonucleotide(oligo) {}

void Vertex::addSuccessor(Vertex *v) {
    // TO DO
}

int Vertex::getValue() const {
    return oligonucleotide;
}
