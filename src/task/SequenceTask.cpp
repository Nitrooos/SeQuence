#include "SequenceTask.hpp"

#include "../helper/Logger.hpp"
#include "../helper/Timer.hpp"
#include <unistd.h>
#include <iostream>

SequenceTask::SequenceTask(Data *data) : Task(data) {
    algorithm.reset(new SimpleHeuristic());
}

void SequenceTask::run() {
    Timer timer;
    
    data->graph.get()->setGraphAlgorithm(algorithm.get());

    timer.start();
    data->graph.get()->runAlgorithm();
    auto result = algorithm.get()->getResult();
    timer.stop();

    data->computationTime += timer.getTime();
    
    Logger l;
    l.saveResult(ResultEvent(*data->instance.get(), result, data->computationTime));
}
