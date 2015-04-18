#ifndef VERTEX
#define VERTEX

#include <set>

using namespace std;

class Vertex {
    struct SuccessorsCompare {
        bool operator() (const pair<Vertex*, int>& lhs, const pair<Vertex*, int>& rhs) const {
            return lhs.second > rhs.second;
        }
    };

    Vertex() = delete;

    int oligonucleotide;
    multiset<pair<Vertex*, int>, SuccessorsCompare> successors;

    public:
        Vertex(int oligo);
        void addSuccessor(Vertex *v, int commonPart);
        int getValue() const;
        void printSuccessors() const;
};

#endif
