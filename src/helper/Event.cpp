#include "Event.hpp"
#include "Converter.hpp"

string StatisticsGeneratedEvent::getMessage() const {
    string result =
    "    Graph include " + to_string(statistic.vertexes) + " vertexes with\n" +
    "                  " + to_string(statistic.arches)   + " arches\n"   +
    "                  which means " + to_string(statistic.density) + " density\n" +
    "                  and " + to_string(statistic.avgSuccessors) + " average successors per vertex\n";
    
    Converter c;
    result +="    Best potential beginning vertexes:\n";
    for (auto &potentialBeginningVertex : statistic.potentialBeginningVertexes) {
        result += "        " + c.convert(potentialBeginningVertex->getValue()) + "\n";
    }
    
    result += "    Visited vertexes: " + to_string(statistic.visitedVertexes) + "\n";
    
    for (auto it = statistic.successorsByType.rbegin();
              it != statistic.successorsByType.rend();
              ++it) {
                  
        result += "    " + to_string(it->second) + " successors with common part of " +
                  to_string(it->first) +
                  " (avg " + to_string(it->second/(double)statistic.vertexes) + " per vertex)\n";
    }
    
    return result;
}
