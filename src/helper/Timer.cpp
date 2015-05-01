#include "Timer.hpp"

Timer::Timer() { }

void Timer::start() {
    startPoint = steady_clock::now();
}

void Timer::stop() {
    endPoint = steady_clock::now();
    time += endPoint - startPoint;
}

long double Timer::getTime() const {
    return (long double)(time.count()) * steady_clock::period::num / steady_clock::period::den;
}
