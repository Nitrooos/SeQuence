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

#endif
