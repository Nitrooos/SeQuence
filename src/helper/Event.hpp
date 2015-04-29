#ifndef EVENT
#define EVENT

#include "../task/Statistic.hpp"

#include <string>

using namespace std;

class Event {
    public:
        virtual string getMessage() const = 0;
};

class ResultEvent : public Event {
    public:
        ResultEvent() { }
        string getMessage() const { return "JAKIŚ REZULTAT"; }
};

class InstanceLoadedEvent : public Event {
    string name;

    public:
        InstanceLoadedEvent(string instanceName) : name(instanceName) {}
        string getMessage() const { return "Instance " + name + " loaded"; }
};

class StatisticsGeneratedEvent : public Event {
    Statistic statistic;
    
    public:
        StatisticsGeneratedEvent(Statistic const& stat) : statistic(stat) {}
        string getMessage() const;
};

class DFSResultEvent : public Event {
    string beginVertex;
    int visited;
    public:
        DFSResultEvent(string beginVertex, int visited);
        string getMessage() const;
};

#endif
