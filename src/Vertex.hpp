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
    typedef multiset<pair<Vertex*, int>, SuccessorsCompare> SetOfSuccessors;

    Vertex() = delete;

    int oligonucleotide;
    SetOfSuccessors successors;

    public:
        Vertex(int oligo);
        void addSuccessor(Vertex *v, int commonPart);
        int getValue() const;
        SetOfSuccessors const& getSuccessors() const { return successors; }
};

#endif
