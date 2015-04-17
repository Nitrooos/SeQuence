#include <iostream>

#include "CommandLineParser.hpp"

int main(int argc, char *argv[]) {
    Parser::setProgramOptions(argc, argv);

    return 0;
}
