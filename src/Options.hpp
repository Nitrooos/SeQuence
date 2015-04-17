#ifndef OPTIONS
#define OPTIONS

#include <string>

using namespace std;

class Options {
    Options();
    Options(Options const&)         = delete;
    void operator=(Options const&)  = delete;

    string instanceFilename;
    int minCommonPart,
        basePairsPerOligonucleotide,
        solutionsNumber,
        timeout;

    public:
        static Options& getInstance();

        void setInstanceFilename(string file);
        void setMinCommonPart(int minCommonPart);
        void setBasePairsPerOligonucleotide(int bpPerOligo);
        void setSolutionsNumber(int solutionsNumber);
        void setTimeout(int timeout);

        string getInstanceFilename();
        int getMinCommonPart();
        int getBasePairsPerOligonucleotide();
        int getSolutionsNumber();
        int getTimeout();
        constexpr static int getBytesPerInt() { return sizeof(int); }
};

#endif
