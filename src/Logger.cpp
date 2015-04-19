#include "Logger.hpp"
#include "Event.hpp"
#include "Options.hpp"

Logger::Logger() {
    logFile.open(Options::getInstance().getLogFilename(), ios_base::app);
    resultsFile.open(Options::getInstance().getResultsFilename(), ios_base::app);
}

void Logger::log(Event const& e) {
    logFile << e.getMessage() << "\n";
}

void Logger::saveResult(ResultEvent const& e) {
    resultsFile << e.getMessage() << "\n";
}
