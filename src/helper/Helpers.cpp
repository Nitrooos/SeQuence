#include "Helpers.hpp"
#include "../graph/Vertex.hpp"
#include "../app/Options.hpp"

int CommonPart::get(Vertex const& vertex, Vertex const& candidate) {
    Options &o = Options::getInstance();
    int bytesPerInt       = o.getBytesPerInt(),
        basePairsPerOligo = o.getBasePairsPerOligonucleotide(),
        minCommonPart     = o.getMinCommonPart();

    unsigned int initialMask = ((unsigned)(~0) >> (8*bytesPerInt - 2*basePairsPerOligo));

    for (int i = basePairsPerOligo - 1; i >= minCommonPart; --i) {
        int tempV = (vertex.getValue() >> 2*(10 - i)),
            tempC = candidate.getValue() & (initialMask >> 2*(10 - i));
        // sprawdź czy kandydat ma 10 - i wspólnych zasad z wyjątkiem pierwszej
        // z badanym oligonukleotydem
        if ((tempV ^ tempC) == 0 )
            return i;
    }

    return 0;
}
