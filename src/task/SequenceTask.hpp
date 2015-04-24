#ifndef SEQUENCE_TASK
#define SEQUENCE_TASK

#include "../graph/GraphAlgorithm.hpp"
#include "Task.hpp"
#include "Data.hpp"

class SequenceTask : public Task {
    SequencingAlgorithm *algorithm;
    
    public:
        SequenceTask(Data *data);
        void run() const;
};

#endif
