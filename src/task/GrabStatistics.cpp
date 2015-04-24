#include "GrabStatistics.hpp"
#include "../graph/Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Event.hpp"

#include <iostream>

GrabStatistics::GrabStatistics(Data *data) : Task(data), algorithm(new DFS()) { }

void GrabStatistics::run() const {
    std::cout << "GrabStatistics::run\n";
    Graph *graph = data->graph.get();
    
    Statistic s;
    s.vertexes = graph->getVertexes().size();
    
    for (auto &v : graph->getVertexes()) {
        s.arches += v.getSuccessors().size();
        for (auto &succ : v.getSuccessors()) {
            ++s.successorsByType[succ.second];
        }
    }
    
    s.avgSuccessors = s.arches/(double)s.vertexes;
    s.density = s.vertexes/(s.vertexes*(s.vertexes - 1)/2.0);
    
    graph->setGraphAlgorithm(this->algorithm);
    graph->runAlgorithm();
    this->algorithm->fillStatistic(s);
    
    Logger l;
    l.log(StatisticsGeneratedEvent(s));
}
