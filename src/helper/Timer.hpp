#ifndef TIMER_H
#define TIMER_H

#include <chrono>

using namespace std::chrono;

class Timer {
    steady_clock::duration time{0};
    steady_clock::time_point startPoint, endPoint;
    
    public:
        Timer();
        
        void start();
        void stop();
        long double getTime() const;
};

#endif
