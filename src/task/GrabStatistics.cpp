#include "GrabStatistics.hpp"
#include "../graph/Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Event.hpp"

GrabStatistics::GrabStatistics(Data *data) : Task(data) { }

void GrabStatistics::run() const {
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
    
    Logger l;
    l.log(StatisticsGeneratedEvent(s));
}
