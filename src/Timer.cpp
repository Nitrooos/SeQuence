#include "Timer.hpp"

Timer::Timer() : time(0.0) { }

void Timer::start() {
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start1);
	start2 = clock();
}

void Timer::stop() {
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &koniec1);
	koniec2 = clock();
}

double Timer::getTime() {
	time = ((double)(koniec2 - start2))/CLOCKS_PER_SEC;
	// włączamy większą dokładność
	if (time <= 0.05) {
		time = (koniec1.tv_nsec - start1.tv_nsec)/1000000000.0;
		if (time < 0)
			++time;
	}
	return time;
}
