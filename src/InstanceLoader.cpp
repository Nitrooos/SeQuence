#include "InstanceLoader.hpp"
#include "Converter.hpp"
#include "Vertex.hpp"

#include <fstream>

InstanceLoader::InstanceLoader() {}

void InstanceLoader::run(string file, vector<Vertex> &vertexes) const {
    ifstream F(file);

    string oligonucleotide;
    Converter c;

    vertexes.clear();
    while (F >> oligonucleotide) {
        vertexes.push_back(Vertex(c.convert(oligonucleotide)));
    }
}
