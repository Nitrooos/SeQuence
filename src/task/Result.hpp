#ifndef RESULT
#define RESULT

struct Result {
    int sequenceLength{0},
        nOligonucleotides{0};
    double computationTime{0.0};
    string sequence;
    list <const Vertex*> oligonucleotidesUsed;
};

#endif
