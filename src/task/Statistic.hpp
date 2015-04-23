#ifndef STATISTIC
#define STATISTIC

#include "../graph/Vertex.hpp"

#include <map>
#include <list>

using namespace std;

struct Statistic {
    int vertexes, arches, isolatedVertexes;
    double density, avgSuccessors;
    map<int, int> successorsByType;
    list<Vertex*> potentialBeginVertexes;
};

#endif
