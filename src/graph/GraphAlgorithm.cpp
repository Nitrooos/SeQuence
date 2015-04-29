#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Converter.hpp"
#include "../app/Options.hpp"

#include <stack>
#include <algorithm>

        // DFS

DFS::DFS(const Vertex *beginningVertex) : beginningVertex(beginningVertex) { }

Vertex *DFS::getNonVisitedSuccessor(const Vertex *current) {
    for (auto succ : current->getSuccessors())
        if (vertexesInfo[succ.first].visited == false)
            return succ.first;
    return nullptr;
}

void DFS::run(Graph const& g) {    
    vertexesInfo.clear();
    for (auto &v : g.getVertexes())
        vertexesInfo.insert(make_pair(&v, VertexInfo()));
    
    stack<const Vertex*> vertexesStack;
    vertexesStack.push(beginningVertex);
    vertexesInfo[beginningVertex].visited = true;

    const Vertex *next, *current;
    while (!vertexesStack.empty()) {
        current = vertexesStack.top();
        next = getNonVisitedSuccessor(current);
        if (next != nullptr) {
            vertexesStack.push(next);
            vertexesInfo[next].visited = true;
        } else {
            next = vertexesStack.top();
            vertexesStack.pop();
        }
    }
}

int DFS::getVisitedVertexesNumber() const {
    return count_if(vertexesInfo.begin(), vertexesInfo.end(),
        [] (pair<const Vertex*, VertexInfo> const& p) {
            return p.second.visited;
        }
    );
}

        // DetermineBeginningVertex
DetermineBeginningVertexes::DetermineBeginningVertexes() {}

void DetermineBeginningVertexes::run(Graph const& g) {
    map<const Vertex*, int> penaltyPoints;
    for (auto &v : g.getVertexes())
        penaltyPoints.insert(make_pair(&v, 0));
    
    for (auto &v : g.getVertexes())
        for (auto &succ : v.getSuccessors()) {
            penaltyPoints[succ.first] += succ.second;
            penaltyPoints[&v] -= succ.second/2;
        }
    
    vector<pair<const Vertex*, int>> penaltyVector(penaltyPoints.begin(), penaltyPoints.end());
    sort(penaltyVector.begin(), penaltyVector.end(), [] (pair<const Vertex*, int> l, pair<const Vertex*, int> r) {
        return l.second < r.second;
    });
    
    for (int i = 0; i < 10; ++i)
        potentialBeginningVertexes.push_back(penaltyVector[i].first);
}

void DetermineBeginningVertexes::fillStatistic(Statistic & s) const {
    s.potentialBeginningVertexes = potentialBeginningVertexes;
}

list<const Vertex*> DetermineBeginningVertexes::getBeginningVertexes() const {
    return potentialBeginningVertexes;
}

        // SimpleHeuristic

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));
    l.saveResult(ResultEvent());
}
