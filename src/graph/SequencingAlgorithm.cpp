#include "SequencingAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Logger.hpp"
#include "../app/Options.hpp"

#include <iostream>

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) const {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));

    cout << "SuperHeurystyka...\nI już coś mam!\n";
    
    l.saveResult(ResultEvent());
}
