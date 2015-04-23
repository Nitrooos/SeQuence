#ifndef GRAB_STATISTICS
#define GRAB_STATISTICS

#include "Task.hpp"
#include "Data.hpp"

class GrabStatistics : public Task {
    public:
        GrabStatistics(Data *data);
        void run() const;
};

#endif
