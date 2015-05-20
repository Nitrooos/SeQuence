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
    list <const Vertex*> oligonucleotidesUsed;
    
    public:
        void addOligonucleotide(const Vertex *o);
        void recalculate();
        
        int getSequenceLength() const                        { return sequenceLength;       }
        int getNumberOfUsedOligonucleotides() const          { return nOligonucleotides;    }
        string getSequence() const                           { return sequence;             }
        list<const Vertex*> const& getUsedOligonucleotides() const { return oligonucleotidesUsed; }
};

#endif
