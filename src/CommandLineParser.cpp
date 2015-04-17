#include "CommandLineParser.hpp"
#include "Options.hpp"

#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

void Parser::setProgramOptions(int argc, char *argv[]) {
    char tmp;

    while ((tmp = getopt(argc, argv, "hs:m:t:")) != -1) {
        switch (tmp) {
            case 'h':
                showHelpInfo(argv[0]);
                break;
            case 's':
                Options::getInstance().setSolutionsNumber(stoi(optarg));
                break;
            case 'm':
                Options::getInstance().setMinCommonPart(stoi(optarg));
                break;
            case 't':
                Options::getInstance().setTimeout(stoi(optarg));
                break;
            default:
                showHelpInfo(argv[0]);
                break;
        }
    }
}

void Parser::showHelpInfo(char *programName) {
    cout << "Usage:   " << programName << " [-option] [argument]\n"
         << "Options:\n\t"
         << "-h   show help information\n"
         << "\t" << "-s   number of solutions to find (default 1)\n"
         << "\t" << "-m   minimal common part of two oligonucleotides sufficient to connect them (default 7)\n"
         << "\t" << "-t   maximal time of computations in seconds, after which program stops (default no limit)\n\n"
         << "Example: " << programName << " -s 10 -m 8 -t 100\n";
}
