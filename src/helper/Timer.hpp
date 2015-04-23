#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer {
	struct timespec start1, koniec1;
	clock_t start2, koniec2;
	double time;

	public:
		Timer();

		void start();
		void stop();
		double getTime();
};

#endif
