#ifndef EVENT
#define EVENT

#include "../task/Statistic.hpp"
#include "../task/Result.hpp"
#include "../app/Instance.hpp"

#include <string>

using namespace std;

class Event {
    public:
        virtual string getMessage() const = 0;
};

class ResultEvent : public Event {
    Result result;
    Instance instance;
    long double computationTime;
    public:
        ResultEvent(Instance const& instance, Result const& result, long double computationTime)
            : instance(instance), result(result), computationTime(computationTime) { }
        string getMessage() const;
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

#endif
