#include "Application.hpp"
#include "Options.hpp"
#include "../Exceptions.hpp"
#include "../task/SequenceTask.hpp"
#include "../task/GrabStatistics.hpp"
#include "../helper/Logger.hpp"

#include <string>
#include <iostream>

using namespace std;

Application::Application(int argc, char *argv[]) : argc(argc), argv(argv) {
    Options::getInstance().load(argc, argv);

    string instanceFilename = Options::getInstance().getInstanceFilename();
    data.graph.reset(new Graph());
    data.instance.reset(new Instance(instanceFilename));
    
    Logger l;
    l.log(InstanceLoadedEvent(data.instance.get()->getName()));
    
    this->loadTasks();
}

void Application::loadTasks() {
    if (Options::getInstance().getDebugMode())
        tasks.push_back(new GrabStatistics(&data));
    else
        tasks.push_back(new SequenceTask(&data));
}

int Application::run() {
    for (auto &task : tasks)
        task->run();
    
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
    } catch(OnlyHelpInfo const& e) {
        
    } catch (...) {
        cerr << "Exception of unknown type!\n";                   // Kernel Panic
    }
    return -1;
}
