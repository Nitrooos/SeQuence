#ifndef GRAB_STATISTICS
#define GRAB_STATISTICS

#include "../graph/GraphAlgorithm.hpp"
#include "Task.hpp"
#include "Data.hpp"

class GrabStatistics : public Task {
    StatisticAlgorithm *algorithm;
    
    public:
        GrabStatistics(Data *data);
        void run() const;
};

#endif
