#ifndef LOGGER
#define LOGGER

#include <fstream>

#include "Event.hpp"

using namespace std;

class Logger {
    ofstream logFile, resultsFile;

    public:
        Logger();

        void log(Event const& e);
        void saveResult(ResultEvent const& e);
};

#endif
