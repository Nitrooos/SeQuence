#ifndef INSTANCE_LOADER
#define INSTANCE_LOADER

#include <vector>
#include <string>

using namespace std;

class Vertex;
class InstanceLoader {
    public:
        InstanceLoader();
        void run(string file, vector<Vertex> &vertexes) const;
};

#endif
