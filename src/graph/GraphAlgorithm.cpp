#include "GraphAlgorithm.hpp"
#include "Graph.hpp"
#include "../helper/Converter.hpp"
#include "../app/Options.hpp"

#include <iostream>
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
            penaltyPoints[succ.first] += succ.second*succ.second;
            penaltyPoints[&v] -= 5*succ.second;
        }
    
    vector<pair<const Vertex*, int>> penaltyVector(penaltyPoints.begin(), penaltyPoints.end());
    sort(penaltyVector.begin(), penaltyVector.end(), [] (pair<const Vertex*, int> l, pair<const Vertex*, int> r) {
        return l.second < r.second;
    });
    
    for (int i = 0; i < 10; ++i)
        potentialBeginningVertexes.push_back(penaltyVector[i].first);
}

list<const Vertex*> DetermineBeginningVertexes::getBeginningVertexes() const {
    return potentialBeginningVertexes;
}

        // ChooseBestBeginningVertex

ChooseBestBeginningVertex::ChooseBestBeginningVertex() { }

void ChooseBestBeginningVertex::run(Graph const &g) {
    DetermineBeginningVertexes determine;
    determine.run(g);
    list<const Vertex *> potentialBeginningVertexes = determine.getBeginningVertexes();
    
    pair<const Vertex*, int> bestVisited;
    Converter c;
    
    for (auto &v : potentialBeginningVertexes) {
        DFS dfs(v);
        dfs.run(g);
        int nVisited = dfs.getVisitedVertexesNumber();
        if (nVisited > bestVisited.second) {
            bestVisited.first  = v;
            bestVisited.second = nVisited;
        }
    }
    
    bestBeginningVertex = bestVisited;
}

pair<const Vertex*, int> ChooseBestBeginningVertex::getBestBeginningVertex() const {
    return bestBeginningVertex;
}

        // SimpleHeuristic

SimpleHeuristic::SimpleHeuristic(int maxLength) : maxLength(maxLength) { }

pair<const Vertex*, int> SimpleHeuristic::chooseNextVertex(const Vertex *current, int minCommonPart) {
    pair<const Vertex*, int> alternative_vertex = make_pair(nullptr, 0);
    for (auto succ : current->getSuccessors()) {
        if (succ.second >= minCommonPart) {
            if (vertexesInfo[succ.first].visited) {
                if (alternative_vertex.first == nullptr)
                    alternative_vertex = succ;
            } else {
                return succ;
            }
        }
    }
    return alternative_vertex;
}

void SimpleHeuristic::run(Graph const& g) {
    stack<const Vertex*> v_stack;
    Result current_result;
    
    ChooseBestBeginningVertex algorithm;
    algorithm.run(g);
    const Vertex *begin = algorithm.getBestBeginningVertex().first;
    
    v_stack.push(begin);
    current_result.addOligonucleotide(make_pair(begin, 0), false);
    vertexesInfo[begin].visited = true;

    const int BASE_PAIRS_PER_OLIGONUCLEOTIDE = Options::getInstance().getBasePairsPerOligonucleotide();
    int current_length = BASE_PAIRS_PER_OLIGONUCLEOTIDE;
    while (current_length < maxLength) {
        int min_common_part = BASE_PAIRS_PER_OLIGONUCLEOTIDE - (maxLength - current_length);
        auto next_vertex = chooseNextVertex(v_stack.top(), min_common_part);
        if (next_vertex.first != nullptr) {
            v_stack.push(next_vertex.first);
            current_result.addOligonucleotide(next_vertex, vertexesInfo[next_vertex.first].visited);
            vertexesInfo[next_vertex.first].visited = true;
            current_length += BASE_PAIRS_PER_OLIGONUCLEOTIDE - next_vertex.second;
        } else
            break;
    }
    
    current_result.recalculate();
    results.push_back(current_result);
}
