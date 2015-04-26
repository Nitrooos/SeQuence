#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Logger.hpp"
#include "../app/Options.hpp"

#include <stack>
#include <algorithm>
#include <iostream>

DFS::DFS() { }

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
    vertexesStack.push(&g.getVertexes().front());
    vertexesInfo[&g.getVertexes().front()].visited = true;

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
    
    int isolated = count_if(vertexesInfo.begin(), vertexesInfo.end(), [] (pair<const Vertex*, VertexInfo> p) {
        return !p.second.visited;
    });
    
    s.isolatedVertexes = isolated;
}

SimpleHeuristic::SimpleHeuristic() { }

void SimpleHeuristic::run(Graph const& g) {
    Logger l;
    l.log(InstanceLoadedEvent(Options::getInstance().getInstanceFilename()));

    cout << "\tSimpleHeuristic::run\n";
    
    l.saveResult(ResultEvent());
}
