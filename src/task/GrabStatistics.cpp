#include "GrabStatistics.hpp"

#include <iostream>

GrabStatistics::GrabStatistics(Data *data) : Task(data) { }

void GrabStatistics::run() const {
    std::cout << "I'm grabbing statistics about graph!\n";
}
