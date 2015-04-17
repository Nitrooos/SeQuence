#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER

class Parser {
    Parser()                 = delete;
    Parser(Parser const&)    = delete;
    Parser operator=(Parser const&) = delete;

    static void showHelpInfo(char *programName);

    public:
        static void setProgramOptions(int argc, char *argv[]);
};

#endif
