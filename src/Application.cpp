#include "Application.hpp"
#include "Options.hpp"
#include "Exceptions.hpp"
#include "SequencingAlgorithm.hpp"

#include <string>
#include <iostream>

using namespace std;

Application::Application(int argc, char *argv[]) : argc(argc), argv(argv) {
    Options::getInstance().load(argc, argv);
    string instanceFilename = Options::getInstance().getInstanceFilename();

    graph.reset(new Graph(instanceFilename));
    instance.reset(new Instance(instanceFilename));
}

int Application::run() {
    graph.get()->setSequencingAlgorithm(new SimpleHeuristic());
    graph.get()->runAlgorithm();
    return 0;
}

int main(int argc, char *argv[]) {
    try {
        Application app(argc, argv);
        return app.run();
    } catch (NoEnoughSpaceInInt const& e) {
        cerr << e.what() << "\n";
    } catch (CannotOpenInstanceFileError const& e) {
        cerr << e.what() << "\n";
    } catch (...) {
        cerr << "Exception of unknown type!\n";                   // Kernel Panic
    }
    return -1;
}
