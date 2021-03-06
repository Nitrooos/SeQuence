#include "Event.hpp"
#include "Converter.hpp"
#include "../app/Options.hpp"

string StatisticsGeneratedEvent::getMessage() const {
    string result =
    "    Graph include " + to_string(statistic.vertexes) + " vertexes with\n" +
    "                  " + to_string(statistic.arches)   + " arches\n"   +
    "                  which means " + to_string(statistic.density) + " density\n" +
    "                  and " + to_string(statistic.avgSuccessors) + " average successors per vertex\n" +
    "    Isolated vertexes: " + to_string(statistic.isolatedVertexes) + "\n";
    
    Converter c;
    result += "    Started from vertex: " + c.convert(statistic.chosenBeginningVertex.first->getValue()) +
              " and visited " + to_string(statistic.chosenBeginningVertex.second) + " vertexes\n";
    
    for (auto it = statistic.successorsByType.rbegin();
              it != statistic.successorsByType.rend();
              ++it) {
                  
        result += "    " + to_string(it->second) + " successors with common part of " +
                  to_string(it->first) +
                  " (avg " + to_string(it->second/(double)statistic.vertexes) + " per vertex)\n";
    }
    
    return result;
}

string ResultEvent::getMessage() const {
    Converter c;
    string resultLog =
        instance.getName() + "\n" +
        c.convert(result.getUsedOligonucleotides().front().first->getValue()) + "\n" +
        to_string((double)result.getNumberOfUsedOligonucleotides()/instance.getIdealNumberOfUsedOligonucleotides()*100) + "%\n" +
        to_string(result.getNumberOfUsedOligonucleotides()) + "\n" +
        to_string(instance.getIdealNumberOfUsedOligonucleotides()) + "\n" +
        to_string(result.getSequenceLength()) + "\n" +
        to_string(instance.getOriginalSequenceLength()) + "\n" +
        to_string(computationTime) + "\n" +
        result.getSequence() + "\n";
    
    int n = -Options::getInstance().getBasePairsPerOligonucleotide();
    for (auto &oligo : result.getUsedOligonucleotides()) {
        n += Options::getInstance().getBasePairsPerOligonucleotide() - oligo.second;
        resultLog += string(n, ' ') + c.convert(oligo.first->getValue()) + "\n";
    }
    
    return resultLog;
}
