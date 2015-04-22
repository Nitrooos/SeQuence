#include "SequenceTask.hpp"

#include <iostream>

SequenceTask::SequenceTask(Data *data) : Task(data) { }

void SequenceTask::run() const {
    std::cout << "I'm sequencing the graph\n";
}
