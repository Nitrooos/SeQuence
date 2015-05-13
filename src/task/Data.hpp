#ifndef DATA
#define DATA

#include "../graph/Graph.hpp"
#include "../app/Instance.hpp"

#include <memory>

struct Data {
    unique_ptr<Graph> graph;
    unique_ptr<Instance> instance;
    long double computationTime{0.0};
};

#endif
