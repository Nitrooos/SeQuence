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

    int oligonucleotide;
    SetOfSuccessors successors;

    public:
        Vertex();
        Vertex(int oligo);
        void addSuccessor(Vertex *v, int commonPart);
        int getValue() const;
        SetOfSuccessors const& getSuccessors() const { return successors; }
};

    class VertexDecorator : public Vertex {
        protected:
            Vertex &decoratedVertex;
        public:
            VertexDecorator(Vertex &v);
    };

        class VisitedVertex : public VertexDecorator {
            private:
                bool visited;
            public:
                VisitedVertex(Vertex &v);
                void visit();
                bool getVisited() const;
        };

#endif
