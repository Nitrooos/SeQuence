#include "CommandLineParser.hpp"
#include "Exceptions.hpp"

#include <unistd.h>
#include <iostream>

map<string, string> Parser::setProgramOptions(int argc, char *argv[]) {
    char tmp;
    map<string, string> options;

    while ((tmp = getopt(argc, argv, "hf:s:m:t:l:r:")) != -1) {
        switch (tmp) {
            case 'h':
                showHelpInfo(argv[0]);
                break;
            case 'f': case 's': case 'm': case 't': case 'l': case 'r':
                options[string(&tmp)] = optarg;
                break;
            default:
                showHelpInfo(argv[0]);
                break;
        }
    }
    return options;
}

void Parser::showHelpInfo(char *programName) {
    cout << "Usage:   " << programName << " [-option] [argument]\n"
         << "Options:\n\t"
         << "-h   show help information\n"
         << "\t" << "-f   instance file\n"
         << "\t" << "-s   number of solutions to find (default 1)\n"
         << "\t" << "-m   minimal common part of two oligonucleotides sufficient to connect them (default 7)\n"
         << "\t" << "-t   maximal time of computations in seconds, after which program stops (default no limit)\n"
         << "\t" << "-l   log file (default: log)\n"
         << "\t" << "-r   results file (default: results)\n\n"
         << "Example: " << programName << " -f data/instances/9.200-40 -s 10 -m 8 -t 100 -l mylog.txt\n";
    
    throw OnlyHelpInfo();
}
