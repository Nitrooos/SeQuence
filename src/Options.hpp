#ifndef OPTIONS
#define OPTIONS

class Options {
    Options();
    Options(Options const&)         = delete;
    void operator=(Options const&)  = delete;

    int minCommonPart,
        basePairsPerOligonucleotide,
        solutionsNumber,
        timeout;

    public:
        static Options& getInstance();

        void setMinCommonPart(int minCommonPart);
        void setBasePairsPerOligonucleotide(int bpPerOligo);
        void setSolutionsNumber(int solutionsNumber);
        void setTimeout(int timeout);

        int getMinCommonPart();
        int getBasePairsPerOligonucleotide();
        int getSolutionsNumber();
        int getTimeout();
        constexpr static int getBytesPerInt() { return sizeof(int); }
};

#endif
