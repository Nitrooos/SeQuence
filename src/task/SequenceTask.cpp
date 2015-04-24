#include "SequenceTask.hpp"

#include <iostream>

SequenceTask::SequenceTask(Data *data) : Task(data) {
    algorithm.reset(new SimpleHeuristic());
}

void SequenceTask::run() const {
    std::cout << "SequenceTask::run\n";
    data->graph.get()->setGraphAlgorithm(algorithm.get());
    data->graph.get()->runAlgorithm();
}
