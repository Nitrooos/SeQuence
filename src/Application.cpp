#include <iostream>

int main() {
    std::cout << "SeQuence\n";

    int vertex = 0xA63,
        candidate = 0x298;

    std::cout << ~(candidate ^ (vertex >> 2)) << "\n";

    return 0;
}
