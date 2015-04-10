#include <iostream>
#include "Converter.hpp"

int main() {
    Converter c;
    std::cout << c.convert(0xE4, 4) << "\n";

    return 0;
}
