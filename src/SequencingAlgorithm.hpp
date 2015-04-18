#ifndef SEQUENCING_ALGORITHM
#define SEQUENCING_ALGORITHM

class Graph;

class SequencingAlgorithm {
    public:
        SequencingAlgorithm() {}
        virtual void run(Graph const& g) const = 0;
};

class SimpleHeuristic : public SequencingAlgorithm {
    public:
        SimpleHeuristic();
        void run(Graph const& g) const;
};

#endif
