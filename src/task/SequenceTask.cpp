#include "SequenceTask.hpp"

#include <iostream>

SequenceTask::SequenceTask(Data *data) : Task(data), algorithm(new SimpleHeuristic()) { }

void SequenceTask::run() const {
    std::cout << "SequenceTask::run\n";
    data->graph.get()->setGraphAlgorithm(this->algorithm);
    data->graph.get()->runAlgorithm();
}
