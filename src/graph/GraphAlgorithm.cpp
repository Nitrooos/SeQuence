#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Logger.hpp"
#include "../helper/Converter.hpp"
#include "../app/Options.hpp"

#include <stack>
#include <algorithm>
#include <iostream>

        // DFS

DFS::DFS(const Vertex *beginningVertex) : beginningVertex(beginningVertex) { }

Vertex *DFS::getNonVisitedSuccessor(const Vertex *current) {
    for (auto succ : current->getSuccessors())
        if (vertexesInfo[succ.first].visited == false)
            return succ.first;
    return nullptr;
}

void DFS::run(Graph const& g) {    
    cout << "\tDFS::run\n";

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

void DFS::fillStatistic(Statistic & s) const {
    cout << "\tDFS::fillStatistic\n";
    
    int isolated = count_if(vertexesInfo.begin(), vertexesInfo.end(), [] (pair<const Vertex*, VertexInfo> const& p) {
        return !p.second.visited;
    });
    
    s.isolatedVertexes = isolated;
}

        // DetermineBeginningVertex
DetermineBeginningVertex::DetermineBeginningVertex() : bestBeginningVertex(nullptr) {}

void DetermineBeginningVertex::run(Graph const& g) {
    map<const Vertex*, int> penaltyPoints;
    for (auto &v : g.getVertexes())
        penaltyPoints.insert(make_pair(&v, 0));
    
    for (auto &v : g.getVertexes()) {
        for (auto &succ : v.getSuccessors()) {
            penaltyPoints[succ.first] += succ.second;
        }
    }
    
    bestBeginningVertex = min_element(penaltyPoints.begin(), penaltyPoints.end(),
        [] (pair<const Vertex*, int> const& i, pair<const Vertex*, int> const& j) {
            return i.second < j.second;
        })->first;

    Converter c;
    cout << "\tBeginning vertex: " << c.convert(bestBeginningVertex->getValue()) << "\n";
}

void DetermineBeginningVertex::fillStatistic(Statistic & s) const {
    s.potentialBeginVertex = bestBeginningVertex;
}

const Vertex *DetermineBeginningVertex::getBeginningVertex() const {
    return bestBeginningVertex;
}
        
        // SimpleHeuristic

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));

    cout << "\tSimpleHeuristic::run\n";
    
    l.saveResult(ResultEvent());
}
