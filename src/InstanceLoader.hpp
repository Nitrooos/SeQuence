#ifndef INSTANCE_LOADER
#define INSTANCE_LOADER

#include <list>
#include <string>

using namespace std;

class Vertex;
class InstanceLoader {
    void addSuccessorsToVertexes(list<Vertex> &vertexes) const;

    public:
        InstanceLoader();
        void run(string file, list<Vertex> &vertexes) const;
};

#endif
