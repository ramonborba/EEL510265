#include "ClockCalendar.h"

ClockCalendar::ClockCalendar(int d, int mt, int y, int h, int m, int s, int pm) : Clock(h, m, s, pm), Calendar(d, mt, y) {
}

void ClockCalendar::advance() {
    bool wasPM = isPM;
    Clock::advance();
    if (wasPM && !isPM) {
        Calendar::advance();
    }
}
