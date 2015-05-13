#ifndef SEQUENCING_ALGORITHM
#define SEQUENCING_ALGORITHM

#include "../task/Statistic.hpp"
#include "../task/Result.hpp"

class Graph;

class GraphAlgorithm {
    public:
        GraphAlgorithm() {}
        virtual void run(Graph const& g) = 0;
};

class SequencingAlgorithm : public GraphAlgorithm {
    Result result;
    
    public:
        virtual Result const& getResult() const { return result; }
};

class StatisticAlgorithm : public GraphAlgorithm {
    public:
        virtual void fillStatistic(Statistic & s) const = 0;
};

class DFS : GraphAlgorithm {
    struct VertexInfo {
        bool visited{false};
    };
    
    Vertex *getNonVisitedSuccessor(const Vertex *current);
    
    map<const Vertex*, VertexInfo> vertexesInfo;
    const Vertex *beginningVertex;
    
    public:
        DFS(const Vertex *beginningVertex);
        void run(Graph const& g);
        int getVisitedVertexesNumber() const;
};

class DetermineBeginningVertexes : public GraphAlgorithm {
    list<const Vertex*> potentialBeginningVertexes;
    
    public:
        DetermineBeginningVertexes();
        void run(Graph const& g);
        list<const Vertex*> getBeginningVertexes() const;
};

class ChooseBestBeginningVertex : public GraphAlgorithm {
    pair<const Vertex*, int> bestBeginningVertex;
    
    public:
        ChooseBestBeginningVertex();
        void run(Graph const& g);
        pair<const Vertex*, int> getBestBeginningVertex() const;
};

class SimpleHeuristic : public SequencingAlgorithm {
    public:
        SimpleHeuristic();
        void run(Graph const& g);
};

#endif
