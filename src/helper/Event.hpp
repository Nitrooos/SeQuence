#ifndef EVENT
#define EVENT

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
    int arches;
    
    public:
        StatisticsGeneratedEvent(int successors) : arches(successors) {}
        string getMessage() const { return "    Graph include " + to_string(arches) + " arches"; }
};

#endif
