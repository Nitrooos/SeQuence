#include <iostream>

#include "Vertex.hpp"
#include "Converter.hpp"

int main(int argc, char *argv[]) {
    std::cout << "SeQuence\n";

    Converter c;
    Vertex v(c.convert("GCTTCAGACA")),
           v1(c.convert("CTAGGTACGA"));
    v.addSuccessor(&v1, 9);
    v.addSuccessor(nullptr, 9);
    v.addSuccessor(nullptr, 8);
    v.addSuccessor(&v1, 6);
    v.addSuccessor(nullptr, 5);
    v.addSuccessor(nullptr, 7);

    v.printSuccessors();

    return 0;
}
