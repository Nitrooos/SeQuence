#ifndef OPTIONS
#define OPTIONS

#include <string>
#include <map>

using namespace std;

class Options {
    Options();
    Options(Options const&)         = delete;
    void operator=(Options const&)  = delete;

    string instanceFilename,
           logFilename,
           resultsFilename;
    int minCommonPart,
        basePairsPerOligonucleotide;
    bool debugMode;

    public:
        static Options& getInstance();

        void load(int argc, char *argv[]);

        void setBasePairsPerOligonucleotide(int bpPerOligo);

        string getInstanceFilename();
        string getLogFilename();
        string getResultsFilename();
        int getMinCommonPart();
        int getBasePairsPerOligonucleotide();
        bool getDebugMode();
        constexpr static int getBytesPerInt() { return sizeof(int); }
};

#endif
