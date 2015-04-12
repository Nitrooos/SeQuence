#ifndef OPTIONS
#define OPTIONS

class Options {
    public:
        static int getMinCommonPart();
        static int getBasePairsPerOligonucleotide();
        constexpr static int getBytesPerInt() { return sizeof(int); }
};

#endif
