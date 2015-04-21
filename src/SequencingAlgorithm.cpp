#include "SequencingAlgorithm.hpp"
#include "Graph.hpp"
#include "Logger.hpp"
#include "Options.hpp"

#include <iostream>

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) const {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));

    cout << "SuperHeurystyka...\nI już coś mam!\n";
    
    l.saveResult(ResultEvent());
}
