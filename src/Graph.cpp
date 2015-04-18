#include "Graph.hpp"
#include "Vertex.hpp"
#include "SequencingAlgorithm.hpp"
#include "InstanceLoader.hpp"

Graph::Graph(string instanceFile) {
    InstanceLoader loader;
    loader.run(instanceFile, this->vertexes);
}

void Graph::setSequencingAlgorithm(SequencingAlgorithm *sa) {
    seqAlgorithm.reset(sa);
}

void Graph::runAlgorithm() const {
    seqAlgorithm.get()->run(*this);
}
