#ifndef APPLICATION
#define APPLICATION

#include <memory>

#include "Graph.hpp"
#include "Instance.hpp"

class Application {
    unique_ptr<Graph> graph;
    unique_ptr<Instance> instance;

    int argc;
    char **argv;

    public:
        Application(int argc, char *argv[]);
        int run();
};

#endif
