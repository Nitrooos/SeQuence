#ifndef SEQUENCING_ALGORITHM
#define SEQUENCING_ALGORITHM

#include "../task/Statistic.hpp"

class Graph;

class GraphAlgorithm {
    public:
        GraphAlgorithm() {}
        virtual void run(Graph const& g) = 0;
};

class SequencingAlgorithm : public GraphAlgorithm { };

class StatisticAlgorithm : public GraphAlgorithm {
    public:
        virtual void fillStatistic(Statistic & s) const = 0;
};

class DFS : public StatisticAlgorithm {
    struct VertexInfo {
        bool visited{false};
    };
    
    Vertex *getNonVisitedSuccessor(const Vertex *current);
    
    map<const Vertex*, VertexInfo> vertexesInfo;
    const Vertex *beginningVertex;
    
    public:
        DFS(const Vertex *beginningVertex);
        void run(Graph const& g);
        void fillStatistic(Statistic & s) const;
};

class DetermineBeginningVertex : public StatisticAlgorithm {
    const Vertex *bestBeginningVertex;
    
    public:
        DetermineBeginningVertex();
        void run(Graph const& g);
        void fillStatistic(Statistic & s) const;
        const Vertex *getBeginningVertex() const;
};

class SimpleHeuristic : public SequencingAlgorithm {
    public:
        SimpleHeuristic();
        void run(Graph const& g);
};

#endif
