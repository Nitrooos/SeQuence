#include "GrabStatistics.hpp"
#include "../graph/Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Event.hpp"

#include <iostream>

GrabStatistics::GrabStatistics(Data *data) : Task(data) {
    DetermineBeginningVertex *alg = new DetermineBeginningVertex();
    data->graph.get()->setGraphAlgorithm(alg);
    data->graph.get()->runAlgorithm();
    alg->fillStatistic(statistic);
    
    algorithm.reset(new DFS(alg->getBeginningVertex()));
}

void GrabStatistics::run() {
    std::cout << "GrabStatistics::run\n";
    Graph *graph = data->graph.get();
    
    statistic.vertexes = graph->getVertexes().size();

    statistic.arches = 0;
    for (auto &v : graph->getVertexes()) {
        statistic.arches += v.getSuccessors().size();
        for (auto &succ : v.getSuccessors()) {
            ++statistic.successorsByType[succ.second];
        }
    }
    
    statistic.avgSuccessors = statistic.arches/(double)statistic.vertexes;
    statistic.density = statistic.arches/(statistic.vertexes*(statistic.vertexes - 1)/2.0);
    
    graph->setGraphAlgorithm(algorithm.get());
    graph->runAlgorithm();
    algorithm.get()->fillStatistic(statistic);

    Logger l;
    l.log(StatisticsGeneratedEvent(statistic));
}
