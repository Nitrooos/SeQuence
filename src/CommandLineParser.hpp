#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER

#include <map>
#include <string>

using namespace std;

class Parser {
    Parser()                 = delete;
    Parser(Parser const&)    = delete;
    Parser operator=(Parser const&) = delete;

    static void showHelpInfo(char *programName);

    public:
        static map<string, string> setProgramOptions(int argc, char *argv[]);
};

#endif
