#include "Options.hpp"
#include "CommandLineParser.hpp"
#include "Exceptions.hpp"

Options::Options()
    : minCommonPart(7), basePairsPerOligonucleotide(10), solutionsNumber(1), timeout(-1),
      logFilename("output/log"), resultsFilename("output/results"), debugMode(false) {}

Options& Options::getInstance() {
    static Options instance;

    return instance;
}

void Options::load(int argc, char *argv[]) {
    map<string, string> options = Parser::setProgramOptions(argc, argv);

    this->instanceFilename = options["f"];
    if (options.find("l") != options.end())
        this->logFilename = options["l"];
    if (options.find("r") != options.end())
        this->resultsFilename = options["r"];

    if (options.find("s") != options.end())
        this->solutionsNumber = stoul(options["s"]);
    if (options.find("m") != options.end())
        this->minCommonPart = stoul(options["m"]);
    if (options.find("t") != options.end())
        this->timeout = stoul(options["t"]);
    
    if (options.find("d") != options.end())
        this->debugMode = true;
}

void Options::setBasePairsPerOligonucleotide(int bpPerOligo) {
    this->basePairsPerOligonucleotide = bpPerOligo;
}

string Options::getInstanceFilename() {
    return instanceFilename;
}

string Options::getLogFilename() {
    return logFilename;
}

string Options::getResultsFilename() {
    return resultsFilename;
}

int Options::getMinCommonPart() {
    return minCommonPart;
}

int Options::getBasePairsPerOligonucleotide() {
    return basePairsPerOligonucleotide;
}

int Options::getSolutionsNumber() {
    return solutionsNumber;
}

int Options::getTimeout() {
    return timeout;
}

bool Options::getDebugMode() {
    return debugMode;
}
