#ifndef RESULT
#define RESULT

#include <string>
#include <list>

#include "../graph/Vertex.hpp"

using namespace std;

class Result {
    int sequenceLength{0},
        nOligonucleotides{0};
    string sequence;
    list<pair<const Vertex*, int>> oligonucleotidesUsed;
    
    public:
        void addOligonucleotide(pair<const Vertex*, int> const& o, bool visited);
        void recalculate();
        
        int getSequenceLength() const                        { return sequenceLength;       }
        int getNumberOfUsedOligonucleotides() const          { return nOligonucleotides;    }
        string getSequence() const                           { return sequence;             }
        list<pair<const Vertex*, int>> const& getUsedOligonucleotides() const { return oligonucleotidesUsed; }
};

#endif
