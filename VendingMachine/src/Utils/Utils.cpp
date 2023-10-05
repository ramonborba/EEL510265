#include "Utils.hpp"


void delay(clock_t time) {
	clock_t start_time = clock();
	clock_t end_time = time + start_time;
	while (clock() != end_time);
}
