#ifndef GRAPH
#define GRAPH

#include <list>
#include <string>
#include <memory>

#include "Vertex.hpp"
#include "GraphAlgorithm.hpp"

using namespace std;

class Graph {
    Graph() = delete;

    list<Vertex> vertexes;
    unique_ptr<GraphAlgorithm> algorithm;

    public:
        Graph(string filename);

        list<Vertex> const& getVertexes() const;
        void setGraphAlgorithm(GraphAlgorithm *alg);
        void runAlgorithm() const;
};

#endif
