#include "Graph.hpp"
#include "Vertex.hpp"
#include "InstanceLoader.hpp"

Graph::Graph(string instanceFile) {
    InstanceLoader loader;
    loader.run(instanceFile, this->vertexes);
}

void Graph::setGraphAlgorithm(GraphAlgorithm *alg) {
    algorithm.reset(alg);
}

void Graph::runAlgorithm() const {
    if (algorithm.get() != nullptr)
        algorithm.get()->run(*this);
}

list<Vertex> const& Graph::getVertexes() const {
    return vertexes;
}
