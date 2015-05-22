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
    protected:
        list<Result> results;
    
    public:
        virtual list<Result> const& getResults() const { return results; }
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
    struct VertexInfo {
        bool visited{false};
    };
    
    pair<const Vertex*, int> chooseNextVertex(const Vertex *current,
        map<const Vertex*, VertexInfo> & vertexesInfo, int minCommonPart);
    void startFromNextVertex(const Vertex *v);
    
    int maxLength;
    
    public:
        SimpleHeuristic(int maxLength);
        void run(Graph const& g);
};

#endif
