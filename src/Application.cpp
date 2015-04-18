#include <iostream>

#include "Graph.hpp"
#include "SequencingAlgorithm.hpp"

int main(int argc, char *argv[]) {
    std::cout << "SeQuence\n";

    Graph g("data/instances/9.200-40");
    g.setSequencingAlgorithm(new SimpleHeuristic());
    g.runAlgorithm();

    return 0;
}
