#ifndef DATA
#define DATA

#include "../Graph.hpp"
#include "../Instance.hpp"

#include <memory>

struct Data {
    unique_ptr<Graph> graph;
    unique_ptr<Instance> instance;
};

#endif
