#include "Helpers.hpp"
#include "Vertex.hpp"
#include "Options.hpp"

int CommonPart::get(Vertex const& vertex, Vertex const& candidate) {
    unsigned int initialMask = ((unsigned)(~0) >>
                                (8*Options::getBytesPerInt() - 2*Options::getBasePairsPerOligonucleotide()));

    for (int i = Options::getBasePairsPerOligonucleotide() - 1; i >= Options::getMinCommonPart(); --i) {
        int tempV = (vertex.getValue() >> 2*(10 - i)),
            tempC = candidate.getValue() & (initialMask >> 2*(10 - i));
        // sprawdź czy kandydat ma 10 - i wspólnych zasad z wyjątkiem pierwszej
        // z badanym oligonukleotydem
        if ((tempV ^ tempC) == 0 )
            return i;
    }

    return 0;
}
