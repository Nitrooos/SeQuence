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

class DFS : GraphAlgorithm {
    struct VertexInfo {
        bool visited{false};
    };
    
    Vertex *getNonVisitedSuccessor(const Vertex *current);
    void logResult() const;
    
    map<const Vertex*, VertexInfo> vertexesInfo;
    const Vertex *beginningVertex;
    
    public:
        DFS(const Vertex *beginningVertex);
        void run(Graph const& g);
};

class DetermineBeginningVertexes : public StatisticAlgorithm {
    list<const Vertex*> potentialBeginningVertexes;
    
    public:
        DetermineBeginningVertexes();
        void run(Graph const& g);
        void fillStatistic(Statistic & s) const;
        list<const Vertex*> getBeginningVertexes() const;
};

class SimpleHeuristic : public SequencingAlgorithm {
    public:
        SimpleHeuristic();
        void run(Graph const& g);
};

#endif
