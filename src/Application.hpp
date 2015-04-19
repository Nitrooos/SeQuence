#ifndef APPLICATION
#define APPLICATION

#include <memory>

#include "Graph.hpp"
#include "Instance.hpp"
#include "Logger.hpp"

class Application {
    unique_ptr<Graph> graph;
    unique_ptr<Instance> instance;
    Logger logger;

    int argc;
    char **argv;

    public:
        Application(int argc, char *argv[]);
        int run();
};

#endif
