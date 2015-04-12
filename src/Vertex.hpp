#ifndef VERTEX
#define VERTEX

#include <set>

using namespace std;

class Vertex {
    Vertex() = delete;

    int oligonucleotide;
    set<pair<Vertex*, int>> successors;

    public:
        Vertex(int oligo);
        void addSuccessor(Vertex *v, int commonPart);
        int getValue() const;
};

#endif
