#ifndef OPTIONS
#define OPTIONS

class Options {
    Options();
    Options(Options const&)         = delete;
    void operator=(Options const&)  = delete;

    int minCommonPart,
        basePairsPerOligonucleotide;

    public:
        static Options& getInstance();

        void setMinCommonPart(int minCommonPart);
        void setBasePairsPerOligonucleotide(int bpPerOligo);
        int getMinCommonPart();
        int getBasePairsPerOligonucleotide();
        constexpr static int getBytesPerInt() { return sizeof(int); }
};

#endif
