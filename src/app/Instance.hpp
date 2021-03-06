#ifndef INSTANCE
#define INSTANCE

#include <string>
#include <vector>

using namespace std;

class Instance {
    vector<string> split(string const& s, char delim);

    string name;
    int positiveErrors, negativeErrors, n, idealSpectrum,
        idealUsedOligonucleotides;

    public:
        Instance(string filename);

        string getName() const { return name; }
        int getPositiveErrors() const { return positiveErrors; }
        int getNegativeErrors() const { return negativeErrors; }
        int getOriginalSequenceLength() const { return n; }
        int getIdealSpectrum() const { return idealSpectrum; }
        int getIdealNumberOfUsedOligonucleotides() const { return idealUsedOligonucleotides; }
};

#endif
