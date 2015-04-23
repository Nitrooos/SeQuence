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
    if (seqAlgorithm.get() != nullptr)
        seqAlgorithm.get()->run(*this);
}

list<Vertex> const& Graph::getVertexes() const {
    return vertexes;
}
