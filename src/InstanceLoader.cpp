#include "InstanceLoader.hpp"
#include "Converter.hpp"
#include "Vertex.hpp"
#include "Options.hpp"

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

void InstanceLoader::addSuccessorsToVertexes(vector<Vertex> &vertexes) const {
    for (auto &vertex : vertexes)
        for (auto &cand : vertexes) {
            int common = commonPart(vertex, cand);
            if (common >= Options::getMinCommonPart())
                vertex.addSuccessor(&cand, common);
        }
}

int InstanceLoader::commonPart(Vertex const& vertex, Vertex const& candidate) const {
    int bp_per_nuc = Options::getBasePairsPerOligonucleotide(),
        bytes_per_int = Options::getBytesPerInt();

    for (int i = 1; i < Options::getBasePairsPerOligonucleotide(); ++i)
        // sprawdź czy kandydat ma 10 - i wspólnych zasad z wyjątkiem pierwszej
        // z badanym oligonukleotydem
        if (candidate.getValue() & (vertex.getValue() >> 2*i) == (-1 >> (8*bytes_per_int - 2*bp_per_nuc)))
            return 10 - i;
    return 0;
}
