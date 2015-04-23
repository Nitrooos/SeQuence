#ifndef SEQUENCE_TASK
#define SEQUENCE_TASK

#include "Task.hpp"
#include "Data.hpp"

class SequenceTask : public Task {
    public:
        SequenceTask(Data *data);
        void run() const;
};

#endif
