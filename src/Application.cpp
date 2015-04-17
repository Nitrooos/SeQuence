#include <iostream>

#include "CommandLineParser.hpp"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i)
        std::cout << argv[i] << "\n";

    Parser::setProgramOptions(argc, argv);

    return 0;
}
