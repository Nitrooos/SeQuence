#include "Task.hpp"

#include "../helper/Timer.hpp"

Task::Task(Data *data) : data(data) {
    Timer t;
    t.start();
    // budowa grafu
    data->graph.get()->load(data->instance.get()->getName());
    // zakończ odliczanie czasu
    t.stop();
    
    data->computationTime += t.getTime();
}
