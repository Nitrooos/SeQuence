#include "Application.hpp"
#include "Options.hpp"

#include <string>
#include <iostream>

Application::Application(int argc, char *argv[]) : argc(argc), argv(argv) {
    Options::getInstance().load(argc, argv);
    string instanceFilename = Options::getInstance().getInstanceFilename();

    graph.reset(new Graph(instanceFilename));
    instance.reset(new Instance(instanceFilename));
}

int Application::run() {
    std::cout << "SeQuence\n";
}

int main(int argc, char *argv[]) {
    Application app(argc, argv);
    app.run();

    return 0;
}
