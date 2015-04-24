#ifndef SEQUENCE_TASK
#define SEQUENCE_TASK

#include "../graph/GraphAlgorithm.hpp"
#include "Task.hpp"
#include "Data.hpp"

#include <memory>

class SequenceTask : public Task {
    unique_ptr<SequencingAlgorithm> algorithm;
    
    public:
        SequenceTask(Data *data);
        void run() const;
};

#endif
