#include <iostream>
#include "InstanceLoader.hpp"
#include "Converter.hpp"
#include "Vertex.hpp"

#include <vector>

int main() {
    InstanceLoader loader;
    Converter c;
    vector<Vertex> v;
    loader.run("data/instances/9.200-40", v);

    for (auto &e : v) {
        std::cout << c.convert(e.getValue()) << "\n";
    }

    return 0;
}
