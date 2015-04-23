#ifndef GRAPH
#define GRAPH

#include <list>
#include <string>
#include <memory>

#include "Vertex.hpp"
#include "SequencingAlgorithm.hpp"

using namespace std;

class Graph {
    Graph() = delete;

    list<Vertex> vertexes;
    unique_ptr<SequencingAlgorithm> seqAlgorithm;

    public:
        Graph(string filename);

        list<Vertex> const& getVertexes() const;
        void setSequencingAlgorithm(SequencingAlgorithm *seqAlg);
        void runAlgorithm() const;
};

#endif