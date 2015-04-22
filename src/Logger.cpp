#include "Logger.hpp"
#include "Event.hpp"
#include "Options.hpp"

Logger::Logger() {
    logFile.open(Options::getInstance().getLogFilename(), ios_base::app);
    
    bool resultsFileExisted = fileExists(Options::getInstance().getResultsFilename());
    resultsFile.open(Options::getInstance().getResultsFilename(), ios_base::app);
    
    if (!resultsFileExisted) {
        writeBasicInfoOnBegin();
    }
}

void Logger::log(Event const& e) {
    logFile << e.getMessage() << "\n";
}

void Logger::saveResult(ResultEvent const& e) {
    resultsFile << e.getMessage() << "\n";
}

void Logger::writeBasicInfoOnBegin() {
    resultsFile << "# SeQuence 2015 by Nitrooos, Poznan 2015\n"
                << "# Find more on Github: http://github.com/Nitrooos\n"
                << "#\n"
                << "# Every result is described as below:\n"
                << "#     instance name\n"
                << "#     list of potential starting oligonucleotides\n"
                << "#     used starting oligonucleotide\n"
                << "#     number of used oligonucleotides from spectrum\n"
                << "#     ideal number of used oligonucleotides\n"
                << "#     length of computed sequence\n"
                << "#     length of original sequence\n"
                << "#     time of computations in seconds\n"
                << "#     computed sequence (all letters)\n"
                << "#     list of used oligonucleotides\n\n";
}

bool Logger::fileExists(string filename) const {
    ifstream ifile(filename);
    return ifile;
}
