#ifndef GRAB_STATISTICS
#define GRAB_STATISTICS

#include "Task.hpp"

class GrabStatistics : public Task {
    public:
        GrabStatistics(Data *data);
        void run() const;
};

#endif
