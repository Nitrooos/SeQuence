#include "CommandLineParser.hpp"
#include "../Exceptions.hpp"

#include <unistd.h>
#include <iostream>

map<string, string> Parser::setProgramOptions(int argc, char *argv[]) {
    char tmp;
    std::map<string, string> options;

    if (argc < 3)
        showHelpInfo(argv[0]);

    while ((tmp = getopt(argc, argv, "df:m:l:r:")) != -1) {
        switch (tmp) {
            case 'f': case 'm': case 'l': case 'r':
                options[string(&tmp)] = string(optarg);
                break;
            case 'd':
                options[string(&tmp)] = "";
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
         << "\t" << "-m   minimal common part of two oligonucleotides sufficient to connect them (default 7)\n"
         << "\t" << "-l   log file (default: log)\n"
         << "\t" << "-r   results file (default: results)\n"
         << "\t" << "-d   debug mode (only statistics about instance graph are collecting)\n\n"
         << "Example: " << programName << " -f data/instances/9.200-40 -m 8 -l mylog.txt\n";

    throw OnlyHelpInfo();
}
