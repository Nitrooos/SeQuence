#include "InstanceLoader.hpp"
#include "../helper/Converter.hpp"
#include "Vertex.hpp"
#include "../app/Options.hpp"
#include "../helper/Helpers.hpp"
#include "../Exceptions.hpp"

#include <fstream>

InstanceLoader::InstanceLoader() {}

void InstanceLoader::run(string file, list<Vertex> &vertexes) const {
    ifstream F(file);
    if (F.fail())
        throw CannotOpenInstanceFileError(file);

    string oligonucleotide;
    Converter c;

    vertexes.clear();
    while (F >> oligonucleotide) {
        static bool firstOligonucleotide = true;
        if (firstOligonucleotide) {
            Options::getInstance().setBasePairsPerOligonucleotide(oligonucleotide.size());
            firstOligonucleotide = false;
        }

        vertexes.push_back(Vertex(c.convert(oligonucleotide)));
    }

    this->addSuccessorsToVertexes(vertexes);
}

void InstanceLoader::addSuccessorsToVertexes(list<Vertex> &vertexes) const {
    for (auto &vertex : vertexes)
        for (auto &cand : vertexes) {
            int common = CommonPart::get(vertex, cand);
            if (common >= Options::getInstance().getMinCommonPart())
                vertex.addSuccessor(&cand, common);
        }
}
