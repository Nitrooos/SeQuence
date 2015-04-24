#ifndef SEQUENCING_ALGORITHM
#define SEQUENCING_ALGORITHM

#include "../task/Statistic.hpp"

class Graph;

class GraphAlgorithm {
    public:
        GraphAlgorithm() {}
        virtual void run(Graph const& g) const = 0;
};

class SequencingAlgorithm : public GraphAlgorithm { };

class StatisticAlgorithm : public GraphAlgorithm {
    public:
        virtual void fillStatistic(Statistic & s) const = 0;
};

class DFS : public StatisticAlgorithm {
    public:
        DFS();
        void run(Graph const& g) const;
        void fillStatistic(Statistic & s) const;
};

class SimpleHeuristic : public SequencingAlgorithm {
    public:
        SimpleHeuristic();
        void run(Graph const& g) const;
};

#endif
