#ifndef APPLICATION
#define APPLICATION

#include <list>

#include "task/Task.hpp"
#include "task/Data.hpp"

class Application {
    void loadTasks();
    
    int argc;
    char **argv;

    list<Task*> tasks;
    Data data;

    public:
        Application(int argc, char *argv[]);
        int run();
};

#endif
