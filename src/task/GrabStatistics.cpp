#include "GrabStatistics.hpp"
#include "../graph/Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Converter.hpp"
#include "../helper/Event.hpp"

#include <algorithm>

GrabStatistics::GrabStatistics(Data *data) : Task(data) { }

void GrabStatistics::run() {
    fillBasicStatistics();
    statistic.isolatedVertexes = countIsolatedVertexes();
    chooseBestBeginningVertex();
    
    Logger l;
    l.log(StatisticsGeneratedEvent(statistic));
}

int GrabStatistics::countIsolatedVertexes() const {
    map<const Vertex*, bool> isolated;
    for (auto &v : data->graph.get()->getVertexes())
        isolated[&v] = true;
    
    for (auto &v : isolated) {
        if (v.first->getSuccessors().size() > 0)
            v.second = false;
        
        for (auto &succ : v.first->getSuccessors())
            isolated[succ.first] = false;
    }
    
    return count_if(isolated.begin(), isolated.end(), [] (pair<const Vertex*, bool> const& p) {
        return p.second;
    });
}

void GrabStatistics::fillBasicStatistics() {
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
}

void GrabStatistics::chooseBestBeginningVertex() {
    ChooseBestBeginningVertex determine;
    determine.run(*data->graph.get());
    
    statistic.chosenBeginningVertex = determine.getBestBeginningVertex();
}
