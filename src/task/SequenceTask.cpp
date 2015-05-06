#include "SequenceTask.hpp"

#include "../helper/Logger.hpp"

SequenceTask::SequenceTask(Data *data) : Task(data) {
    algorithm.reset(new SimpleHeuristic());
}

void SequenceTask::run() {
    data->graph.get()->setGraphAlgorithm(algorithm.get());
    data->graph.get()->runAlgorithm();
    auto result = algorithm.get()->getResult();
    
    Logger l;
    l.saveResult(ResultEvent(*data->instance.get(), result));
}
