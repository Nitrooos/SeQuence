#include "InstanceLoader.hpp"
#include "Converter.hpp"
#include "Vertex.hpp"
#include "Options.hpp"
#include "Helpers.hpp"
#include "Exceptions.hpp"

#include <fstream>

InstanceLoader::InstanceLoader() {}

void InstanceLoader::run(string file, vector<Vertex> &vertexes) const {
    ifstream F(file);
    if (F.fail())
        throw CannotOpenInstanceFileError(file);

    string oligonucleotide;
    Converter c;

    vertexes.clear();
    while (F >> oligonucleotide) {
        vertexes.push_back(Vertex(c.convert(oligonucleotide)));
    }

    this->addSuccessorsToVertexes(vertexes);
}

void InstanceLoader::addSuccessorsToVertexes(vector<Vertex> &vertexes) const {
    for (auto &vertex : vertexes)
        for (auto &cand : vertexes) {
            int common = CommonPart::get(vertex, cand);
            if (common >= Options::getMinCommonPart())
                vertex.addSuccessor(&cand, common);
        }
}
