#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Logger.hpp"
#include "../app/Options.hpp"

#include <iostream>

DFS::DFS() { }

void DFS::run(Graph const& g) const {
    cout << "\tDFS::run\n";
}

void DFS::fillStatistic(Statistic & s) const {
    cout << "\tDFS::fillStatistic\n";
}

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) const {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));

    cout << "\tSimpleHeuristic::run\n";
    
    l.saveResult(ResultEvent());
}
