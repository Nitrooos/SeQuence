#ifndef GRAB_STATISTICS
#define GRAB_STATISTICS

#include "../graph/GraphAlgorithm.hpp"
#include "Task.hpp"
#include "Data.hpp"

#include <memory>

class GrabStatistics : public Task {
    void fillBasicStatistics();
    int countIsolatedVertexes() const;
    void chooseBestBeginningVertex();
    
    Statistic statistic;
    
    public:
        GrabStatistics(Data *data);
        void run();
};

#endif
