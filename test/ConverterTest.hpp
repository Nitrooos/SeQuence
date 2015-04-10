#include "../src/Converter.hpp"

#include <time.h>
#include <stdlib.h>

class ConverterTest : public CppUnit::TestCase {
    char getRandomNucleotide() const {
        switch (rand()%4) {
            case 0: return 'A';
            case 1: return 'C';
            case 2: return 'T';
            case 3: return 'G';
        }
    }

    string generateRandomSequence(int length) const {
        string result = "";
        for (int i = 0; i < length; ++i)
            result += getRandomNucleotide();
        return result;
    }

    public:
        void runTest() {
            // Converter c;
            //
            // srand((unsigned)time(NULL));
            // int randomLength;
            // string randomSequence, processedSequence;
            // for (int i = 0; i < 100; ++i) {
            //     randomLength      = rand()%15 + 1;
            //     randomSequence    = generateRandomSequence(randomLength);
            //     processedSequence = c.convert(c.convert(randomSequence), randomLength);
            //
            //     CPPUNIT_ASSERT_MESSAGE("Converter changed sequence during conversion!",
            //         randomSequence == processedSequence);
            // }
        }
};
