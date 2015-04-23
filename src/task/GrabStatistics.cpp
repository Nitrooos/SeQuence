#include "GrabStatistics.hpp"
#include "../graph/Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Event.hpp"

GrabStatistics::GrabStatistics(Data *data) : Task(data) { }

void GrabStatistics::run() const {
    Graph *graph = data->graph.get();
    
    Logger l;
    int successors = 0;
    for (auto &v : graph->getVertexes()) {
        successors += v.getSuccessors().size();
    }
    l.log(StatisticsGeneratedEvent(successors));
}
