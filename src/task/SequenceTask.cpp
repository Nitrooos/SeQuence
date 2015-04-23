#include "SequenceTask.hpp"

SequenceTask::SequenceTask(Data *data) : Task(data) { }

void SequenceTask::run() const {
    data->graph.get()->setSequencingAlgorithm(new SimpleHeuristic());
    data->graph.get()->runAlgorithm();
}
