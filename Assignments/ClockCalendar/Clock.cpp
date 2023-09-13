#include "Clock.h"

Clock::Clock(int h, int m, int s, bool pm) : hr(h), min(m), sec(s), isPM(pm) {
}

Clock::~Clock() {
}

void Clock::setClock(int h, int m, int s, bool pm) {
    hr = h;
    min = m;
    sec = s;
    isPM = pm;
}

void Clock::readClock(int& h, int& m, int& s, bool& pm) {
    h = hr; 
    m = min; 
    s = sec; 
    pm = isPM; 
}

void Clock::advance() {
    sec++;
    if (sec > 59) {
        sec = 0;
        min++;
        if (min > 59) {
            min = 0;
            hr++;
            if (hr == 12) {
                if (isPM) {
                    hr = 0;
                    isPM = false;
                }
                else {
                    isPM = true;
                }
            }
            else if (hr > 12) {
                hr = 1;
            }
        }
    }
}
