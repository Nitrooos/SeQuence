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

    this->addSuccessorsToVertexes(vertexes);
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
    unsigned int initialMask = ((unsigned)(~0) >>
                                (8*Options::getBytesPerInt() - 2*Options::getBasePairsPerOligonucleotide()));

    for (int i = 1; i < Options::getBasePairsPerOligonucleotide(); ++i) {
        int tempV = (vertex.getValue() >> 2*i),
            tempC = candidate.getValue() & (initialMask >> 2*i);
        // sprawdź czy kandydat ma 10 - i wspólnych zasad z wyjątkiem pierwszej
        // z badanym oligonukleotydem
        if ((tempV ^ tempC) == 0 )
            return 10 - i;
    }

    return 0;
}
