#include "Timer.hpp"

Timer::Timer() : time(0.0) { }

void Timer::start() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start1);
    start2 = clock();
}

void Timer::stop() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &koniec1);
    koniec2 = clock();
    
    countInterval();
}

void Timer::countInterval() {
    double interval = ((double)(koniec2 - start2))/CLOCKS_PER_SEC;
    // włączamy większą dokładność
    if (interval <= 0.05) {
        interval = (koniec1.tv_nsec - start1.tv_nsec)/1000000000.0;
        if (interval < 0)
            ++interval;
    }
    time += interval;
}

double Timer::getTime() {
    return time;
}
