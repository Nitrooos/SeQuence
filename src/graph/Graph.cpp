#include "Graph.hpp"
#include "Vertex.hpp"
#include "InstanceLoader.hpp"

#include "../helper/Converter.hpp"
#include <iostream>

Graph::Graph() { }

void Graph::load(string instanceFile) {
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

void Graph::printGraph() const {
    Converter c;
    for (auto &v : vertexes) {
        cout << "\t" << c.convert(v.getValue()) << ":\n";
        for (auto &succ : v.getSuccessors()) {
            cout << "\t\t" << c.convert(succ.first->getValue()) << ": " << succ.second << "\n";
        }
    }
}
